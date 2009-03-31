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
		lastUpperMsg = new cMessage();
		lastBeacon = new PdMsg();
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
	delete (msg);
}

void Mcps::handlePdMsg(cMessage *msg) {
	if (msg->getKind() == PD_DATA_CONFIRM) {
		PdData_confirm* confirm = check_and_cast<PdData_confirm *> (msg);
		if (confirm->getStatus() == PHY_SUCCESS) {
			if (getLastUpperMsg()->getKind() == MAC_COMMAND_FRAME) {
				MacCommand* command = new MacCommand("Beacon request sent",
						MAC_COMMAND_FRAME);
				command->setCommandType(BEACON_REQUEST);
				sendMlme(command);
			} else if (getLastUpperMsg()->getKind() == MAC_BEACON_FRAME) {
				MacBeacon* beacon = new MacBeacon("Beacon sent",
						MAC_BEACON_FRAME);
				sendMlme(beacon);
			}
		}
		delete (msg);
	} else if (msg->getKind() == PD_DATA_INDICATION) {
		PdMsg* pdMsg = check_and_cast<PdMsg *>(msg);
		if (pdMsg->getFrameType() == BEACON) {
			setLastBeacon(pdMsg->dup());
			McpsMsg* mcpsMsg = decapsulatePd(pdMsg);
			MacBeacon* beacon = check_and_cast<MacBeacon *>(mcpsMsg);
			beacon->setKind(MAC_BEACON_FRAME);
			sendMlme(beacon);
		}
	}
}

void Mcps::handleMcpsMsg(cMessage *msg) {
	setLastUpperMsg(msg->dup());
	delete(msg);
}

void Mcps::handleMlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg->dup());
	/** @todo maybe here we can just encapsulate the message without distinguishing what kind of msg it is*/
	/** future will tell */
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		if (command->getCommandType() == BEACON_REQUEST) {
			sendPdDown(encapsulateMcps(command));
		}
	} else if (msg->getKind() == MAC_BEACON_FRAME) {
		MacBeacon* beacon = check_and_cast<MacBeacon *> (msg);
		sendPdDown(encapsulateMcps(beacon));
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

PdMsg* Mcps::encapsulateMcps(McpsMsg *msg) {
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		if (command->getCommandType() == BEACON_REQUEST) {
			PdData_request *request = new PdData_request("Beacon request",
					PD_DATA_REQUEST);
			request->setByteLength(11);
			/** @comment this should not be the same as ByteLength */
			request->setPsduLength(msg->getByteLength());
			request->setFrameType(COMMAND);
			request->setSecurityEnabled(false);
			request->setFramePending(false);
			request->setAckRequest(false);
			request->setPanIdCompression(true);
			request->setDestinationAddressingMode(SHORT_ADDRESS);
			request->setFrameVersion(0x01);
			request->setSourceAddressingMode(SHORT_ADDRESS);
			request->setSequenceNumber(getMacPib()->getMacDSN());
			getMacPib()->setMacDSN(getMacPib()->getMacDSN() + 1);
			request->setDestinationPanIdentifier(0xFFFF);
			request->setDestinationAddress((unsigned long) 0xFFFF);
			request->setSourceAddress(
					(unsigned long) (getMacPib()->getMacShortAddress()));
			request->setAuxiliarySecurityHeaderArraySize(0);
			/** @todo who wants to calculate the fcs? :) */
			request->setFcs((unsigned short) (rand() % 65536));
			request->encapsulate(command);
			return request;
		}
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
		request->setPanIdCompression(true);
		request->setDestinationAddressingMode(SHORT_ADDRESS);
		request->setFrameVersion(0x01);
		request->setSourceAddressingMode(SHORT_ADDRESS);
		request->setSequenceNumber(getMacPib()->getMacBSN());
		getMacPib()->setMacBSN(getMacPib()->getMacBSN() + 1);
		request->setDestinationPanIdentifier(0xFFFF);
		request->setDestinationAddress((unsigned long) 0xFFFF);
		request->setSourceAddress(
				(unsigned long) (getMacPib()->getMacShortAddress()));
		request->setAuxiliarySecurityHeaderArraySize(0);
		/** @todo who wants to calculate the fcs? :) */
		request->setFcs((unsigned short) (rand() % 65536));
		request->encapsulate(beacon);
		return request;
	}
	return NULL;
}

McpsMsg* Mcps::decapsulatePd(PdMsg *msg) {
	McpsMsg* mcpsMsg = static_cast<McpsMsg *> (msg->decapsulate());
	delete (msg);
	return mcpsMsg;
}
