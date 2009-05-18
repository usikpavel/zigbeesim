/* -*- mode:c++ -*- ********************************************************
 * file:        Mcps.h
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
 * description: - Module describing the behavior of the mac data entity
 ***************************************************************************/
#ifndef __MCPS_H__
#define __MCPS_H__

#include <omnetpp.h>
#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "BBItems.h"
#include <string>
#include <sstream>
#include "MacPib.h"
#include "Pd.h"
#include "PhyPib.h"

class Mcps: public BasicModule {
public:
	virtual void initialize(int);
	virtual void handleMessage(cMessage *msg);
protected:
	/** @brief gate id*/
	/*@{*/
	int mcpsSapIn;
	int mcpsSapOut;
	int pdSapIn;
	int pdSapOut;
	int mlmeIn;
	int mlmeOut;
	/*@}*/
	/** additional variables */
	cMessage* lastUpperMsg;
	cMessage* ackTimer;
	PdMsg* lastLowerMsg;
	McpsEncapsulation encapsulation;
	McpsEncapsulation* nextEncapsulation;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	int frameQueueLength;
	std::list<PdMsg *> frameQueue;
	int priorityFrameQueueLength;
	std::list<PdMsg *> priorityFrameQueue;
	virtual ~Mcps();
	void handleSelfMsg(cMessage *);
	void handlePdMsg(cMessage *);
	void handleMcpsMsg(cMessage *);
	void handleMlmeMsg(cMessage *);
	void sendPdDown(cMessage *);
	void sendMcpsUp(cMessage *);
	void sendMlme(cMessage *);
	void sendMcpsUp(cMessage *, double);
	void sendMlme(cMessage *, double);
	/** @brief method to extract the frame from the queue and send it*/
public:
	void sendCapFrame();
protected:
	PdMsg* encapsulateMcps(McpsMsg *);
	McpsMsg* decapsulatePd(PdMsg *);
	void comment(CommentsLevel level, std::string s) {
		/** @todo align logName substrings for routers and endDevices */
		if ((level & commentsLevel) > COMMENT_NOTHING) {
			std::cout << logName() << "." << getName() << "\t" << s << endl;
		}
	}
	void commentMsgSending(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Sending " << msg->getName();
		comment(COMMENT_MESSAGE, commentStream.str());
	}
	void commentMsgReceived(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Received " << msg->getName();
		comment(COMMENT_MESSAGE, commentStream.str());
	}
	void commentError(std::string errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(COMMENT_ERROR, commentStream.str());
	}
public:
	void setLastUpperMsg(cMessage* msg) {
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
	}
	MacPib* getMacPib() {
		return ((MacPib *) (this->getParentModule()->getModuleByRelativePath(
				"macPib")));
	}
	Pd* getPd() {
		return ((Pd *) (this->getParentModule()->getParentModule()->getModuleByRelativePath(
				"phy.pd")));
	}
	PhyPib* getPhyPib() {
		return ((PhyPib *) (this->getParentModule()->getParentModule()->getModuleByRelativePath(
				"phy.phyPib")));
	}
	void setLastLowerMsg(PdMsg* lastLowerMsg) {
		delete (this->lastLowerMsg);
		this->lastLowerMsg = lastLowerMsg;
	}
	PdMsg* getLastLowerMsg() {
		return this->lastLowerMsg;
	}
	void setNextEncapsulation(McpsEncapsulation nextEncapsulation) {
		this->nextEncapsulation->frameType = nextEncapsulation.framePending;
		this->nextEncapsulation->securityEnabled
				= nextEncapsulation.securityEnabled;
		this->nextEncapsulation->framePending = nextEncapsulation.framePending;
		this->nextEncapsulation->ackRequest = nextEncapsulation.ackRequest;
		this->nextEncapsulation->panIdCompression
				= nextEncapsulation.panIdCompression;
		this->nextEncapsulation->destinationAddressingMode
				= nextEncapsulation.destinationAddressingMode;
		this->nextEncapsulation->frameVersion = nextEncapsulation.frameVersion;
		this->nextEncapsulation->sourceAddressingMode
				= nextEncapsulation.sourceAddressingMode;
		this->nextEncapsulation->sequenceNumber
				= nextEncapsulation.sequenceNumber;
		this->nextEncapsulation->destinationPanIdentifier
				= nextEncapsulation.destinationPanIdentifier;
		this->nextEncapsulation->destinationAddress
				= nextEncapsulation.destinationAddress;
		this->nextEncapsulation->sourcePanIdentifier
				= nextEncapsulation.sourcePanIdentifier;
		this->nextEncapsulation->sourceAddress
				= nextEncapsulation.sourceAddress;
	}
	McpsEncapsulation* getNextEncapsulation() {
		return nextEncapsulation;
	}
	void setFrameQueueLength(int frameQueueLength) {
		this->frameQueueLength = frameQueueLength;
	}
	int getFrameQueueLength() {
		return this->frameQueueLength;
	}
	void setPriorityFrameQueueLength(int priorityFrameQueueLength) {
		this->priorityFrameQueueLength = priorityFrameQueueLength;
	}
	int getPriorityFrameQueueLength() {
		return this->priorityFrameQueueLength;
	}
};

#endif
