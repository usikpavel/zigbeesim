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

		radio = SingleChannelRadioAccess().get();
		commentsLevel = ALL;
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
	//assert(dynamic_cast<PdMsg*>(msg));
	PdMsg *pdMsg = static_cast<PdMsg *> (msg);
	sendRfDown(encapsulatePd(pdMsg));
}

void Pd::handleRfMsg(cMessage *msg) {

}

void Pd::handlePlmeMsg(cMessage *msg) {

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

AirFrame802154* Pd::encapsulatePd(PdMsg *msg) {
	AirFrame802154 *airframe = new AirFrame802154("AirFrame",
			msg->getKind());
	unsigned char currentChannel = getPhyPib()->getPhyCurrentChannel();
	unsigned char currentPage = getPhyPib()->getPhyCurrentPage();
	int preambleLength;
	int sfdLength;
	std::cout << "Page: " << (int) currentPage << " Channel: " << (int) currentChannel << endl;
	switch (currentPage) {
	case 0x00:
		preambleLength = 32;
		sfdLength = 8;
		break;
	case 0x01:
		if (currentChannel == 0x00) {
			preambleLength = 40;
			sfdLength = 20;
		} else if (currentChannel <= 0x0A) {
			preambleLength = 30;
			sfdLength = 5;
		}
		break;
	case 0x02:
		preambleLength = 32;
		sfdLength = 8;
		break;
	}
	airframe->encapsulate(msg);
	std::cout << "Preamble: " << preambleLength << " SFD: " << sfdLength << endl;
	std::cout << "Length: " << (preambleLength + sfdLength) << endl;
	airframe->setBitLength(preambleLength + sfdLength);
	airframe->setDuration(0.1);
	return airframe;
}

PdMsg* Pd::decapsulateAirFrame(AirFrame802154 *msg) {
	return check_and_cast<PdMsg *> (msg->decapsulate());
}
