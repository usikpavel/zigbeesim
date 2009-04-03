#ifndef __NLME_H__
#define __NLME_H__

#include <omnetpp.h>

#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "FFDAppLayer.h"
#include "NwkPib.h"
#include "Mcps.h"

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
	NetworkDescriptor* networkDescriptors;
	int networkDescriptorsArraySize;
	unsigned char networkAddress;
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
		if ((level & commentsLevel) > COMMENT_NOTHING) {
			std::cout << logName() << "." << getName() << "\t" << s << endl;
		}
	}

	virtual void commentMsgSending(cMessage* msg) {
		std::stringstream commentStream;
		commentStream << "Sending " << msg->getName();
		comment(COMMENT_MESSAGE, commentStream.str());
	}

	virtual void commentMsgReceived(cMessage* msg) {
		std::stringstream commentStream;
		commentStream << "Received " << msg->getName();
		comment(COMMENT_MESSAGE, commentStream.str());
	}

	NwkPib* getNwkPib() {
		return ((NwkPib *) (this->getParentModule()->getModuleByRelativePath(
				"nwkPib")));
	}

	FFDAppLayer* getFFDAppLayer() {
		return (FFDAppLayer *) (getParentModule()->getParentModule()->getModuleByRelativePath(
				"app"));
	}

	Mcps* getMcps() {
		return (Mcps *) (getParentModule()->getParentModule()->getModuleByRelativePath("mac")->getModuleByRelativePath("mcps"));
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

	void setNetworkDescriptorsArraySize(int size) {
		this->networkDescriptorsArraySize = size;
	}

	int getNetworkDescriptorsArraySize() {
		return this->networkDescriptorsArraySize;
	}

	void setNetworkDescriptors(NetworkDescriptor* descriptors) {
		this->networkDescriptors = descriptors;
	}

	NetworkDescriptor* getNetworkDescriptors() {
		return this->networkDescriptors;
	}

	void addNetworkDescriptor(NetworkDescriptor descriptor) {
		int size = getNetworkDescriptorsArraySize();
		NetworkDescriptor* newNetworkDescriptors;
		newNetworkDescriptors = new NetworkDescriptor[size + 1];
		for (int i = 0; i < size; i++) {
			newNetworkDescriptors[i] = this->networkDescriptors[i];
		}
		newNetworkDescriptors[size] = descriptor;
		delete this->networkDescriptors;
		this->networkDescriptors = newNetworkDescriptors;
		setNetworkDescriptorsArraySize(size + 1);
	}

	bool isNetworkScanned(NetworkDescriptor descriptor) {
		int size = getNetworkDescriptorsArraySize();
		for (int i = 0; i < size; i++) {
			if (getNetworkDescriptors()[i].panId == descriptor.panId) {
				return true;
			}
		}
		return false;
	}

	void resetNetworkDescriptors() {
		delete networkDescriptors;
		setNetworkDescriptorsArraySize(0);
		this->networkDescriptors = new NetworkDescriptor[0];
	}

	unsigned short getNetworkAddress() {
		return this->networkAddress;
	}

	void setNetworkAddress(unsigned short networkAddress) {
		this->networkAddress = networkAddress;
	}

};

#endif
