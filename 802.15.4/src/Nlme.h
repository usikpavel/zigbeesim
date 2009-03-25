#ifndef __NLME_H__
#define __NLME_H__

#include <omnetpp.h>

#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"

class Nlme: public BasicModule {
public:
	virtual void initialize(int);
	void handleMessage(cMessage *msg);

protected:
	/** @brief gate id*/
	/*@{*/
	int mlmeSapIn;
	int mlmeSapOut;
	int nlmeSapIn;
	int nlmeSapOut;
	int nwkPibIn;
	int nwkPibOut;
	int nldeOut;
	int nldeIn;
	/*@}*/
	/** additional variables */
	cMessage* lastUpperMsg;
	unsigned short panId;
	unsigned char logicalChannel;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;

	virtual void handleSelfMsg(cMessage *);

	virtual void handleMlmeMsg(cMessage *);

	virtual void handleNlmeMsg(cMessage *);

	virtual void handleNwkPibMsg(cMessage *);

	virtual void handleNldeMsg(cMessage *);

	virtual void sendMlmeDown(cMessage *);

	virtual void sendNlmeUp(cMessage *);

	virtual void sendNlde(cMessage *);

	virtual void sendNwkPib(cMessage *);

	unsigned char getChannelPageFromChannels(unsigned int channels);

	virtual void comment(CommentsLevel level, std::string s) {
		/** @todo align logName substrings for routers and endDevices */
		if ((level & commentsLevel) > NOTHING) {
			std::cout << logName() << "." << getName() << "\t" << s << endl;
		}
	}

	virtual void commentMsgSending(cMessage* msg) {
		std::stringstream commentStream;
		commentStream << "Sending " << msg->getName();
		comment(MESSAGE, commentStream.str());
	}

	virtual void commentMsgReceived(cMessage* msg) {
		std::stringstream commentStream;
		commentStream << "Received " << msg->getName();
		comment(MESSAGE, commentStream.str());
	}

	void setLastUpperMsg(cMessage* msg) {
		delete (this->lastUpperMsg);
		this->lastUpperMsg = msg;
	}

	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
	}

	void setPanId(unsigned short id) {
		this->panId = id;
	}

	unsigned short getPanId() {
		return this->panId;
	}

	void setLogicalChannel(unsigned char channel) {
		this->logicalChannel = channel;
	}

	unsigned char getLogicalChannel() {
		return this->logicalChannel;
	}
};

#endif
