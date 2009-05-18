/* -*- mode:c++ -*- ********************************************************
 * file:        PhyPib.cc
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
 * description: - Module describing the behaviour of the phy information base
 ***************************************************************************/
#include "PhyPib.h"

Define_Module(PhyPib)
;

void PhyPib::initialize(int stage) {
	BasicModule::initialize(stage);
	if (stage == 0) {
		plmeOut = findGate("plmeOut");
		plmeIn = findGate("plmeIn");

		phyChannelsSupported = new unsigned int[1];
		resetPhyPibValues();
		commentsLevel = COMMENT_ALL;
	}
}

void PhyPib::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == plmeIn) {
		handlePlmeMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void PhyPib::handleSelfMsg(cMessage *msg) {
	delete (msg);
}

void PhyPib::handlePlmeMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	delete (msg);
}

void PhyPib::sendPlme(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, plmeOut);
}

void PhyPib::resetPhyPibValues() {
	setMaxPHYPacketSize(127);
	setTurnAroundTime(12);
}

PhyEnum PhyPib::setPibAttribute(PibIdentifier attribute, unsigned int* value) {
	/** @todo Add condition when the attribute is just read-only */
	switch (attribute) {
	case PHY_CURRENT_CHANNEL:
		if (value[0] > 26) {
			return PHY_INVALID_PARAMETER;
		}
		setPhyCurrentChannel(value[0]);
		break;
	case PHY_CHANNELS_SUPPORTED:
		if ((sizeof(value)/sizeof(int)) >= 32) {
			return PHY_INVALID_PARAMETER;
		}
		setPhyChannelsSupported(value);
		break;
	case PHY_TRANSMIT_POWER:
		if (value[0] < 0xbf) {
			return PHY_INVALID_PARAMETER;
		}
		setPhyTransmitPower(value[0]);
		break;
	case PHY_CCA_MODE:
		if ((value[0] < 1) || (value[0] > 3)) {
			return PHY_INVALID_PARAMETER;
		}
		setPhyCCAMode(value[0]);
		break;
	case PHY_CURRENT_PAGE:
		if (value[0] >= 32) {
			return PHY_INVALID_PARAMETER;
		}
		setPhyCurrentPage(value[0]);
		break;
	case PHY_MAX_FRAME_DURATION:
		if ((value[0] != 55) && (value[0] != 212) && (value[0] != 266)
				&& (value[0] != 1064)) {
			return PHY_INVALID_PARAMETER;
		}
		setPhyMaxFrameDuration(value[0]);
		break;
	case PHY_SHR_DURATION:
		if ((value[0] != 3) && (value[0] != 7) && (value[0] != 10) && (value[0]
				!= 40)) {
			return PHY_INVALID_PARAMETER;
		}
		setPhySHRDuration(value[0]);
		break;
	case 0x07:
		if ((value[0] != 0.4) && (value[0] != 1.6) && (value[0] != 2.0)
				&& (value[0] != 8.0)) {
			return PHY_INVALID_PARAMETER;
		}
		setPhySymbolsPerOctet(value[0]);
		break;
	default:
		return PHY_UNSUPPORTED_ATTRIBUTE;
	}
	return PHY_SUCCESS;
}
