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
	cMessage* lastUpperMsg;
	cMessage* timer;
	int currentChannel;
	unsigned char currentPage;
	int scannedChannels;
	char* energyLevels;
	int layerStage;
	PanDescriptor* scannedPanDescriptors;
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
	virtual double symbolsToSeconds(int, int, int);
	virtual void switchRadioToChannel(unsigned int);
	virtual void comment(CommentsLevel level, std::string s) {
		/** @todo align logName substrings for routers and endDevices */
		if ((level & commentsLevel) > NOTHING) {
			std::cout << logName() << "." << getName() << "\t" << s << endl;
		}
	}
	virtual void commentMsgSending(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Sending " << msg->getName();
		comment(MESSAGE, commentStream.str());
	}
	virtual void commentMsgReceived(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Received " << msg->getName();
		comment(MESSAGE, commentStream.str());
	}
	virtual void commentError(char* errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(ERROR, commentStream.str());
	}
	MacPib* getMacPib() {
		return ((MacPib *) (this->getParentModule()->getModuleByRelativePath(
				"macPib")));
	}
	virtual void setLastUpperMsg(cMessage* msg) {
		setLayerStage(0);
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
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
	int getCurrentChannel() {
		return this->currentChannel;
	}
	void setCurrentPage(unsigned char page) {
		this->currentPage = page;
	}
	unsigned char getCurrentPage() {
		return this->currentPage;
	}
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

	void setScannedPanDescriptors(PanDescriptor* descriptor) {
		this->scannedPanDescriptors = descriptor;
	}

	PanDescriptor* getScannedPanDescriptors() {
		return this->scannedPanDescriptors;
	}

	void addScannedPanDescriptor(PanDescriptor descriptor) {
		int size = sizeof(this->scannedPanDescriptors)/sizeof(PanDescriptor);
		PanDescriptor* newScannedPanDescriptors;
		newScannedPanDescriptors = new PanDescriptor[size+1];
		for (int i = 0; i < size; i++) {
			newScannedPanDescriptors[i] = this->scannedPanDescriptors[i];
		}
		newScannedPanDescriptors[size] = descriptor;
		delete this->scannedPanDescriptors;
		this->scannedPanDescriptors = newScannedPanDescriptors;
	}

	void resetScannedPanDescriptors() {
		delete scannedPanDescriptors;
		this->scannedPanDescriptors = new PanDescriptor[0];
	}
};

#endif
