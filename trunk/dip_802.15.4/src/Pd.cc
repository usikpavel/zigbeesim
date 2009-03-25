#include "Pd.h"

Define_Module(Pd)
;

void Pd::initialize(int stage) {
	BasicModule::initialize(stage);
	if (stage == 0) {
		pdSapOut = findGate("pdSapOut");
		pdSapIn = findGate("pdSapIn");
		rfSapOut = findGate("rfSapOut");
		rfSapIn = findGate("rfSapIn");
		plmeOut = findGate("plmeOut");
		plmeIn = findGate("plmeIn");
		rfControlIn = findGate("rfControlIn");

		commentsLevel = ALL;

		/** @todo put the queue length param into omnetpp.ini */
		queueLength = 10;
		radioState = RadioState::RECV;
		RadioState cs;
		catRadioState = bb->subscribe(this, &cs,
				getParentModule()->getParentModule()->getId());
		radio = SingleChannelRadioAccess().get();
		phyState = RX;
	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
	}
}

void Pd::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == pdSapIn) {
		handlePdMsg(msg);
	} else if (msg->getArrivalGateId() == rfSapIn) {
		handleRfMsg(msg);
	} else if (msg->getArrivalGateId() == plmeIn) {
		handlePlmeMsg(msg);
	} else if (msg->getArrivalGateId() == rfControlIn) {
		handleRfControl(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void Pd::handleSelfMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	delete (msg);
}

void Pd::handlePdMsg(cMessage *msg) {
	setLastUpperMsg(msg);
	assert(static_cast<cPacket*> (msg));
	Frame802154 *frame = encapsulatePd(static_cast<PdMsg *> (msg));
	if (frameQueue.size() <= queueLength) {
		frameQueue.push_back(frame);
		if ((frameQueue.size() == 1) && (phyState == RX)) {
			prepareSend();
		}
	}
}

void Pd::handleRfMsg(cMessage *msg) {

}

void Pd::handlePlmeMsg(cMessage *msg) {

}

void Pd::handleRfControl(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msgName == "TRANSMISSION_OVER") {
		if (radio->switchToRecv()) {
			phyState = RX;
		}
	}
	delete(msg);
}

void Pd::sendPdUp(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, pdSapOut);
}

void Pd::sendRfDown(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, rfSapOut);
}

void Pd::sendPlme(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, plmeOut);
}

Frame802154* Pd::encapsulatePd(PdMsg *msg) {
	Frame802154 *frame = new Frame802154("AirFrame", msg->getKind());
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	int preambleLength;
	int sfdLength;
	switch (currentPage) {
	case 0x00:
		preambleLength = 32;
		sfdLength = 8;
		if (currentChannel == 0x00) {
			radio->setBitrate(20480);
		} else if (currentChannel <= 0x0A) {
			radio->setBitrate(40960);
		} else {
			radio->setBitrate(256000);
		}
		break;
	case 0x01:
		if (currentChannel == 0x00) {
			preambleLength = 40;
			sfdLength = 20;
		} else if (currentChannel <= 0x0A) {
			preambleLength = 30;
			sfdLength = 5;
		}
		radio->setBitrate(256000);
		break;
	case 0x02:
		preambleLength = 32;
		sfdLength = 8;
		if (currentChannel == 0x00) {
			radio->setBitrate(102400);
		} else if (currentChannel <= 0x0A) {
			radio->setBitrate(256000);
		}
		break;
	}
	frame->setBitLength(preambleLength + sfdLength);
	frame->encapsulate(msg);
	return frame;
}

PdMsg* Pd::decapsulateFrame(Frame802154 *msg) {
	return check_and_cast<PdMsg *> (msg->decapsulate());
}

/**********************************************************************/
cMessage* Pd::decapsMsg(Frame802154* msg) {
	cPacket *m = msg->decapsulate();
	//m->setControlInfo(new MacControlInfo(msg->getSrcAddr()));
	delete msg;
	return m;
}
Frame802154* Pd::encapsMsg(cPacket *msg) {
	Frame802154 *frame = new Frame802154(msg->getName(), msg->getKind());
	frame->setBitLength(40);
	// copy dest address from the Control Info attached to the network
	// mesage by the network layer
	MacControlInfo* cInfo =
			static_cast<MacControlInfo*> (msg->removeControlInfo());
	//frame->setDestAddr(cInfo->getNextHopMac());
	//delete the control info
	delete cInfo;
	//frame->setSrcAddr(myMacAddr);
	//encapsulate the network packet
	frame->encapsulate(msg);
	return frame;
}

void Pd::prepareSend() {
	if (frameQueue.size() != 0) {
		if (radio->switchToSend()) {
			phyState = TX;
		}
	}
}

void Pd::receiveBBItem(int category, const BBItem *details, int scopeModuleId) {
	Enter_Method_Silent();
	if (category == catRadioState) {
		radioState = static_cast<const RadioState *> (details)->getState();
		if ((phyState == TX) && (radioState == RadioState::SEND)) {
			sendRfDown(frameQueue.front());
			frameQueue.pop_front();
			PdData_confirm *confirm = new PdData_confirm("PD-DATA.confirm",
					PD_DATA_CONFIRM);
			confirm->setStatus(PHY_SUCCESS);
			sendPdUp(confirm);
		} else if ((phyState == RX) && (radioState == RadioState::RECV)) {
			prepareSend();
		}
	}
}
