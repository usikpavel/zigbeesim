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
#include <cassert>
#include "MacControlInfo.h"
#include "SimpleAddress.h"
#include "CoreDebug.h"
#include <list>
#include <ActiveChannel.h>
#include "ChannelControl.h"

class Pd: public BasicModule {
public:
	void initialize(int);
	void handleMessage(cMessage *msg);

	/** @brief gate id*/
	/*@{*/
	int pdSapOut;
	int pdSapIn;
	int rfSapOut;
	int rfSapIn;
	int plmeOut;
	int plmeIn;
	int rfControlIn;
	/*@}*/
	/** @brief Last message received from upper level */
	cMessage* lastUpperMsg;
	cMessage* frameTimer;
	SimTime lastMsgTimestamp;
	SimTime backoffPeriod;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	/** @TODO remove this temporary cc */
	ChannelControl* cc;
	void handleSelfMsg(cMessage *);
	void handlePdMsg(cMessage *);
	void handleRfMsg(cMessage *);
	void handlePlmeMsg(cMessage *);
	void handleRfControl(cMessage *);
	void sendPdUp(cMessage *);
	void sendRfDown(cMessage *);
	void sendPlme(cMessage *);
	Frame802154* encapsulatePd(PdMsg*);
	PdMsg* decapsulateFrame(Frame802154*);
	unsigned char calculatePreambleLengthInSymbols();
	double calculatePreambleLengthInSeconds();
	unsigned char calculateSfdLengthInSymbols();
	double calculateSfdLengthInSeconds();
	double symbolsToSeconds(unsigned int symbols);
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
	void commentError(const char* errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(COMMENT_ERROR, commentStream.str());
	}
	PhyPib* getPhyPib() {
		return ((PhyPib *) (this->getParentModule()->getModuleByRelativePath(
				"phyPib")));
	}
	void setLastUpperMsg(cMessage* msg) {
		this->lastUpperMsg = msg;
	}
	cMessage* getLastUpperMsg() {
		return this->lastUpperMsg;
	}
	void setLastMsgTimestamp(SimTime lastMsgTimestamp) {
		this->lastMsgTimestamp = lastMsgTimestamp;
	}
	SimTime getLastMsgTimestamp() {
		return this->lastMsgTimestamp;
	}
	/** @TODO clean this up*/
	/** temp */
	typedef std::list<Frame802154 *> FrameQueue;
	enum States {
		RX, TX,
	};
	States phyState;
	RadioState::States radioState;
	int catRadioState;
	SingleChannelRadio* radio;
	FrameQueue frameQueue;
	int myMacAddr;
	unsigned int queueLength;
	void prepareSend();
	void receiveBBItem(int category, const BBItem *details, int scopeModuleId);
	/** -temp */
};

#endif
