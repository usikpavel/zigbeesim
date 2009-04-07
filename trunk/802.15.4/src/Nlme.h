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
	MacBeaconPayload macBeaconPayload;
	unsigned char depth;
	std::map<unsigned long, NeighborTableEntry> neighborTable;
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
	virtual void commentError(const char* errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(COMMENT_ERROR, commentStream.str());
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
		return (Mcps *) (getParentModule()->getParentModule()->getModuleByRelativePath(
				"nic")->getModuleByRelativePath("mac")->getModuleByRelativePath(
				"mcps"));
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

	MacBeaconPayload getMacBeaconPayload() {
		return this->macBeaconPayload;
	}

	void setMacBeaconPayload(MacBeaconPayload macBeaconPayload) {
		this->macBeaconPayload = macBeaconPayload;
	}
	MacPib* getMacPib() {
		return ((MacPib *) (this->getParentModule()->getParentModule()->getModuleByRelativePath(
				"nic")->getModuleByRelativePath("mac")->getModuleByRelativePath(
				"macPib")));
	}
	void setDepth(unsigned char depth) {
		this->depth = depth;
	}
	unsigned char getDepth() {
		return this->depth;
	}
	void addNeighborTableEntry(NeighborTableEntry entry) {
		unsigned long key = entry.extendedAddress;
		if (!hasNeighborTableEntry(key)) {
			/** @comment the neighbor is not in the map, so let's add it */
			neighborTable.insert(std::pair<unsigned long, NeighborTableEntry>(
					key, entry));
		}
	}
	bool hasNeighborTableEntry(NeighborTableEntry entry) {
		unsigned long key = entry.extendedAddress;
		return hasNeighborTableEntry(key);
	}
	bool hasNeighborTableEntry(unsigned long key) {
		std::map<unsigned long, NeighborTableEntry>::iterator iterator =
				neighborTable.begin();
		iterator = neighborTable.find(key);
		if (iterator == neighborTable.end())
			return false;
		else
			return true;
	}
	void deleteNeighborTableEntry(NeighborTableEntry entry) {
		unsigned long key = entry.extendedAddress;
		if (hasNeighborTableEntry(entry)) {
			std::map<unsigned long, NeighborTableEntry>::iterator iterator =
					neighborTable.begin();
			iterator = neighborTable.find(key);
			neighborTable.erase(iterator);
		}
	}
	/** @note if the neighbor is not in the table, returns NULL */
	NeighborTableEntry getNeighborTableEntry(unsigned long key) {
		std::map<unsigned long, NeighborTableEntry>::iterator iterator =
				neighborTable.begin();
		iterator = neighborTable.find(key);
		return iterator->second;
	}
	NeighborTableEntry findRouterForJoining(unsigned short panId) {
		std::list<NeighborTableEntry> possibleRouters;
		NeighborTableEntry routerForJoining;
		/** @comment let's create a list of possible parents */
		for (std::map<unsigned long, NeighborTableEntry>::iterator iterator =
				neighborTable.begin(); iterator != neighborTable.end(); iterator++) {
			if (iterator->second.panId == panId) {
				possibleRouters.push_back(iterator->second);
			}
		}
		/** @comment now find the parent with the lowest depth in the network tree */
		routerForJoining = *(possibleRouters.begin());
		for (std::list<NeighborTableEntry>::iterator iterator =
				possibleRouters.begin(); iterator != possibleRouters.end(); iterator++) {
			if (routerForJoining.depth > (*(iterator)).depth) {
				routerForJoining = *(iterator);
			}
		}
		return routerForJoining;
	}
};

#endif
