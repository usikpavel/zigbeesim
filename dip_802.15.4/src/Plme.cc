#include "Plme.h"

Define_Module(Plme)
;

void Plme::initialize(int stage) {
	BasicModule::initialize(stage);

	if (stage == 0) {
		plmeSapOut = findGate("plmeSapOut");
		plmeSapIn = findGate("plmeSapIn");
		pdOut = findGate("pdOut");
		pdIn = findGate("pdIn");
		phyPibOut = findGate("phyPibOut");
		phyPibIn = findGate("phyPibIn");

		setLayerState(PHY_TRX_OFF);
		commentsLevel = ALL;
	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
		timer = new cMessage();
	}
}

void Plme::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == plmeSapIn) {
		handlePlmeMsg(msg);
	} else if (msg->getArrivalGateId() == pdIn) {
		handlePdMsg(msg);
	} else if (msg->getArrivalGateId() == phyPibIn) {
		handlePhyPibMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void Plme::handleSelfMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msgName == "ED.timer") {
		/** @todo here, we should do the energy measurement */
		PlmeEd_confirm* confirm = new PlmeEd_confirm();
		confirm->setName("PLME-ED.confirm");
		confirm->setKind(PLME_ED_CONFIRM);
		confirm->setStatus(PHY_SUCCESS);
		confirm->setEnergyLevel((rand() % 26) + 'a');
		sendPlmeUp(confirm);
	}
}

void Plme::handlePlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg);
	std::string msgName = msg->getName();
	if (msg->getKind() == PLME_SET_TRX_STATE_REQUEST) {
		PlmeSetTrxState_request* request = check_and_cast<
				PlmeSetTrxState_request *> (msg);
		PlmeSetTrxState_confirm* response = new PlmeSetTrxState_confirm();
		response->setName("PLME-SET-TRX-STATE.confirm");
		response->setKind(PLME_SET_TRX_STATE_CONFIRM);
		if (request->getState() == getLayerState()) {
			std::stringstream commentStream;
			commentStream << "Layer State already in " << std::hex
					<< (int) request->getState() << std::dec;
			comment(STATUS, commentStream.str());
			response->setStatus(request->getState());
		} else {
			std::stringstream commentStream;
			commentStream << "Changing Layer State to " << std::hex
					<< (int) request->getState() << std::dec;
			comment(STATUS, commentStream.str());
			setLayerState((PhyEnum) request->getState());
			response->setStatus(PHY_SUCCESS);

		}
		sendPlmeUp(response);
	} else if (msg->getKind() == PLME_SET_REQUEST) {
		PlmeSet_request* request = check_and_cast<PlmeSet_request *> (msg);
		unsigned int* value =
				new unsigned int[request->getPibAttributeValueArraySize()];
		for (int i = 0; i < request->getPibAttributeValueArraySize(); i++) {
			value[i] = request->getPibAttributeValue(i);
		}
		PlmeSet_confirm* response = new PlmeSet_confirm("PLME-SET.confirm", PLME_SET_CONFIRM);
		PhyEnum status = getPhyPib()->setPibAttribute(
				(PibIdentifier) request->getPibAttribute(), value);
		response->setStatus(status);
		response->setPibAttribute(request->getPibAttribute());
		sendPlmeUp(response);
	} else if (msgName == "PLME-ED.request") {
		if ((getLayerState() == PHY_TRX_OFF) || (getLayerState() == PHY_TX_ON)) {
			PlmeEd_confirm* confirm = new PlmeEd_confirm();
			confirm->setName("PLME-ED.confirm");
			confirm->setKind(PLME_ED_CONFIRM);
			confirm->setStatus(getLayerState());
			confirm->setEnergyLevel(0x00);
			sendPlmeUp(confirm);
		} else {
			timer->setName("ED.timer");
			/** @todo 960/62500 = 0.01536s - theoretically shortest ED scan*/
			/** let's give it multiplier x0.9 */
			/** how long does it take to make the measurement in real environment? */
			scheduleAt(simTime() + 0.013824, timer);
		}
	}
}

void Plme::handlePdMsg(cMessage *msg) {
	delete (msg);
}

void Plme::handlePhyPibMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msgName == "PHY-PIB-SET.confirm") {
		msg->setName("PLME-SET.confirm");
		msg->setKind(PLME_SET_CONFIRM);
		sendPlmeUp(msg);
		return;
	}
	delete (msg);
}

void Plme::sendPlmeUp(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, plmeSapOut);
}

void Plme::sendPd(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, pdOut);
}

void Plme::sendPhyPib(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, phyPibOut);
}
