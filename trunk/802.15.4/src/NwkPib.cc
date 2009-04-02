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
	setNwkSequenceNumber((unsigned char)(rand()%256));
	setNwkPassiveAckTimeout(0x03);
	setNwkMaxBroadcastRetries(0x03);
	setNwkMaxChildren(0x07);
	setNwkMaxDepth(0x05);
	setNwkMaxRouters(0x05);
	setNwkNetworkBroadcastDeliveryTime(getNwkPassiveAckTimeout()*getNwkMaxBroadcastRetries());
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
