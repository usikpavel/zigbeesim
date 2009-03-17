#ifndef __PD_H__
#define __PD_H__

#include <omnetpp.h>
#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "BBItems.h"
#include <string>
#include <sstream>
#include "PhyPib.h"
#include "SingleChannelRadio.h"

class Pd: public BasicModule {
public:
	void initialize(int);
	void handleMessage(cMessage *msg);
protected:
	/** @brief gate id*/
	/*@{*/
	int pdSapOut;
	int pdSapIn;
	int rfSapOut;
	int rfSapIn;
	int plmeOut;
	int plmeIn;
	/*@}*/
	SingleChannelRadio* radio;
	/** @brief Last message received from upper level */
	cMessage* lastUpperMsg;
	cMessage* timer;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	void handleSelfMsg(cMessage *);
	void handlePdMsg(cMessage *);
	void handleRfMsg(cMessage *);
	void handlePlmeMsg(cMessage *);
	void sendPdUp(cMessage *);
	void sendRfDown(cMessage *);
	void sendPlme(cMessage *);
	AirFrame802154* encapsulatePd(PdMsg*);
	PdMsg* decapsulateAirFrame(AirFrame802154*);
	void comment(CommentsLevel level, std::string s) {
		/** @todo align logName substrings for routers and endDevices */
		if ((level & commentsLevel) > NOTHING) {
			std::cout << logName() << "." << getName() << "\t" << s << endl;
		}
	}
	void commentMsgSending(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Sending " << msg->getName();
		comment(MESSAGE, commentStream.str());
	}
	void commentMsgReceived(cMessage *msg) {
		std::stringstream commentStream;
		commentStream << "Received " << msg->getName();
		comment(MESSAGE, commentStream.str());
	}
	PhyPib* getPhyPib() {
		return ((PhyPib *) (this->getParentModule()->getModuleByRelativePath(
				"phyPib")));
	}
	void setLastUpperMsg(cMessage* msg) {
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
	}
};

#endif
