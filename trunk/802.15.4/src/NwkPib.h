/* -*- mode:c++ -*- ********************************************************
 * file:        NwkPib.h
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
 * description: - Module describing the behaviour of the nwk information base
 ***************************************************************************/
#ifndef __NWKPIB_H__
#define __NWKPIB_H__

#include <omnetpp.h>
#include "BasicModule.h"
#include "typedef.h"
#include "Messages_m.h"
#include "BBItems.h"
#include <string>
#include <sstream>
#include "FFDAppLayer.h"

class NwkPib: public BasicModule {
public:
	virtual void initialize(int);
	virtual void handleMessage(cMessage *msg);
protected:
	/** @brief gate id*/
	/*@{*/
	int nlmeOut;
	int nlmeIn;
	/*@}*/
	/** NWK PIB constants */
	bool nwkcCoordinatorCapable;
	/** @fixme omitting the nwkcDefaultSecurityLevel */
	unsigned char nwkcDiscoveryRetryLimit;
	unsigned char nwkcMaxDepth;
	unsigned char nwkcMinHeaderOverhead;
	unsigned char nwkcProtocolVersion;
	unsigned char nwkcRepairThreshold;
	unsigned short nwkcRouteDiscoveryTime;
	unsigned char nwkcMaxBroadcastJitter;
	unsigned char nwkcInitialRreqRetries;
	unsigned char nwkcRreqRetries;
	unsigned char nwkcRreqRetryInterval;
	unsigned char nwkcMinRreqJitter;
	unsigned char nwkcMaxRreqJitter;
	/** NWK PIB attributes */
	unsigned char nwkSequenceNumber;
	unsigned char nwkPassiveAckTimeout;
	unsigned char nwkMaxBroadcastRetries;
	unsigned char nwkMaxChildren;
	unsigned char nwkMaxDepth;
	unsigned char nwkMaxRouters;
	NeighborTableEntry* neighborTable;
	int neighborTableSize;
	unsigned char nwkNetworkBroadcastDeliveryTime;
	unsigned char nwkReportConstantCost;
	unsigned char nwkRouteDiscoveryRetriesPermitted;
	RoutingTableEntry* routingTable;
	int routingTableSize;
	bool nwkSymLink;
	NwkCapabilityInformation nwkCapabilityInformation;
	bool nwkUseTreeAddrAlloc;
	bool nwkUseTreeRouting;
	unsigned short nwkNextAddress;
	unsigned short nwkAvailableAddresses;
	unsigned short nwkAddressIncrement;
	unsigned short nwkTransactionPersistenceTime;
	/** @brief Sets the level of comments to the EV output */
	CommentsLevel commentsLevel;
	virtual void handleSelfMsg(cMessage*);
	virtual void handleNlmeMsg(cMessage*);
	virtual void sendNlme(cMessage*);
	virtual void resetNwkPibValues();
	virtual void comment(CommentsLevel level, std::string s) {
		if ((level & commentsLevel) > COMMENT_NOTHING) {
			/** @todo align logName substrings for routers and endDevices */
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
	virtual void commentError(char* errorMessage) {
		std::stringstream commentStream;
		commentStream << "ERROR: " << errorMessage;
		comment(COMMENT_ERROR, commentStream.str());
	}
public:
	NwkEnum setPibAttribute(PibIdentifier, unsigned int*);
	unsigned int* getPibAttribute(PibIdentifier);
    bool getNwkcCoordinatorCapable() const
    {
        return nwkcCoordinatorCapable;
    }

    void setNwkcCoordinatorCapable(bool nwkcCoordinatorCapable)
    {
        this->nwkcCoordinatorCapable = nwkcCoordinatorCapable;
    }

    unsigned char getNwkcDiscoveryRetryLimit() const
    {
        return nwkcDiscoveryRetryLimit;
    }

    void setNwkcDiscoveryRetryLimit(unsigned char nwkcDiscoveryRetryLimit)
    {
        this->nwkcDiscoveryRetryLimit = nwkcDiscoveryRetryLimit;
    }

    unsigned char getNwkcMaxDepth() const
    {
        return nwkcMaxDepth;
    }

    void setNwkcMaxDepth(unsigned char nwkcMaxDepth)
    {
        this->nwkcMaxDepth = nwkcMaxDepth;
    }

    unsigned char getNwkcMinHeaderOverhead() const
    {
        return nwkcMinHeaderOverhead;
    }

    void setNwkcMinHeaderOverhead(unsigned char nwkcMinHeaderOverhead)
    {
        this->nwkcMinHeaderOverhead = nwkcMinHeaderOverhead;
    }

    unsigned char getNwkcProtocolVersion() const
    {
        return nwkcProtocolVersion;
    }

    void setNwkcProtocolVersion(unsigned char nwkcProtocolVersion)
    {
        this->nwkcProtocolVersion = nwkcProtocolVersion;
    }

    unsigned char getNwkcRepairThreshold() const
    {
        return nwkcRepairThreshold;
    }

    void setNwkcRepairThreshold(unsigned char nwkcRepairThreshold)
    {
        this->nwkcRepairThreshold = nwkcRepairThreshold;
    }

    unsigned short getNwkcRouteDiscoveryTime() const
    {
        return nwkcRouteDiscoveryTime;
    }

    void setNwkcRouteDiscoveryTime(unsigned short  nwkcRouteDiscoveryTime)
    {
        this->nwkcRouteDiscoveryTime = nwkcRouteDiscoveryTime;
    }

    unsigned char getNwkcMaxBroadcastJitter() const
    {
        return nwkcMaxBroadcastJitter;
    }

    void setNwkcMaxBroadcastJitter(unsigned char nwkcMaxBroadcastJitter)
    {
        this->nwkcMaxBroadcastJitter = nwkcMaxBroadcastJitter;
    }

    unsigned char getNwkcInitialRreqRetries() const
    {
        return nwkcInitialRreqRetries;
    }

    void setNwkcInitialRreqRetries(unsigned char nwkcInitialRreqRetries)
    {
        this->nwkcInitialRreqRetries = nwkcInitialRreqRetries;
    }

    unsigned char getNwkcRreqRetries() const
    {
        return nwkcRreqRetries;
    }

    void setNwkcRreqRetries(unsigned char nwkcRreqRetries)
    {
        this->nwkcRreqRetries = nwkcRreqRetries;
    }

    unsigned char getNwkcRreqRetryInterval() const
    {
        return nwkcRreqRetryInterval;
    }

    void setNwkcRreqRetryInterval(unsigned char nwkcRreqRetryInterval)
    {
        this->nwkcRreqRetryInterval = nwkcRreqRetryInterval;
    }

    unsigned char getNwkcMinRreqJitter() const
    {
        return nwkcMinRreqJitter;
    }

    void setNwkcMinRreqJitter(unsigned char nwkcMinRreqJitter)
    {
        this->nwkcMinRreqJitter = nwkcMinRreqJitter;
    }

    unsigned char getNwkcMaxRreqJitter() const
    {
        return nwkcMaxRreqJitter;
    }

    void setNwkcMaxRreqJitter(unsigned char nwkcMaxRreqJitter)
    {
        this->nwkcMaxRreqJitter = nwkcMaxRreqJitter;
    }

    unsigned char getNwkSequenceNumber() const
    {
        return nwkSequenceNumber;
    }

    void setNwkSequenceNumber(unsigned char nwkSequenceNumber)
    {
        this->nwkSequenceNumber = nwkSequenceNumber;
    }

    unsigned char getNwkPassiveAckTimeout() const
    {
        return nwkPassiveAckTimeout;
    }

    void setNwkPassiveAckTimeout(unsigned char nwkPassiveAckTimeout)
    {
        this->nwkPassiveAckTimeout = nwkPassiveAckTimeout;
    }

    unsigned char getNwkMaxBroadcastRetries() const
    {
        return nwkMaxBroadcastRetries;
    }

    void setNwkMaxBroadcastRetries(unsigned char nwkMaxBroadcastRetries)
    {
        this->nwkMaxBroadcastRetries = nwkMaxBroadcastRetries;
    }

    unsigned char getNwkMaxChildren() const
    {
        return nwkMaxChildren;
    }

    void setNwkMaxChildren(unsigned char nwkMaxChildren)
    {
        this->nwkMaxChildren = nwkMaxChildren;
    }

    unsigned char getNwkMaxDepth() const
    {
        return nwkMaxDepth;
    }

    void setNwkMaxDepth(unsigned char nwkMaxDepth)
    {
        this->nwkMaxDepth = nwkMaxDepth;
    }

    unsigned char getNwkMaxRouters() const
    {
        return nwkMaxRouters;
    }

    void setNwkMaxRouters(unsigned char nwkMaxRouters)
    {
        this->nwkMaxRouters = nwkMaxRouters;
    }

    int getNeighborTableSize() {
    	return this->neighborTableSize;
    }

    void setNeighborTableSize(int neighborTableSize) {
    	this->neighborTableSize = neighborTableSize;
    }

    unsigned char getNwkNetworkBroadcastDeliveryTime() const
    {
        return nwkNetworkBroadcastDeliveryTime;
    }

    void setNwkNetworkBroadcastDeliveryTime(unsigned char nwkNetworkBroadcastDeliveryTime)
    {
        this->nwkNetworkBroadcastDeliveryTime = nwkNetworkBroadcastDeliveryTime;
    }

    unsigned char getNwkReportConstantCost() const
    {
        return nwkReportConstantCost;
    }

    void setNwkReportConstantCost(unsigned char nwkReportConstantCost)
    {
        this->nwkReportConstantCost = nwkReportConstantCost;
    }

    unsigned char getNwkRouteDiscoveryRetriesPermitted() const
    {
        return nwkRouteDiscoveryRetriesPermitted;
    }

    void setNwkRouteDiscoveryRetriesPermitted(unsigned char nwkRouteDiscoveryRetriesPermitted)
    {
        this->nwkRouteDiscoveryRetriesPermitted = nwkRouteDiscoveryRetriesPermitted;
    }

    int getRoutingTableSize() {
    	return this->routingTableSize;
    }

    void setRoutingTableSize(int routingTableSize) {
    	this->routingTableSize = routingTableSize;
    }

    bool getNwkSymLink() const
    {
        return nwkSymLink;
    }

    void setNwkSymLink(bool nwkSymLink)
    {
        this->nwkSymLink = nwkSymLink;
    }

    NwkCapabilityInformation getNwkCapabilityInformation() const
    {
        return nwkCapabilityInformation;
    }

    void setNwkCapabilityInformation(NwkCapabilityInformation nwkCapabilityInformation)
    {
        this->nwkCapabilityInformation = nwkCapabilityInformation;
    }

    bool getNwkUseTreeAddrAlloc() const
    {
        return nwkUseTreeAddrAlloc;
    }

    void setNwkUseTreeAddrAlloc(bool nwkUseTreeAddrAlloc)
    {
        this->nwkUseTreeAddrAlloc = nwkUseTreeAddrAlloc;
    }

    bool getNwkUseTreeRouting() const
    {
        return nwkUseTreeRouting;
    }

    void setNwkUseTreeRouting(bool nwkUseTreeRouting)
    {
        this->nwkUseTreeRouting = nwkUseTreeRouting;
    }

    unsigned short getNwkNextAddress() const
    {
        return nwkNextAddress;
    }

    void setNwkNextAddress(unsigned short  nwkNextAddress)
    {
        this->nwkNextAddress = nwkNextAddress;
    }

    unsigned short getNwkAvailableAddresses() const
    {
        return nwkAvailableAddresses;
    }

    void setNwkAvailableAddresses(unsigned short  nwkAvailableAddresses)
    {
        this->nwkAvailableAddresses = nwkAvailableAddresses;
    }

    unsigned short getNwkAddressIncrement() const
    {
        return nwkAddressIncrement;
    }

    void setNwkAddressIncrement(unsigned short  nwkAddressIncrement)
    {
        this->nwkAddressIncrement = nwkAddressIncrement;
    }

    unsigned short getNwkTransactionPersistenceTime() const
    {
        return nwkTransactionPersistenceTime;
    }

    void setNwkTransactionPersistenceTime(unsigned short  nwkTransactionPersistenceTime)
    {
        this->nwkTransactionPersistenceTime = nwkTransactionPersistenceTime;
    }

};

#endif
