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
	setNwkNetworkBroadcastDeliveryTime(getNwkPassiveAckTimeout()
			* getNwkMaxBroadcastRetries());
	setNwkReportConstantCost(0x00);
	setNwkRouteDiscoveryRetriesPermitted(getNwkcDiscoveryRetryLimit());
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
	setNwkAvailableAddress(0x0000);
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
		setNwkNextAddresses(value[0]);
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
		status = MAC_READ_ONLY;
	}
	return status;
}

