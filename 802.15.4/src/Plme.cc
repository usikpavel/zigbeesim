/* -*- mode:c++ -*- ********************************************************
 * file:        Plme.cc
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
 * description: - Module describing the behaviour of the phy management entity
 ***************************************************************************/
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
		commentsLevel = COMMENT_ALL;
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
	if (msg->getKind() == TIMER_ED_SCAN) {
		/** @todo here, we should do the energy measurement */
		PlmeEd_confirm* confirm = new PlmeEd_confirm();
		confirm->setName("PLME-ED.confirm");
		confirm->setKind(PLME_ED_CONFIRM);
		confirm->setStatus(PHY_SUCCESS);
		confirm->setEnergyLevel((rand() % 26) + 'a');
		sendPlmeUp(confirm);
	} else if (msg->getKind() == TIMER_CCA) {
		PlmeCca_confirm *confirm = new PlmeCca_confirm("PLME-CCA.confirm", PLME_CCA_CONFIRM);
		/** @FIXME find out why do we have PHY in TRX_OFF status */
		/*
		if (getLayerState() == PHY_TRX_OFF) {
			confirm->setStatus(PHY_TRX_OFF);
		} else if (getSnrEval()->snrInfo.ptr == 0) {
			confirm->setStatus(PHY_IDLE);
		} else {
			confirm->setStatus(PHY_BUSY);
		}
		*/
		confirm->setStatus(PHY_IDLE);
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
			comment(COMMENT_STATUS, commentStream.str());
			response->setStatus(request->getState());
		} else {
			std::stringstream commentStream;
			commentStream << "Changing Layer State to " << std::hex
					<< (int) request->getState() << std::dec;
			comment(COMMENT_STATUS, commentStream.str());
			setLayerState((PhyEnum) request->getState());
			response->setStatus(PHY_SUCCESS);

		}
		sendPlmeUp(response);
	} else if (msg->getKind() == PLME_SET_REQUEST) {
		PlmeSet_request* request = check_and_cast<PlmeSet_request *> (msg);
		unsigned int* value =
				new unsigned int[request->getPibAttributeValueArraySize()];
		for (unsigned int i = 0; i < request->getPibAttributeValueArraySize(); i++) {
			value[i] = request->getPibAttributeValue(i);
		}
		PlmeSet_confirm* response = new PlmeSet_confirm("PLME-SET.confirm", PLME_SET_CONFIRM);
		PhyEnum status = getPhyPib()->setPibAttribute(
				(PibIdentifier) request->getPibAttribute(), value);
		response->setStatus(status);
		response->setPibAttribute(request->getPibAttribute());
		sendPlmeUp(response);
	} else if (msg->getKind() == PLME_ED_REQUEST) {
		if ((getLayerState() == PHY_TRX_OFF) || (getLayerState() == PHY_TX_ON)) {
			PlmeEd_confirm* confirm = new PlmeEd_confirm("PLME-ED.confirm", PLME_ED_CONFIRM);
			confirm->setStatus(getLayerState());
			confirm->setEnergyLevel(0x00);
			sendPlmeUp(confirm);
		} else {
			timer->setKind(TIMER_ED_SCAN);
			/** @todo 960/62500 = 0.01536s - theoretically shortest ED scan*/
			/** let's give it multiplier x0.9 */
			/** how long does it take to make the measurement in real environment? */
			scheduleAt(simTime() + 0.013824, timer);
		}
	} else if (msg->getKind() == PLME_CCA_REQUEST) {
		timer->setKind(TIMER_CCA);
		scheduleAt(simTime() + getMlme()->symbolsToSeconds(8, getMlme()->getCurrentChannel(), getMlme()->getCurrentPage()), timer);
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
