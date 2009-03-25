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
	cMessage* timer;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	void handleSelfMsg(cMessage *);
	void handlePdMsg(cMessage *);
	void handleMcpsMsg(cMessage *);
	void handleMlmeMsg(cMessage *);
	void sendPdDown(cMessage *);
	void sendMcpsUp(cMessage *);
	void sendMlme(cMessage *);
	PdMsg* encapsulateMcps(McpsMsg *);
	McpsMsg* decapsulatePd(PdMsg *);
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
	void commentError(char* errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(ERROR, commentStream.str());
	}
	void setLastUpperMsg(cMessage* msg) {
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}
	MacPib* getMacPib() {
		return ((MacPib *) (this->getParentModule()->getModuleByRelativePath(
				"macPib")));
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
	}
};

#endif
