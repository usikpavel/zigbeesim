/* -*- mode:c++ -*- ********************************************************
 * file:        Mlme.h
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
 * description: - Module describing the behavior of the mac management entity
 ***************************************************************************/

#ifndef __MLME_H__
#define __MLME_H__

#include <omnetpp.h>
#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "BBItems.h"
#include <string>
#include <sstream>
#include "MacPib.h"
#include "Mcps.h"
#include "Pd.h"

class Mlme: public BasicModule {
public:
	virtual void initialize(int);
	virtual void handleMessage(cMessage *msg);

protected:
	/** @brief gate id*/
	/*@{*/
	int mlmeSapIn;
	int mlmeSapOut;
	int plmeSapIn;
	int plmeSapOut;
	int macPibIn;
	int macPibOut;
	int mcpsOut;
	int mcpsIn;
	/*@}*/
	/** additional variables */
	Role role;
	cMessage* lastUpperMsg;
	MacBeacon* lastBeacon;
	cMessage* timer;
	cMessage* beaconTimer;
	cMessage* backoffTimer;
	cMessage* capSlotTimer;
	cMessage* superframeTimer;
	cMessage* dataRequestTimer;
	cMessage* timeoutMsg;
	int currentChannel;
	unsigned char currentPage;
	int scannedChannels;
	char* energyLevels;
	int layerStage;
	PanDescriptor* scannedPanDescriptors;
	int scannedPanDescriptorsArraySize;
	double beaconPeriod;
	SimTime lastBeaconTimestamp;
	int capSlotNumber;
	int backoffExponent;
	int numberOfBackoffs;
	SimTime capSlotDuration;
	SimTime superframeDuration;
	SimTime backoffPeriod;
	SuperframePeriod superframePeriod;
	bool dataRequestScheduled;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	virtual void handleSelfMsg(cMessage *);
	virtual void handlePlmeMsg(cMessage *);
	virtual void handleMlmeMsg(cMessage *);
	virtual void handleMacPibMsg(cMessage *);
	virtual void handleMcpsMsg(cMessage *);
	virtual void sendPlmeDown(cMessage *);
	virtual void sendMlmeUp(cMessage *);
	virtual void sendMacPib(cMessage *);
	virtual void sendMcps(cMessage *);
public:
	virtual double symbolsToSeconds(int, int, int);
protected:
	virtual void switchRadioToChannel(unsigned int);
	void recalculateBackoffPeriod();
	void resetBackoffPeriod();
	SimTime calculateBackoffPeriod();
	virtual void comment(CommentsLevel level, std::string s) {
		/** @TODO align logName substrings for routers and endDevices */
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
	virtual void commentError(const char* errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(COMMENT_ERROR, commentStream.str());
	}
	Role getRole() {
		return this->role;
	}
	void setRole(Role role) {
		this->role = role;
	}
	MacPib* getMacPib() {
		return ((MacPib *) (this->getParentModule()->getModuleByRelativePath(
				"macPib")));
	}
	Mcps* getMcps() {
		return ((Mcps *) (this->getParentModule()->getModuleByRelativePath(
				"mcps")));
	}
	Pd* getPd() {
		return ((Pd *) (this->getParentModule()->getParentModule()->getModuleByRelativePath(
				"phy.pd")));
	}
	void setLastUpperMsg(cMessage* msg) {
		setLayerStage(0);
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
	}
	void setLastBeacon(MacBeacon* msg) {
		delete (this->lastBeacon);
		this->lastBeacon = msg;
	}
	MacBeacon* getLastBeacon() {
		return this->lastBeacon;
	}
	void setLayerStage(int stage) {
		this->layerStage = stage;
	}
	int getLayerStage() {
		return this->layerStage;
	}
	void setCurrentChannel(int channel) {
		this->currentChannel = channel;
	}
public:
	int getCurrentChannel() {
		return this->currentChannel;
	}
protected:
	void setCurrentPage(unsigned char page) {
		this->currentPage = page;
	}
public:
	unsigned char getCurrentPage() {
		return this->currentPage;
	}
protected:
	void setScannedChannels(int scannedChannels) {
		this->scannedChannels = scannedChannels;
	}
	int getScannedChannels() {
		return this->scannedChannels;
	}

	void setEnergyLevels(char* energyLevels) {
		this->energyLevels = energyLevels;
	}
	char* getEnergyLevels() {
		return this->energyLevels;
	}

	void setScannedPanDescriptorsArraySize(int size) {
		this->scannedPanDescriptorsArraySize = size;
	}

	int getScannedPanDescriptorsArraySize() {
		return this->scannedPanDescriptorsArraySize;
	}

	void setScannedPanDescriptors(PanDescriptor* descriptors) {
		this->scannedPanDescriptors = descriptors;
	}

	PanDescriptor* getScannedPanDescriptors() {
		return this->scannedPanDescriptors;
	}

	void addScannedPanDescriptor(PanDescriptor descriptor) {
		int size = getScannedPanDescriptorsArraySize();
		PanDescriptor* newScannedPanDescriptors;
		newScannedPanDescriptors = new PanDescriptor[size + 1];
		for (int i = 0; i < size; i++) {
			newScannedPanDescriptors[i] = this->scannedPanDescriptors[i];
		}
		newScannedPanDescriptors[size] = descriptor;
		delete this->scannedPanDescriptors;
		this->scannedPanDescriptors = newScannedPanDescriptors;
		setScannedPanDescriptorsArraySize(size + 1);
		std::stringstream commentStream;
		commentStream << "New PAN (ID: " << descriptor.coordPanId
				<< ") on this channel detected";
		comment(COMMENT_PAN, commentStream.str());
	}

	bool isPanScanned(PanDescriptor descriptor) {
		int size = getScannedPanDescriptorsArraySize();
		for (int i = 0; i < size; i++) {
			if (getScannedPanDescriptors()[i].coordPanId
					== descriptor.coordPanId) {
				return true;
			}
		}
		return false;
	}

	void resetScannedPanDescriptors() {
		delete scannedPanDescriptors;
		setScannedPanDescriptorsArraySize(0);
		this->scannedPanDescriptors = new PanDescriptor[0];
	}

	void setBeaconPeriod(double period) {
		this->beaconPeriod = period;
	}

	SimTime getBeaconPeriod() {
		return this->beaconPeriod;
	}

	void setLastBeaconTimestamp(SimTime lastBeaconTimestamp) {
		this->lastBeaconTimestamp = lastBeaconTimestamp;
	}

	SimTime getLastBeaconTimestamp() {
		return this->lastBeaconTimestamp;
	}
	void setCapSlotNumber(int capSlotNumber) {
		this->capSlotNumber = capSlotNumber;
	}
	int getCapSlotNumber() {
		return this->capSlotNumber;
	}
	void setBackoffPeriod(SimTime backoffPeriod) {
		this->backoffPeriod = backoffPeriod;
	}
	SimTime getBackoffPeriod() {
		return this->backoffPeriod;
	}
	void setBackoffExponent(int backoffExponent) {
		this->backoffExponent = backoffExponent;
	}
	int getBackoffExponent() {
		return this->backoffExponent;
	}
	void setNumberOfBackoffs(int numberOfBackoffs) {
		this->numberOfBackoffs = numberOfBackoffs;
	}
	int getNumberOfBacoffs() {
		return this->numberOfBackoffs;
	}
	void setCapSlotDuration(SimTime capSlotDuration) {
		this->capSlotDuration = capSlotDuration;
	}
	SimTime getCapSlotDuration() {
		return this->capSlotDuration;
	}
	void setSuperframeDuration(SimTime superframeDuration) {
		this->superframeDuration = superframeDuration;
	}
	SimTime getSuperframeDuration() {
		return this->superframeDuration;
	}
	void setSuperframePeriod(SuperframePeriod superframePeriod) {
		this->superframePeriod = superframePeriod;
	}
	SuperframePeriod getSuperframePeriod() {
		return this->superframePeriod;
	}
	void setDataRequestScheduled(bool dataRequestScheduled) {
		this->dataRequestScheduled = dataRequestScheduled;
	}
	bool getDataRequestScheduled() {
		return this->dataRequestScheduled;
	}
};

#endif
