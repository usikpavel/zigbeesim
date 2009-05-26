/* -*- mode:c++ -*- ********************************************************
 * file:        FFDAppLayer.cc
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
 * description: - Module describing the behavior of the application layer
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
					TIMER_START);
			scheduleAt(simTime(), msg);
		} else if (getRole() == ROUTER) {
			cMessage* msg = new cMessage("NLME-NETWORK-DISCOVERY.request",
					TIMER_START);
			scheduleAt(simTime() + 100 + uniform(10, 15), msg);
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
		/** @todo include the param into the omnetpp.ini */
		request->setPermitDuration(0xFF);
		sendNlmeDown(request);
		recordScalar("Network Formation Time", simTime());
	} else if (msg->getKind() == NLME_PERMIT_JOINING_CONFIRM) {
	} else if (msg->getKind() == NLME_NETWORK_DISCOVERY_CONFIRM) {
		NlmeNetworkDiscovery_confirm* confirm = check_and_cast<
				NlmeNetworkDiscovery_confirm *> (msg);
		NlmeJoin_request* request = new NlmeJoin_request("NLME-JOIN.request",
				NLME_JOIN_REQUEST);
		/** @comment if no network was found, let's try again later */
		if (confirm->getNetworkCount() == 0) {
			delete (msg);
			cMessage* msg = new cMessage("NLME-NETWORK-DISCOVERY.request",
					TIMER_START);
			comment(COMMENT_PAN, "No networks detected, trying again in 60s");
			/** @todo add this param into the omnetpp.ini */
			scheduleAt(simTime() + 60.0, msg);
			return;
		}
		/** @comment let's pick one random scanned network */
		request->setPanId(confirm->getNetworkDescriptorList(rand()
				% (confirm->getNetworkCount())).panId);
		request->setJoinAsRouter(getRole() == ROUTER);
		request->setRejoinNetwork(false);
		request->setPowerSource(false);
		request->setRxOnWhenIdle(false);
		request->setMacSecurity(false);
		sendNlmeDown(request);
	}
	delete (msg);
}

void FFDAppLayer::handleSelfMsg(cMessage* msg) {
	if (msg->getKind() == TIMER_START) {
		std::string msgName = msg->getName();
		if (msgName == "NLME-NETWORK-FORMATION.request") {
			NlmeNetworkFormation_request* request =
					new NlmeNetworkFormation_request();
			/** @todo include these params into omnetpp.ini file
			 * more info on this on page 6 in the notepad, or in the 802154 doc */
			request->setName("NLME-NETWORK-FORMATION.request");
			request->setKind(NLME_NETWORK_FORMATION_REQUEST);
			//request->setScanChannels(0x00001800);
			request->setScanChannels(0x00001803);
			request->setScanDuration(0x00);
			request->setBeaconOrder(0x0E);
			request->setSuperframeOrder(0x0A);
			/** @note 0xFFFF is considered a NULL value in my case */
			/** @todo ad this param into the omnetpp.ini as well */
			request->setPANId(0x0005);
			request->setBatteryLifeExtension(false);
			sendNlmeDown(request);
		} else if (msgName == "NLME-NETWORK-DISCOVERY.request") {
			NlmeNetworkDiscovery_request* request =
					new NlmeNetworkDiscovery_request(
							"NLME-NETWORK-DISCOVERY.request",
							NLME_NETWORK_DISCOVERY_REQUEST);
			request->setScanChannels(0x00003000);
			request->setScanDuration(0xCF);
			sendNlmeDown(request);
		}
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
