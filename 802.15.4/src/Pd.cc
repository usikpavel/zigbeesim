#include "Pd.h"

Define_Module( Pd);

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

		commentsLevel = COMMENT_ALL;

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
		frameTimer = new cMessage();
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
	if (msg->getKind() == TIMER_SFD_FRAME) {
		setLastMsgTimestamp(simTime());
	}
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
	Frame802154* frame = check_and_cast<Frame802154 *> (msg);
	sendPdUp(decapsulateFrame(frame));
}

void Pd::handlePlmeMsg(cMessage *msg) {

}

void Pd::handleRfControl(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msgName == "TRANSMISSION_OVER") {
		if (radio->switchToRecv()) {
			phyState = RX;
		}
		PdData_confirm *confirm = new PdData_confirm("PD-DATA.confirm",
				PD_DATA_CONFIRM);
		confirm->setStatus(PHY_SUCCESS);
		sendPdUp(confirm);
	} else if (msgName == "RECEIVING_START") {
		frameTimer->setKind(TIMER_SFD_FRAME);
		frameTimer->setName("SFD processed, setting timestamp");
		scheduleAt(simTime() + calculatePreambleLengthInSeconds()
				+ calculateSfdLengthInSeconds(), frameTimer);
	}
	delete (msg);
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
	Frame802154 *frame = new Frame802154(msg->getName(), msg->getKind());
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
	PdMsg* pdMsg = check_and_cast<PdMsg *> (msg->decapsulate());
	delete (msg);
	pdMsg->setName("PD-DATA.indication");
	pdMsg->setKind(PD_DATA_INDICATION);
	return pdMsg;
}

void Pd::prepareSend() {
	if (frameQueue.size() != 0) {
		if (radio->switchToSend()) {
			phyState = TX;
		}
	}
}

unsigned char Pd::calculatePreambleLengthInSymbols() {
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	switch (currentPage) {
	case 0x00:
		if (currentChannel <= 0x0A)
			return 32;
		else
			return 8;
	case 0x01:
		if (currentChannel == 0x00)
			return 2;
		else
			return 6;
	case 0x02:
		return 8;
	default:
		commentError("Unsupported page number");
	}
	return 0;
}

double Pd::calculatePreambleLengthInSeconds() {
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	switch (currentPage) {
	case 0x00:
		if (currentChannel == 0x00)
			return 0.0016;
		else if (currentChannel <= 0x0A)
			return 0.0008;
		else
			return 0.000128;
	case 0x01:
		if (currentChannel == 0x00)
			return 0.00016;
		else
			return 0.00012;
	case 0x02:
		if (currentChannel == 0x00)
			return 0.00032;
		else
			return 0.000128;
	default:
		commentError("Unsupported page number");
	}
	return 0;
}

unsigned char Pd::calculateSfdLengthInSymbols() {
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	switch (currentPage) {
	case 0x00:
		if (currentChannel <= 0x0A)
			return 8;
		else
			return 2;
	case 0x01:
		return 1;
	case 0x02:
		return 2;
	default:
		commentError("Unsupported page number");
	}
	return 0;
}

double Pd::calculateSfdLengthInSeconds() {
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	switch (currentPage) {
	case 0x00:
		if (currentChannel == 0x00)
			return 0.0004;
		else if (currentChannel <= 0x0A)
			return 0.0002;
		else
			return 0.000032;
	case 0x01:
		if (currentChannel == 0x00)
			return 0.00008;
		else
			return 0.00002;
	case 0x02:
		if (currentChannel == 0x00)
			return 0.00008;
		else
			return 0.000032;
	default:
		commentError("Unsupported page number");
	}
	return 0;
}

double Pd::symbolsToSeconds(unsigned int symbols) {
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	int symbolrate;
	switch (currentPage) {
	case 0x00:
		if (currentChannel == 0x00) symbolrate = 20000;
		else if (currentChannel <= 0x0A) symbolrate = 40000;
		else symbolrate = 62500;
		break;
	case 0x01:
		if (currentChannel == 0x00) symbolrate = 12500;
		else symbolrate = 50000;
		break;
	case 0x02:
		if (currentChannel == 0x00) symbolrate = 25000;
		else symbolrate = 62500;
		break;
	default:
		commentError("Unsupported page number");
	}
	return ((double) symbols)/((double) symbolrate);
}

void Pd::receiveBBItem(int category, const BBItem *details, int scopeModuleId) {
	Enter_Method_Silent();
	if (category == catRadioState) {
		radioState = static_cast<const RadioState *> (details)->getState();
		if ((phyState == TX) && (radioState == RadioState::SEND)) {
			sendRfDown(frameQueue.front());
			frameQueue.pop_front();
		} else if ((phyState == RX) && (radioState == RadioState::RECV)) {
			prepareSend();
		}
	}
}
