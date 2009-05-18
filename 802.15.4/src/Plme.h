/* -*- mode:c++ -*- ********************************************************
 * file:        Plme.h
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
#ifndef __PLME_H__
#define __PLME_H__

#include <omnetpp.h>
#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "BBItems.h"
#include <string>
#include <sstream>
#include "PhyPib.h"
#include "SnrEval802154.h"
#include "Mlme.h"

class Plme: public BasicModule {
public:
	virtual void initialize(int);
	virtual void handleMessage(cMessage *msg);
protected:
	/** @brief gate id*/
	/*@{*/
	int plmeSapOut;
	int plmeSapIn;
	int pdOut;
	int pdIn;
	int phyPibOut;
	int phyPibIn;
	/*@}*/
	/** @brief Last message received from upper level */
	cMessage* lastUpperMsg;
	cMessage* timer;
	/** @brief Layer state */
	PhyEnum layerState;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	virtual void handleSelfMsg(cMessage *);
	virtual void handlePlmeMsg(cMessage *);
	virtual void handlePdMsg(cMessage *);
	virtual void handlePhyPibMsg(cMessage *);
	virtual void sendPlmeUp(cMessage *);
	virtual void sendPd(cMessage *);
	virtual void sendPhyPib(cMessage *);
	PhyPib* getPhyPib() {
		return ((PhyPib *) (this->getParentModule()->getModuleByRelativePath(
				"phyPib")));
	}
	SnrEval802154* getSnrEval() {
		return ((SnrEval802154 *) (this->getParentModule()->getModuleByRelativePath(
				"snrEval")));
	}
	Mlme* getMlme() {
		return ((Mlme *) (this->getParentModule()->getParentModule()->getModuleByRelativePath(
				"mac.mlme")));
	}
	virtual void setLastUpperMsg(cMessage* msg) {
		delete (lastUpperMsg);
		lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return lastUpperMsg;
	}
	virtual void comment(CommentsLevel level, std::string s) {
		/** @todo align logName substrings for routers and endDevices */
		if ((level & commentsLevel) > COMMENT_NOTHING) {
			std::cout << logName() << "." << getName() << "\t" << s << endl;
		}
	}
	virtual void commentMsgSending(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Sending " << msg->getName();
		comment(COMMENT_MESSAGE, commentStream.str());
	}
	virtual void commentMsgReceived(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Received " << msg->getName();
		comment(COMMENT_MESSAGE, commentStream.str());
	}
	PhyEnum getLayerState() const {
		return layerState;
	}
	void setLayerState(PhyEnum layerState) {
		this->layerState = layerState;
	}
};

#endif
