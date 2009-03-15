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
	int currentChannel;
	unsigned char currentPage;
	/** additional variables */
	cMessage* lastUpperMsg;
	cMessage* timer;
	int scannedChannels;
	char* energyLevels;
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
	MacPib* getMacPib() {
		return ((MacPib *) (this->getParentModule()->getModuleByRelativePath(
				"macPib")));
	}
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
	virtual void setLastUpperMsg(cMessage* msg) {
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
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
};

#endif
