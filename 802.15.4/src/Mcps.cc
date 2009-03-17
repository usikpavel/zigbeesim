#include "Mcps.h"

Define_Module(Mcps)
;

void Mcps::initialize(int stage) {
	BasicModule::initialize(stage);

	if (stage == 0) {
		mcpsSapIn = findGate("mcpsSapIn");
		mcpsSapOut = findGate("mcpsSapOut");
		pdSapIn = findGate("pdSapIn");
		pdSapOut = findGate("pdSapOut");
		mlmeIn = findGate("mlmeIn");
		mlmeOut = findGate("mlmeOut");

		commentsLevel = ALL;
	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
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
	std::string msgName = msg->getName();
	delete (msg);
}

void Mcps::handlePdMsg(cMessage *msg) {
	delete (msg);
}

void Mcps::handleMcpsMsg(cMessage *msg) {
	setLastUpperMsg(msg);
}

void Mcps::handleMlmeMsg(cMessage *msg) {
	/** @todo maybe here we can just encapsulate the message without distinguishing what kind of msg it is*/
	/** future will tell */
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		if (command->getCommandType() == BEACON_REQUEST) {
			sendPdDown(encapsulateMcps(command));
		}
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
			PdData_request *request = new PdData_request("PD-DATA.request",
					PD_DATA_REQUEST);
			request->setByteLength(1);
			/** @comment this should be the same as ByteLength always */
			request->setPsduLength(1);
			request->setFrameType(COMMAND);
			request->setSecurityEnabled(false);
			request->setFramePending(false);
			request->setAckRequest(false);
			request->setPanIdCompression(true);
			request->setDestinationAddressingMode(SHORT);
			request->setFrameVersion(0x01);
			request->setSourceAddressingMode(SHORT);
			request->setSequenceNumber(getMacPib()->getMacDSN());
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
	}
	return NULL;
}

McpsMsg* Mcps::decapsulatePd(PdMsg *msg) {
	return NULL;
}
/*
 MacPkt* BasicMacLayer::encapsMsg(cPacket *msg)
 {
 MacPkt *pkt = new MacPkt(msg->getName(), msg->getKind());
 pkt->setBitLength(headerLength);

 // copy dest address from the Control Info attached to the network
 // mesage by the network layer
 MacControlInfo* cInfo = static_cast<MacControlInfo*>(msg->removeControlInfo());

 coreEV <<"CInfo removed, mac addr="<< cInfo->getNextHopMac()<<endl;
 pkt->setDestAddr(cInfo->getNextHopMac());

 //delete the control info
 delete cInfo;

 //set the src address to own mac address (nic module getId())
 pkt->setSrcAddr(myMacAddr);

 //encapsulate the network packet
 pkt->encapsulate(msg);
 coreEV <<"pkt encapsulated\n";

 return pkt;
 }
 */
