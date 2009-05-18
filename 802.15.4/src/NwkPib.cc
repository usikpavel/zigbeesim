/* -*- mode:c++ -*- ********************************************************
 * file:        NwkPib.cc
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
#include "NwkPib.h"

Define_Module( NwkPib);

void NwkPib::initialize(int stage) {
	BasicModule::initialize(stage);
	if (stage == 0) {
		nlmeOut = findGate("nlmeOut");
		nlmeIn = findGate("nlmeIn");

		resetNwkPibValues();
		commentsLevel = COMMENT_ALL;
	}
}

void NwkPib::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == nlmeIn) {
		handleNlmeMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void NwkPib::handleSelfMsg(cMessage *msg) {
	delete (msg);
}

void NwkPib::handleNlmeMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	delete (msg);
}

void NwkPib::sendNlme(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, nlmeOut);
}

void NwkPib::resetNwkPibValues() {
	setNwkcCoordinatorCapable(
			((FFDAppLayer *) (this->getParentModule()->getParentModule()->getModuleByRelativePath(
					"app")))->getRole() == COORDINATOR);
	setNwkcDiscoveryRetryLimit(0x03);
	setNwkcMaxDepth(0x0F);
	setNwkcMinHeaderOverhead(0x08);
	setNwkcProtocolVersion(0x01);
	setNwkcRepairThreshold(0x03);
	setNwkcRouteDiscoveryTime(0x2710);
	setNwkcMaxBroadcastJitter(0x40);
	setNwkcInitialRreqRetries(0x03);
	setNwkcRreqRetries(0x02);
	setNwkcRreqRetryInterval(0xFE);
	setNwkcMinRreqJitter(0x01);
	setNwkcMaxRreqJitter(0x40);
	setNwkSequenceNumber((unsigned char) (rand() % 256));
	setNwkPassiveAckTimeout(0x03);
	setNwkMaxBroadcastRetries(0x03);
	setNwkMaxChildren(0x07);
	setNwkMaxDepth(0x05);
	setNwkMaxRouters(0x05);
	neighborTable = new NeighborTableEntry[0];
	setNeighborTableSize(0);
	setNwkNetworkBroadcastDeliveryTime(getNwkPassiveAckTimeout()
			* getNwkMaxBroadcastRetries());
	setNwkReportConstantCost(0x00);
	setNwkRouteDiscoveryRetriesPermitted(getNwkcDiscoveryRetryLimit());
	routingTable = new RoutingTableEntry[0];
	setRoutingTableSize(0);
	setNwkSymLink(false);
	NwkCapabilityInformation nci;
	nci.alternatePanCoordinator = 0x00;
	nci.deviceType = 0x00;
	nci.powerSource = 0x00;
	nci.receiverOnWhenIdle = 0x00;
	nci.securityCapability = 0x00;
	nci.allocateAddress = 0x00;
	setNwkCapabilityInformation(nci);
	setNwkUseTreeAddrAlloc(true);
	setNwkUseTreeRouting(true);
	setNwkNextAddress(0x0000);
	setNwkAvailableAddresses(0x0000);
	setNwkAddressIncrement(0x0001);
	setNwkTransactionPersistenceTime(0x01f4);
}

NwkEnum NwkPib::setPibAttribute(PibIdentifier attribute, unsigned int* value) {
	NwkEnum status = NWK_SUCCESS;
	switch (attribute) {
	case NWK_SEQUENCE_NUMBER:
		setNwkSequenceNumber(value[0]);
		break;
	case NWK_PASSIVE_ACK_TIMEOUT:
		if (value[0] > 0x0A)
			return NWK_INVALID_PARAMETER;
		setNwkPassiveAckTimeout(value[0]);
		break;
	case NWK_MAX_BROADCAST_RETRIES:
		if (value[0] > 0x05)
			return NWK_INVALID_PARAMETER;
		setNwkMaxBroadcastRetries(value[0]);
		break;
	case NWK_MAX_CHILDREN:
		setNwkMaxChildren(value[0]);
		break;
	case NWK_MAX_DEPTH:
		if (value[0] > getNwkcMaxDepth())
			return NWK_INVALID_PARAMETER;
		setNwkMaxDepth(value[0]);
		break;
	case NWK_MAX_ROUTERS:
		setNwkMaxRouters(value[0]);
		break;
	case NWK_NETWORK_BROADCAST_DELIVERY_TIME:
		if (value[0]
				< (getNwkPassiveAckTimeout() * getNwkMaxBroadcastRetries())
				|| value[0] > 0xFF)
			return NWK_INVALID_PARAMETER;
		setNwkNetworkBroadcastDeliveryTime(value[0]);
		break;
	case NWK_REPORT_CONSTANT_COST:
		if (value[0] > 0x01)
			return NWK_INVALID_PARAMETER;
		setNwkReportConstantCost(value[0]);
		break;
	case NWK_ROUTE_DISCOVERY_RETRIES_PERMITTED:
		if (value[0] > 0x03)
			return NWK_INVALID_PARAMETER;
		setNwkRouteDiscoveryRetriesPermitted(value[0]);
		break;
	case NWK_SYM_LINK:
		if (value[0] > 0x01)
			return NWK_INVALID_PARAMETER;
		setNwkSymLink(value[0]);
		break;
	case NWK_CAPABILITY_INFORMATION:
		NwkCapabilityInformation nci;
		nci.alternatePanCoordinator = value[0] & 0x01;
		nci.deviceType = (value[0] & 0x02) >> 1;
		nci.powerSource = (value[0] & 0x04) >> 2;
		nci.receiverOnWhenIdle = (value[0] & 0x08) >> 3;
		nci.securityCapability = (value[0] & 0x40) >> 6;
		nci.allocateAddress = (value[0] & 0x80) >> 7;
		setNwkCapabilityInformation(nci);
		break;
	case NWK_USE_TREE_ADDR_ALLOC:
		if (value[0] > 0x01)
			return NWK_INVALID_PARAMETER;
		setNwkUseTreeAddrAlloc(value[0]);
		break;
	case NWK_USE_TREE_ROUTING:
		if (value[0] > 0x01)
			return NWK_INVALID_PARAMETER;
		setNwkUseTreeRouting(value[0]);
		break;
	case NWK_NEXT_ADDRESS:
		if (value[0] > 0xFFFD)
			return NWK_INVALID_PARAMETER;
		setNwkNextAddress(value[0]);
		break;
	case NWK_AVAILABLE_ADDRESSES:
		if (value[0] > 0xFFFD)
			return NWK_INVALID_PARAMETER;
		setNwkAvailableAddresses(value[0]);
		break;
	case NWK_ADDRESS_INCREMENT:
		if (value[0] > 0xFFFD)
			return NWK_INVALID_PARAMETER;
		setNwkAddressIncrement(value[0]);
		break;
	case NWK_TRANSACTION_PERSISTENCE_TIME:
		if (value[0] > 0xFFFF)
			return NWK_INVALID_PARAMETER;
		setNwkTransactionPersistenceTime(value[0]);
		break;
	default:
		status = NWK_NOT_PERMITTED;
	}
	return status;
}

unsigned int* NwkPib::getPibAttribute(PibIdentifier attribute) {
	unsigned int* value;
	switch (attribute) {
	case NWKC_COORDINATOR_CAPABLE:
		value = new unsigned int[1];
		value[0] = getNwkcCoordinatorCapable();
		break;
	case NWKC_DISCOVERY_RETRY_LIMIT:
		value = new unsigned int[1];
		value[0] = getNwkcDiscoveryRetryLimit();
		break;
	case NWKC_MAX_DEPTH:
		value = new unsigned int[1];
		value[0] = getNwkcMaxDepth();
		break;
	case NWKC_MIN_HEADER_OVERHEAD:
		value = new unsigned int[1];
		value[0] = getNwkcMinHeaderOverhead();
		break;
	case NWKC_PROTOCOL_VERSION:
		value = new unsigned int[1];
		value[0] = getNwkcProtocolVersion();
		break;
	case NWKC_REPAIR_THRESHOLD:
		value = new unsigned int[1];
		value[0] = getNwkcRepairThreshold();
		break;
	case NWKC_ROUTE_DISCOVERY_TIME:
		value = new unsigned int[1];
		value[0] = getNwkcRouteDiscoveryTime();
		break;
	case NWKC_MAX_BROADCAST_JITTER:
		value = new unsigned int[1];
		value[0] = getNwkcMaxBroadcastJitter();
		break;
	case NWKC_INITIAL_RREQ_RETRIES:
		value = new unsigned int[1];
		value[0] = getNwkcInitialRreqRetries();
		break;
	case NWKC_RREQ_RETRIES:
		value = new unsigned int[1];
		value[0] = getNwkcRreqRetries();
		break;
	case NWKC_RREQ_RETRY_INTERVAL:
		value = new unsigned int[1];
		value[0] = getNwkcRreqRetryInterval();
		break;
	case NWKC_MIN_RREQ_JITTER:
		value = new unsigned int[1];
		value[0] = getNwkcMinRreqJitter();
		break;
	case NWKC_MAX_RREQ_JITTER:
		value = new unsigned int[1];
		value[0] = getNwkcMaxRreqJitter();
		break;
	case NWK_SEQUENCE_NUMBER:
		value = new unsigned int[1];
		value[0] = getNwkSequenceNumber();
		break;
	case NWK_PASSIVE_ACK_TIMEOUT:
		value = new unsigned int[1];
		value[0] = getNwkPassiveAckTimeout();
		break;
	case NWK_MAX_BROADCAST_RETRIES:
		value = new unsigned int[1];
		value[0] = getNwkMaxBroadcastRetries();
		break;
	case NWK_MAX_CHILDREN:
		value = new unsigned int[1];
		value[0] = getNwkMaxChildren();
		break;
	case NWK_MAX_DEPTH:
		value = new unsigned int[1];
		value[0] = getNwkMaxDepth();
		break;
	case NWK_MAX_ROUTERS:
		value = new unsigned int[1];
		value[0] = getNwkMaxRouters();
		break;
	case NWK_NEIGHBOR_TABLE:
		break;
	case NWK_NETWORK_BROADCAST_DELIVERY_TIME:
		value = new unsigned int[1];
		value[0] = getNwkNetworkBroadcastDeliveryTime();
		break;
	case NWK_REPORT_CONSTANT_COST:
		value = new unsigned int[1];
		value[0] = getNwkReportConstantCost();
		break;
	case NWK_ROUTE_DISCOVERY_RETRIES_PERMITTED:
		value = new unsigned int[1];
		value[0] = getNwkRouteDiscoveryRetriesPermitted();
	case NWK_ROUTE_TABLE:
		break;
	case NWK_SYM_LINK:
		value = new unsigned int[1];
		value[0] = getNwkSymLink();
		break;
	case NWK_CAPABILITY_INFORMATION:
		NwkCapabilityInformation nci;
		nci = getNwkCapabilityInformation();
		value = new unsigned int[1];
		value[0] = 0x00000000;
		if (nci.alternatePanCoordinator) value[0] += 0x01;
		if (nci.deviceType) value[0] += 0x02;
		if (nci.powerSource) value[0] += 0x04;
		if (nci.receiverOnWhenIdle) value[0] += 0x08;
		if (nci.securityCapability) value[0] += 0x40;
		if (nci.allocateAddress) value[0] += 0x80;
		break;
	case NWK_USE_TREE_ADDR_ALLOC:
		value = new unsigned int[1];
		value[0] = getNwkUseTreeAddrAlloc();
		break;
	case NWK_USE_TREE_ROUTING:
		value = new unsigned int[1];
		value[0] = getNwkUseTreeRouting();
		break;
	case NWK_NEXT_ADDRESS:
		value = new unsigned int[1];
		value[0] = getNwkNextAddress();
		break;
	case NWK_AVAILABLE_ADDRESSES:
		value = new unsigned int[1];
		value[0] = getNwkAvailableAddresses();
		break;
	case NWK_ADDRESS_INCREMENT:
		value = new unsigned int[1];
		value[0] = getNwkAddressIncrement();
		break;
	case NWK_TRANSACTION_PERSISTENCE_TIME:
		value = new unsigned int[1];
		value[0] = getNwkTransactionPersistenceTime();
		break;
	default:
		commentError("UNKNOWN PARAMETER IN NwkPib::getPIBAttribute()");
	}
	return value;
}
