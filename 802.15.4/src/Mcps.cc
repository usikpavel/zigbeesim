/* -*- mode:c++ -*- ********************************************************
 * file:        Mcps.cc
 *
 * author:      Bernard Halas
 *
 * copyright:   (C) 2009 Czech Technical University, Faculty of
 *              Electrical Engineering
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 ***************************************************************************
 * part of:     ZigBee Simulation model
 * description: - Module describing the behavior of the mac data entity
 ***************************************************************************/
#include "Mcps.h"

Define_Module( Mcps);

void Mcps::initialize(int stage) {
	BasicModule::initialize(stage);

	if (stage == 0) {
		mcpsSapIn = findGate("mcpsSapIn");
		mcpsSapOut = findGate("mcpsSapOut");
		pdSapIn = findGate("pdSapIn");
		pdSapOut = findGate("pdSapOut");
		mlmeIn = findGate("mlmeIn");
		mlmeOut = findGate("mlmeOut");

		commentsLevel = COMMENT_ALL;
	} else if (stage == 1) {
		ackTimer = new cMessage("ACK.timer", TIMER_ACK);
		lastUpperMsg = new cMessage();
		lastLowerMsg = new PdMsg();
		nextEncapsulation = &encapsulation;
		setFrameQueueLength(0);
		setPriorityFrameQueueLength(0);
	}
}

void Mcps::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == pdSapIn) {
		handlePdMsg(msg);
	} else if (msg->getArrivalGateId() == mcpsSapIn) {
		handleMcpsMsg(msg);
	} else if (msg->getArrivalGateId() == mlmeIn) {
		handleMlmeMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void Mcps::handleSelfMsg(cMessage *msg) {
	if (msg->getKind() == TIMER_ACK) {
		MacAck* macAck = new MacAck("Acknowledgment", MAC_ACK_FRAME);
		macAck->setByteLength(0);
		sendPdDown(encapsulateMcps(macAck));
		/** @comment this has to me made for a decision on what to do with the PD-DATA.confirm message */
		setLastUpperMsg(msg->dup());
	}
}

void Mcps::handlePdMsg(cMessage *msg) {
	if (msg->getKind() == PD_DATA_CONFIRM) {
		PdData_confirm* confirm = check_and_cast<PdData_confirm *> (msg);
		if (confirm->getStatus() == PHY_SUCCESS) {
			if (getLastUpperMsg()->getKind() == MAC_COMMAND_FRAME) {
				MacCommand* command = new MacCommand("Command sent",
						MAC_COMMAND_FRAME);
				command->setCommandType(check_and_cast<MacCommand*> (
						getLastUpperMsg())->getCommandType());
				sendMlme(command);
			} else if (getLastUpperMsg()->getKind() == MAC_BEACON_FRAME) {
				MacBeacon* beacon = new MacBeacon("Beacon sent",
						MAC_BEACON_FRAME);
				sendMlme(beacon);
			} else if (getLastUpperMsg()->getKind() == TIMER_ACK) {
				/** @comment no additional action needed */
			}
		}
		delete (msg);
	} else if (msg->getKind() == PD_DATA_INDICATION) {
		PdMsg* pdMsg = check_and_cast<PdMsg *> (msg);
		/** @comment is the message really mentioned for us? */
		if (((pdMsg->getDestinationAddressingMode() == LONG_ADDRESS
				&& pdMsg->getDestinationAddress()
						!= getMacPib()->getExtendedAddress())
				|| (pdMsg->getDestinationAddressingMode() == SHORT_ADDRESS
						&& pdMsg->getDestinationAddress()
								!= getMacPib()->getMacShortAddress()
						&& pdMsg->getDestinationAddress() != 0xFFFF))
				&& pdMsg->getDestinationPanIdentifier() != 0xFFFF) {
			comment(COMMENT_FRAME, "Frame not for us, discarding");
			delete (pdMsg);
			return;
		}
		setLastLowerMsg(pdMsg->dup());
		double ackTime = 0.0;
		/** @note be careful
		 * maybe the code needs to be duplicated for the selfMsg part as well */
		if (pdMsg->getAckRequest()) {
			ackTime = rand()%(getMacPib()->getUnitBackoffPeriod());
			ackTime = getPd()->symbolsToSeconds((unsigned int) ackTime +
					getPhyPib()->getTurnAroundTime());
			scheduleAt(simTime() + ackTime, ackTimer);
		}
		if (ackTime > 0.0) {
			/** @comment we're sending the ack frame */
			/** 11 Bytes - size of the ACK frame */
			ackTime += 11*8 / getPd()->getBitrate();
		}
		/** @comment according to received frame size adjust the ifs period*/
		double ifsPeriod = getPd()->symbolsToSeconds(getMacPib()->getMacMinSIFSPeriod());
		if ((check_and_cast<cPacket *>(msg))->getByteLength() > getMacPib()->getMaxSIFSFrameSize())
			ifsPeriod = getPd()->symbolsToSeconds(getMacPib()->getMacMinLIFSPeriod());
		if (pdMsg->getFrameType() == BEACON) {
			MacBeacon* beacon = check_and_cast<MacBeacon *> (decapsulatePd(
					pdMsg));
			beacon->setKind(MAC_BEACON_FRAME);
			sendMlme(beacon, ackTime + ifsPeriod);
		} else if (pdMsg->getFrameType() == COMMAND) {
			MacCommand* macCommand = check_and_cast<MacCommand *> (
					decapsulatePd(pdMsg));
			macCommand->setKind(MAC_COMMAND_FRAME);
			sendMlme(macCommand, ackTime + ifsPeriod);
		} else if (pdMsg->getFrameType() == ACK) {
			if (getPriorityFrameQueueLength() > 0) {
				if (pdMsg->getSequenceNumber() == priorityFrameQueue.front()->getSequenceNumber()) {
					priorityFrameQueue.pop_front();
					setPriorityFrameQueueLength(getPriorityFrameQueueLength() - 1);
				}
			} else if (getFrameQueueLength() > 0) {
				if (pdMsg->getSequenceNumber() == frameQueue.front()->getSequenceNumber()) {
					frameQueue.pop_front();
					setFrameQueueLength(getFrameQueueLength() - 1);
				}
			} else {
				commentError("Unexpected ACK received, queues are empty");
			}
			sendMlme(decapsulatePd(pdMsg), ackTime + ifsPeriod);
		}
	}
}

void Mcps::handleMcpsMsg(cMessage *msg) {
	setLastUpperMsg(msg->dup());
	/** @TODO most probably put this message into the frame queue */
	delete (msg);
}

void Mcps::handleMlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg->dup());
	/** @todo maybe here we can just encapsulate the message without distinguishing what kind of msg it is*/
	/** future will tell */
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		if (command->getCommandType() == BEACON_REQUEST) {
			sendPdDown(encapsulateMcps(command));
		} else if (command->getCommandType() == ASSOCIATE_REQUEST) {
			sendPdDown(encapsulateMcps(command));
		} else if (command->getCommandType() == DATA_REQUEST) {
			setPriorityFrameQueueLength(getPriorityFrameQueueLength() + 1);
			priorityFrameQueue.push_back(encapsulateMcps(command));
		} else if (command->getCommandType() == ASSOCIATE_RESPONSE) {
			sendPdDown(encapsulateMcps(command));
		}
	} else if (msg->getKind() == MAC_BEACON_FRAME) {
		MacBeacon* beacon = check_and_cast<MacBeacon *> (msg);
		sendPdDown(encapsulateMcps(beacon));
	}
}

void Mcps::sendCapFrame() {
	PdMsg *pdMsg;
	if (getPriorityFrameQueueLength() > 0) {
		pdMsg = priorityFrameQueue.front();
		priorityFrameQueue.pop_front();
		priorityFrameQueue.push_front(pdMsg->dup());
		sendPdDown(pdMsg);
	} else if (getFrameQueueLength() > 0) {
		pdMsg = frameQueue.front();
		frameQueue.pop_front();
		frameQueue.push_front(pdMsg->dup());
		sendPdDown(pdMsg);
	}
}

void Mcps::sendPdDown(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, pdSapOut);
}

void Mcps::sendMcpsUp(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, mcpsSapOut);
}

void Mcps::sendMlme(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, mlmeOut);
}

void Mcps::sendMcpsUp(cMessage *msg, double delay) {
	commentMsgSending(msg);
	sendDelayed(msg, delay, mcpsSapOut);
}

void Mcps::sendMlme(cMessage *msg, double delay) {
	commentMsgSending(msg);
	sendDelayed(msg, delay, mlmeOut);
}

PdMsg* Mcps::encapsulateMcps(McpsMsg *msg) {
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		PdData_request *request = new PdData_request();
		request->setKind(PD_DATA_REQUEST);
		/** @comment this should not be the same as ByteLength */
		request->setPsduLength(msg->getByteLength());
		request->setSecurityEnabled(false);
		request->setFrameType(COMMAND);
		if (command->getCommandType() == BEACON_REQUEST) {
			request->setName("Beacon Request");
			request->setByteLength(11);
			request->setFramePending(false);
			request->setAckRequest(false);
			request->setPanIdCompression(true);
			request->setDestinationAddressingMode(SHORT_ADDRESS);
			request->setFrameVersion(0x01);
			request->setSourceAddressingMode(SHORT_ADDRESS);
			request->setDestinationPanIdentifier(0xFFFF);
			request->setDestinationAddress((unsigned long) 0xFFFF);
			request->setSourceAddress(
					(unsigned long) (getMacPib()->getMacShortAddress()));
		} else if (command->getCommandType() == ASSOCIATE_REQUEST) {
			request->setName("Association Request");
			if (getNextEncapsulation()->destinationAddressingMode
					== LONG_ADDRESS)
				request->setByteLength(25);
			else
				request->setByteLength(19);
			request->setFramePending(false);
			request->setAckRequest(true);
			request->setPanIdCompression(false);
			request->setDestinationAddressingMode(
					getNextEncapsulation()->destinationAddressingMode);
			request->setFrameVersion(0x01);
			request->setSourceAddressingMode(LONG_ADDRESS);
			request->setDestinationPanIdentifier(
					getNextEncapsulation()->destinationPanIdentifier);
			request->setDestinationAddress(
					getNextEncapsulation()->destinationAddress);
			request->setSourcePanIdentifier(0xFFFF);
			request->setSourceAddress(
					(unsigned long) (getMacPib()->getExtendedAddress()));
		} else if (command->getCommandType() == DATA_REQUEST) {
			request->setName("Data Request");
			request->setByteLength(6);
			if (getNextEncapsulation()->sourceAddressingMode == LONG_ADDRESS)
				request->setByteLength(request->getByteLength() + 8);
			else
				request->setByteLength(request->getByteLength() + 2);
			if (getNextEncapsulation()->destinationAddressingMode
					== LONG_ADDRESS)
				request->setByteLength(request->getByteLength() + 8);
			else
				request->setByteLength(request->getByteLength() + 2);
			request->setSourceAddressingMode(
					getNextEncapsulation()->sourceAddressingMode);
			request->setSourceAddress(getNextEncapsulation()->sourceAddress);
			request->setDestinationAddressingMode(
					getNextEncapsulation()->destinationAddressingMode);
			if (getNextEncapsulation()->destinationAddressingMode
					!= NOT_PRESENT)
				request->setDestinationAddress(
						getNextEncapsulation()->destinationAddress);
			request->setDestinationPanIdentifier(
					getNextEncapsulation()->destinationPanIdentifier);
			request->setAckRequest(true);
			request->setFramePending(false);
			request->setPanIdCompression(true);
		} else if (command->getCommandType() == ASSOCIATE_RESPONSE) {
			request->setName("Associate Response");
			request->setByteLength(22);
			request->setSourceAddressingMode(LONG_ADDRESS);
			request->setSourceAddress(getMacPib()->getExtendedAddress());
			request->setDestinationAddressingMode(LONG_ADDRESS);
			request->setDestinationAddress(getNextEncapsulation()->destinationAddress);
			request->setDestinationPanIdentifier(getNextEncapsulation()->destinationPanIdentifier);
			request->setAckRequest(true);
			request->setFramePending(false);
			request->setPanIdCompression(true);
		}
		request->setSequenceNumber(getMacPib()->getMacDSN());
		getMacPib()->setMacDSN(getMacPib()->getMacDSN() + 1);
		request->setAuxiliarySecurityHeaderArraySize(0);
		/** @todo who wants to calculate the fcs? :) */
		request->setFcs((unsigned short) (rand() % 65536));
		request->encapsulate(command);
		return request;
	} else if (msg->getKind() == MAC_BEACON_FRAME) {
		MacBeacon* beacon = check_and_cast<MacBeacon *> (msg);
		PdData_request *request = new PdData_request("Beacon", PD_DATA_REQUEST);
		request->setByteLength(11);
		/** @comment this should not be the same as ByteLength */
		request->setPsduLength(msg->getByteLength());
		request->setFrameType(BEACON);
		request->setSecurityEnabled(false);
		request->setFramePending(false);
		request->setAckRequest(false);
		request->setPanIdCompression(false);
		request->setDestinationAddressingMode(NOT_PRESENT);
		request->setFrameVersion(0x00);
		request->setSourceAddressingMode(LONG_ADDRESS);
		request->setSequenceNumber(getMacPib()->getMacBSN());
		getMacPib()->setMacBSN((getMacPib()->getMacBSN()) + 1);
		request->setDestinationPanIdentifier(0xFFFF);
		request->setSourcePanIdentifier(
				getMacPib()->getPibAttribute(MAC_PAN_ID)[0]);
		request->setSourceAddress(
				(unsigned long) (getMacPib()->getExtendedAddress()));
		request->setAuxiliarySecurityHeaderArraySize(0);
		/** @TODO who wants to calculate the fcs? :) */
		request->setFcs((unsigned short) (rand() % 65536));
		request->encapsulate(beacon);
		return request;
	} else if (msg->getKind() == MAC_ACK_FRAME) {
		MacAck* macAck = check_and_cast<MacAck *> (msg);
		PdData_request *request = new PdData_request("Acknowledgement",
				PD_DATA_REQUEST);
		/** @note the 0x00 fields are ignored on the reception */
		request->setByteLength(5);
		request->setFrameType(ACK);
		request->setSecurityEnabled(0x00);
		request->setFramePending(false);
		request->setAckRequest(0x00);
		request->setPanIdCompression(0x00);
		request->setDestinationAddressingMode(0x00);
		request->setFrameVersion(0x00);
		request->setSourceAddressingMode(0x00);
		request->setSequenceNumber(getLastLowerMsg()->getSequenceNumber());
		/** @TODO who wants to calculate the fcs? :) */
		request->setFcs((unsigned short) (rand() % 65536));
		request->encapsulate(macAck);
		return request;
	}
	return NULL;
}

McpsMsg* Mcps::decapsulatePd(PdMsg *msg) {
	McpsMsg* mcpsMsg = static_cast<McpsMsg *> (msg->decapsulate());
	delete (msg);
	return mcpsMsg;
}

Mcps::~Mcps() {

}
