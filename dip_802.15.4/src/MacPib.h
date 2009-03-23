#ifndef __MACPIB_H__
#define __MACPIB_H__

#include <omnetpp.h>
#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "BBItems.h"
#include <string>
#include <sstream>

class MacPib: public BasicModule {
public:
	virtual void initialize(int);
	virtual void handleMessage(cMessage *msg);
protected:
	/** @brief gate id*/
	/*@{*/
	int mlmeOut;
	int mlmeIn;
	/*@}*/
	/** MAC PIB constants */
	unsigned char aBaseSlotDuration;
	unsigned short aBaseSuperFrameDuration;
	unsigned long aExtendedAddress;
	unsigned char aGTSDescPersistenceTime;
	unsigned char aMaxBeaconOverhead;
	unsigned char aMaxBeaconPayloadLength;
	unsigned char aMaxLostBeacons;
	unsigned char aMaxMACSafePayloadSize;
	unsigned char aMaxMACPayloadSize;
	unsigned char aMaxMPDUUnsecuredOverhead;
	unsigned char aMaxSIFSFrameSize;
	unsigned short aMinCAPLength;
	unsigned char aMinMPDUOverhead;
	unsigned char aNumSuperframeSlots;
	unsigned char aUnitBackoffPeriod;
	/** MAC PIB attributes */
	unsigned int macAckWaitDuration;
	bool macAssociatedPANCoord;
	bool macAssociationPermit;
	bool macAutoRequest;
	bool macBattLifeExt;
	unsigned int macBattLifeExtPeriods;
	unsigned char* macBeaconPayload;
	unsigned char macBeaconPayloadLength;
	unsigned char macBeaconOrder;
	unsigned int macBeaconTxTime;
	unsigned char macBSN;
	unsigned long macCoordExtendedAddress;
	unsigned short macCoordShortAddress;
	unsigned char macDSN;
	bool macGTSPermit;
	unsigned char macMaxBE;
	unsigned char macMaxCSMABackoffs;
	unsigned int macMaxFrameTotalWaitTime;
	unsigned char macMaxFrameRetries;
	unsigned char macMinBE;
	unsigned char macMinLIFSPeriod;
	unsigned char macMinSIFSPeriod;
	unsigned int macPANId;
	bool macPromiscuousMode;
	unsigned char macResponseWaitTime;
	bool macRxOnWhenIdle;
	bool macSecurityEnabled;
	unsigned short macShortAddress;
	unsigned char macSuperframeOrder;
	unsigned short macSyncSymbolOffset;
	bool macTimestampSupported;
	unsigned short macTransactionPersistenceTime;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	virtual void handleSelfMsg(cMessage*);
	virtual void handleMlmeMsg(cMessage*);
	virtual void sendMlme(cMessage*);
	virtual void resetMacPibValues();
	virtual void comment(CommentsLevel level, std::string s) {
		if ((level & commentsLevel) > NOTHING) {
			/** @todo align logName substrings for routers and endDevices */
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
public:
	MacEnum setPibAttribute(PibIdentifier, unsigned int*);
	unsigned int* getPibAttribute(PibIdentifier);
	unsigned char getBaseSlotDuration() const {
		return aBaseSlotDuration;
	}
	void setBaseSlotDuration(unsigned char aBaseSlotDuration) {
		this->aBaseSlotDuration = aBaseSlotDuration;
	}
	unsigned short getBaseSuperFrameDuration() const {
		return aBaseSuperFrameDuration;
	}
	void setBaseSuperFrameDuration(unsigned short aBaseSuperFrameDuration) {
		this->aBaseSuperFrameDuration = aBaseSuperFrameDuration;
	}
	unsigned long getExtendedAddress() const {
		return aExtendedAddress;
	}
	void setExtendedAddress(unsigned long aExtendedAddress) {
		this->aExtendedAddress = aExtendedAddress;
	}
	unsigned char getGTSDescPersistenceTime() const {
		return aGTSDescPersistenceTime;
	}
	void setGTSDescPersistenceTime(unsigned char aGTSDescPersistenceTime) {
		this->aGTSDescPersistenceTime = aGTSDescPersistenceTime;
	}
	unsigned char getMaxBeaconOverhead() const {
		return aMaxBeaconOverhead;
	}
	void setMaxBeaconOverhead(unsigned char aMaxBeaconOverhead) {
		this->aMaxBeaconOverhead = aMaxBeaconOverhead;
	}
	unsigned char getMaxBeaconPayloadLength() const {
		return aMaxBeaconPayloadLength;
	}
	void setMaxBeaconPayloadLength(unsigned char aMaxBeaconPayloadLength) {
		this->aMaxBeaconPayloadLength = aMaxBeaconPayloadLength;
	}
	unsigned char getMaxLostBeacons() const {
		return aMaxLostBeacons;
	}
	void setMaxLostBeacons(unsigned char aMaxLostBeacons) {
		this->aMaxLostBeacons = aMaxLostBeacons;
	}
	unsigned char getMaxMACSafePayloadSize() const {
		return aMaxMACSafePayloadSize;
	}
	void setMaxMACSafePayloadSize(unsigned char aMaxMACSafePayloadSize) {
		this->aMaxMACSafePayloadSize = aMaxMACSafePayloadSize;
	}
	unsigned char getMaxMACPayloadSize() const {
		return aMaxMACPayloadSize;
	}
	void setMaxMACPayloadSize(unsigned char aMaxMACPayloadSize) {
		this->aMaxMACPayloadSize = aMaxMACPayloadSize;
	}
	unsigned char getMaxMPDUUnsecuredOverhead() const {
		return aMaxMPDUUnsecuredOverhead;
	}
	void setMaxMPDUUnsecuredOverhead(unsigned char aMaxMPDUUnsecuredOverhead) {
		this->aMaxMPDUUnsecuredOverhead = aMaxMPDUUnsecuredOverhead;
	}
	unsigned char getMaxSIFSFrameSize() const {
		return aMaxSIFSFrameSize;
	}
	void setMaxSIFSFrameSize(unsigned char aMaxSIFSFrameSize) {
		this->aMaxSIFSFrameSize = aMaxSIFSFrameSize;
	}
	unsigned short getMinCAPLength() const {
		return aMinCAPLength;
	}
	void setMinCAPLength(unsigned short aMinCAPLength) {
		this->aMinCAPLength = aMinCAPLength;
	}
	unsigned char getMinMPDUOverhead() const {
		return aMinMPDUOverhead;
	}
	void setMinMPDUOverhead(unsigned char aMinMPDUOverhead) {
		this->aMinMPDUOverhead = aMinMPDUOverhead;
	}
	unsigned char getNumSuperframeSlots() const {
		return aNumSuperframeSlots;
	}
	void setNumSuperframeSlots(unsigned char aNumSuperframeSlots) {
		this->aNumSuperframeSlots = aNumSuperframeSlots;
	}
	unsigned char getUnitBackoffPeriod() const {
		return aUnitBackoffPeriod;
	}
	void setUnitBackoffPeriod(unsigned char aUnitBackoffPeriod) {
		this->aUnitBackoffPeriod = aUnitBackoffPeriod;
	}
	unsigned int getMacAckWaitDuration() const {
		return macAckWaitDuration;
	}
	void setMacAckWaitDuration(unsigned int macAckWaitDuration) {
		this->macAckWaitDuration = macAckWaitDuration;
	}
	bool getMacAssociatedPANCoord() const {
		return macAssociatedPANCoord;
	}
	void setMacAssociatedPANCoord(bool macAssociatedPANCoord) {
		this->macAssociatedPANCoord = macAssociatedPANCoord;
	}
	bool getMacAssociationPermit() const {
		return macAssociationPermit;
	}
	void setMacAssociationPermit(bool macAssociationPermit) {
		this->macAssociationPermit = macAssociationPermit;
	}
	bool getMacAutoRequest() const {
		return macAutoRequest;
	}
	void setMacAutoRequest(bool macAutoRequest) {
		this->macAutoRequest = macAutoRequest;
	}
	bool getMacBattLifeExt() const {
		return macBattLifeExt;
	}
	void setMacBattLifeExt(bool macBattLifeExt) {
		this->macBattLifeExt = macBattLifeExt;
	}
	unsigned int getMacBattLifeExtPeriods() const {
		return macBattLifeExtPeriods;
	}
	void setMacBattLifeExtPeriods(unsigned int macBattLifeExtPeriods) {
		this->macBattLifeExtPeriods = macBattLifeExtPeriods;
	}
	unsigned char *getMacBeaconPayload() const {
		return macBeaconPayload;
	}
	void setMacBeaconPayload(unsigned char *macBeaconPayload) {
		delete (this->macBeaconPayload);
		this->macBeaconPayload = macBeaconPayload;
	}
	unsigned char getMacBeaconPayloadLength() const {
		return macBeaconPayloadLength;
	}
	void setMacBeaconPayloadLength(unsigned char macBeaconPayloadLength) {
		this->macBeaconPayloadLength = macBeaconPayloadLength;
	}
	unsigned char getMacBeaconOrder() const {
		return macBeaconOrder;
	}
	void setMacBeaconOrder(unsigned char macBeaconOrder) {
		this->macBeaconOrder = macBeaconOrder;
	}
	unsigned int getMacBeaconTxTime() const {
		return macBeaconTxTime;
	}
	void setMacBeaconTxTime(unsigned int macBeaconTxTime) {
		this->macBeaconTxTime = macBeaconTxTime;
	}
	unsigned char getMacBSN() const {
		return macBSN;
	}
	void setMacBSN(unsigned char macBSN) {
		this->macBSN = macBSN;
	}
	unsigned long getMacCoordExtendedAddress() const {
		return macCoordExtendedAddress;
	}
	void setMacCoordExtendedAddress(unsigned long macCoordExtendedAddress) {
		this->macCoordExtendedAddress = macCoordExtendedAddress;
	}
	unsigned short getMacCoordShortAddress() const {
		return macCoordShortAddress;
	}
	void setMacCoordShortAddress(unsigned short macCoordShortAddress) {
		this->macCoordShortAddress = macCoordShortAddress;
	}
	unsigned char getMacDSN() const {
		return macDSN;
	}
	void setMacDSN(unsigned char macDSN) {
		this->macDSN = macDSN;
	}
	bool getMacGTSPermit() const {
		return macGTSPermit;
	}
	void setMacGTSPermit(bool macGTSPermit) {
		this->macGTSPermit = macGTSPermit;
	}
	unsigned char getMacMaxBE() const {
		return macMaxBE;
	}
	void setMacMaxBE(unsigned char macMaxBE) {
		this->macMaxBE = macMaxBE;
	}
	unsigned char getMacMaxCSMABackoffs() const {
		return macMaxCSMABackoffs;
	}
	void setMacMaxCSMABackoffs(unsigned char macMaxCSMABackoffs) {
		this->macMaxCSMABackoffs = macMaxCSMABackoffs;
	}
	unsigned int getMacMaxFrameTotalWaitTime() const {
		return macMaxFrameTotalWaitTime;
	}
	void setMacMaxFrameTotalWaitTime(unsigned int macMaxFrameTotalWaitTime) {
		this->macMaxFrameTotalWaitTime = macMaxFrameTotalWaitTime;
	}
	unsigned char getMacMaxFrameRetries() const {
		return macMaxFrameRetries;
	}
	void setMacMaxFrameRetries(unsigned char macMaxFrameRetries) {
		this->macMaxFrameRetries = macMaxFrameRetries;
	}
	unsigned char getMacMinBE() const {
		return macMinBE;
	}
	void setMacMinBE(unsigned char macMinBE) {
		this->macMinBE = macMinBE;
	}
	unsigned char getMacMinLIFSPeriod() const {
		return macMinLIFSPeriod;
	}
	void setMacMinLIFSPeriod(unsigned char macMinLIFSPeriod) {
		this->macMinLIFSPeriod = macMinLIFSPeriod;
	}
	unsigned char getMacMinSIFSPeriod() const {
		return macMinSIFSPeriod;
	}
	void setMacMinSIFSPeriod(unsigned char macMinSIFSPeriod) {
		this->macMinSIFSPeriod = macMinSIFSPeriod;
	}
	unsigned int getMacPANId() const {
		return macPANId;
	}
	void setMacPANId(unsigned int macPANId) {
		this->macPANId = macPANId;
	}
	bool getMacPromiscuousMode() const {
		return macPromiscuousMode;
	}
	void setMacPromiscuousMode(bool macPromiscuousMode) {
		this->macPromiscuousMode = macPromiscuousMode;
	}
	unsigned char getMacResponseWaitTime() const {
		return macResponseWaitTime;
	}
	void setMacResponseWaitTime(unsigned char macResponseWaitTime) {
		this->macResponseWaitTime = macResponseWaitTime;
	}
	bool getMacRxOnWhenIdle() const {
		return macRxOnWhenIdle;
	}
	void setMacRxOnWhenIdle(bool macRxOnWhenIdle) {
		this->macRxOnWhenIdle = macRxOnWhenIdle;
	}
	bool getMacSecurityEnabled() const {
		return macSecurityEnabled;
	}
	void setMacSecurityEnabled(bool macSecurityEnabled) {
		this->macSecurityEnabled = macSecurityEnabled;
	}
	unsigned short getMacShortAddress() const {
		return macShortAddress;
	}
	void setMacShortAddress(unsigned short macShortAddress) {
		this->macShortAddress = macShortAddress;
	}
	unsigned char getMacSuperframeOrder() const {
		return macSuperframeOrder;
	}
	void setMacSuperframeOrder(unsigned char macSuperframeOrder) {
		this->macSuperframeOrder = macSuperframeOrder;
	}
	unsigned short getMacSyncSymbolOffset() const {
		return macSyncSymbolOffset;
	}
	void setMacSyncSymbolOffset(unsigned short macSyncSymbolOffset) {
		this->macSyncSymbolOffset = macSyncSymbolOffset;
	}
	bool getMacTimestampSupported() const {
		return macTimestampSupported;
	}
	void setMacTimestampSupported(bool macTimestampSupported) {
		this->macTimestampSupported = macTimestampSupported;
	}
	unsigned short getMacTransactionPersistenceTime() const {
		return macTransactionPersistenceTime;
	}
	void setMacTransactionPersistenceTime(
			unsigned short macTransactionPersistenceTime) {
		this->macTransactionPersistenceTime = macTransactionPersistenceTime;
	}
};

#endif
