/* -*- mode:c++ -*- *******************************************************
 * file:        BasicApplLayer.cc
 *
 * author:      Daniel Willkomm
 *
 * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
 *              Technische Universitaet Berlin, Germany.
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 *              For further information see file COPYING
 *              in the top level directory
 ***************************************************************************
 * part of:     framework implementation developed by tkn
 * description: application layer: general class for the application layer
 *              subclass to create your own application layer
 ***************************************************************************/

#include "FFDAppLayer.h"

Define_Module( FFDAppLayer);

/**
 * First we have to initialize the module from which we derived ours,
 * in this case BasicModule.
 *
 * Then we have to intialize the gates and - if necessary - some own
 * variables.
 **/
void FFDAppLayer::initialize(int stage) {
	BasicApplLayer::initialize(stage);

	if (stage == 0) {
		headerLength = par("headerLength");
		nldeSapIn = findGate("nldeSapIn");
		nldeSapOut = findGate("nldeSapOut");
		nlmeSapIn = findGate("nlmeSapIn");
		nlmeSapOut = findGate("nlmeSapOut");

		commentsLevel = COMMENT_ALL;
		if (logName().substr(0, 11) == "coordinator") {
			setRole(COORDINATOR);
		} else if (logName().substr(0, 6) == "router") {
			setRole(ROUTER);
		} else {
			setRole(END_DEVICE);
		}
	} else if (stage == 1) {
		if (getRole() == COORDINATOR) {
			cMessage* msg = new cMessage("NLME-NETWORK-FORMATION.request",
					START_TIMER);
			scheduleAt(simTime(), msg);
		}
	}
}

/**
 * The basic handle message function.
 *
 * Depending on the gate a message arrives handleMessage just calls
 * different handle message functions to further process the message.
 *
 * You should not make any changes in this function but implement all
 * your functionality into the handle*Msg functions called from here.
 *
 * @sa handleLowerMsg, handleSelfMsg
 **/
void FFDAppLayer::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == nlmeSapIn) {
		handleNlmeMsg(msg);
	} else if (msg->getArrivalGateId() == nldeSapIn) {
		handleNldeMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void FFDAppLayer::handleNldeMsg(cMessage* msg) {
	delete (msg);
}

void FFDAppLayer::handleNlmeMsg(cMessage* msg) {
	if (msg->getKind() == NLME_NETWORK_FORMATION_CONFIRM) {
		NlmePermitJoining_request* request = new NlmePermitJoining_request(
				"NLME-PERMIT-JOINING.request", NLME_PERMIT_JOINING_REQUEST);
		request->setPermitDuration(0xAF);
		sendNlmeDown(request);
	}
	delete (msg);
}

void FFDAppLayer::handleSelfMsg(cMessage* msg) {
	if (msg->getKind() == START_TIMER) {
		NlmeNetworkFormation_request* request =
				new NlmeNetworkFormation_request();
		/** @todo include these params into omnetpp.ini file
		 * more info on this on page 6 in the notepad, or in the 802154 doc */
		request->setName("NLME-NETWORK-FORMATION.request");
		request->setKind(NLME_NETWORK_FORMATION_REQUEST);
		request->setScanChannels(0x00003800);
		request->setScanDuration(0x00);
		request->setBeaconOrder(0x0E);
		request->setSuperframeOrder(0x0A);
		/** @note 0xFFFF is considered a NULL value in my case */
		request->setPANId(0xFFFF);
		request->setBatteryLifeExtension(false);
		sendNlmeDown(request);
	}
	delete (msg);
}

/**
 * Send message down to lower layer
 **/
void FFDAppLayer::sendNldeDown(cMessage *msg) {
	sendDelayed(msg, 0.0, nldeSapOut);
}

/**
 * Send message down to lower layer
 **/
void FFDAppLayer::sendNlmeDown(cMessage *msg) {
	sendDelayed(msg, 0.0, nlmeSapOut);
}
