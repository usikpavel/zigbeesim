/* -*- mode:c++ -*- ********************************************************
 * file:        Nlme.cc
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
 * description: - Module describing the behaviour of the net management entity
 ***************************************************************************/
#include "Nlme.h"
#include <string>

Define_Module( Nlme);

void Nlme::initialize(int stage) {
	BasicModule::initialize(stage);

	if (stage == 0) {
		mlmeSapIn = findGate("mlmeSapIn");
		mlmeSapOut = findGate("mlmeSapOut");
		nlmeSapIn = findGate("nlmeSapIn");
		nlmeSapOut = findGate("nlmeSapOut");
		nldeOut = findGate("nldeOut");
		nldeIn = findGate("nldeIn");
		nwkPibIn = findGate("nwkPibIn");
		nwkPibOut = findGate("nwkPibOut");

		commentsLevel = COMMENT_ALL;
	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
		setNetworkDescriptorsArraySize(0);
		networkDescriptors = new NetworkDescriptor[0];
		if (getFFDAppLayer()->getRole() != END_DEVICE) {
			setAssociatedRouters(0);
			setAssociatedEndDevices(0);
		}
	}
}

void Nlme::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == mlmeSapIn) {
		handleMlmeMsg(msg);
	} else if (msg->getArrivalGateId() == nlmeSapIn) {
		handleNlmeMsg(msg);
	} else if (msg->getArrivalGateId() == nldeIn) {
		handleNlmeMsg(msg);
	} else if (msg->getArrivalGateId() == nwkPibIn) {
		handleNwkPibMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void Nlme::handleSelfMsg(cMessage *msg) {
	if (msg->getKind() == TIMER_JOINING_PERMITTED) {
		setLastUpperMsg(msg);
		MlmeSet_request* response = new MlmeSet_request("MLME-SET.request",
				MLME_SET_REQUEST);
		response->setPibAttribute(MAC_ASSOCIATION_PERMIT);
		response->setPibAttributeValueArraySize(1);
		response->setPibAttributeValue(0, (unsigned int) false);
		sendMlmeDown(response);
	}
}

void Nlme::handleMlmeMsg(cMessage *msg) {
	if (msg->getKind() == MLME_SCAN_CONFIRM) {
		MlmeScan_confirm* confirm = check_and_cast<MlmeScan_confirm *> (msg);
		if (getLastUpperMsg()->getKind() == NLME_NETWORK_FORMATION_REQUEST) {
			NlmeNetworkFormation_request* request = check_and_cast<
					NlmeNetworkFormation_request *> (getLastUpperMsg());
			if (confirm->getStatus() == MAC_SUCCESS) {
				if (confirm->getScanType() == ED_SCAN) {
					MlmeScan_request* scan = new MlmeScan_request();
					scan->setName("MLME-SCAN.request");
					scan->setKind(MLME_SCAN_REQUEST);
					scan->setScanType(ACTIVE_SCAN);
					scan->setScanChannels(request->getScanChannels());
					scan->setScanDuration(request->getScanDuration());
					scan->setChannelPage(request->getScanChannels() >> 28);
					sendMlmeDown(scan);
				} else if (confirm->getScanType() == ACTIVE_SCAN) {
					/** @comment we'll try to use the PAN ID provided by the application layer, if possible */
					bool idOk = true;
					setPanId(request->getPANId());
					for (unsigned int i = 0; i
							< confirm->getPanDescriptorListArraySize(); i++) {
						if (getPanId()
								== confirm->getPanDescriptorList(i).coordPanId) {
							idOk = false;
						}
					}
					/** @comment otherwise we'll find not used PAN ID from the scan and save it for a future use (in case we're the coordinator)*/
					while (!idOk) {
						setPanId((unsigned short) (rand() % 0x00004000));
						for (unsigned int i = 0; i
								< confirm->getPanDescriptorListArraySize(); i++) {
							if (getPanId()
									== confirm->getPanDescriptorList(i).coordPanId) {
								idOk = false;
							}
						}
					}
					MlmeSet_request* setRequest = new MlmeSet_request(
							"MLME-SET.request", MLME_SET_REQUEST);
					setRequest->setPibAttribute(PHY_CURRENT_CHANNEL);
					setRequest->setPibAttributeValueArraySize(1);
					/** @todo here we should select a channel according to some better formula */
					unsigned int acceptableChannels =
							confirm->getUnscannedChannels()
									^ request->getScanChannels();
					do {
						setLogicalChannel((unsigned char) (rand() % 28));
					} while (((acceptableChannels >> getLogicalChannel())
							& 0x00000001) != 0x00000001);
					setRequest->setPibAttributeValue(0, getLogicalChannel());
					sendMlmeDown(setRequest);
				}
			}
		} else if (getLastUpperMsg()->getKind()
				== NLME_NETWORK_DISCOVERY_REQUEST) {
			NlmeNetworkDiscovery_confirm* response =
					new NlmeNetworkDiscovery_confirm(
							"NLME-NETWORK-DISCOVERY.confirm",
							NLME_NETWORK_DISCOVERY_CONFIRM);
			response->setNetworkCount(confirm->getResultListSize());
			for (unsigned int i = 0; i < confirm->getResultListSize(); i++) {
				NetworkDescriptor descriptor;
				descriptor.panId = confirm->getPanDescriptorList(i).coordPanId;
				descriptor.logicalChannel
						= confirm->getPanDescriptorList(i).logicalChannel;
				/** @TODO include stack profile, zigbee version,  into descriptor */
				// descriptor.stackProfile =
				// descriptor.zigbeeVersion =
				descriptor.beaconOrder
						= confirm->getPanDescriptorList(i).beaconOrder;
				descriptor.superframeOrder
						= confirm->getPanDescriptorList(i).superframeOrder;
				addNetworkDescriptor(descriptor);
			}
			response->setNetworkDescriptorListArraySize(
					getNetworkDescriptorsArraySize());
			for (int i = 0; i < getNetworkDescriptorsArraySize(); i++) {
				response->setNetworkDescriptorList(i,
						getNetworkDescriptors()[i]);
			}
			response->setStatus(confirm->getStatus());
			sendNlmeUp(response);
		}
	} else if (msg->getKind() == MLME_SET_CONFIRM) {
		MlmeSet_confirm* confirm = check_and_cast<MlmeSet_confirm *> (msg);
		if (getLastUpperMsg()->getKind() == NLME_NETWORK_FORMATION_REQUEST) {
			NlmeNetworkFormation_request* request = check_and_cast<
					NlmeNetworkFormation_request *> (getLastUpperMsg());
			if (confirm->getPibAttribute() == PHY_CURRENT_CHANNEL) {
				MlmeSet_request* setRequest = new MlmeSet_request(
						"MLME-SET.request", MLME_SET_REQUEST);
				setRequest->setPibAttribute(MAC_PAN_ID);
				setRequest->setPibAttributeValueArraySize(1);
				setRequest->setPibAttributeValue(0, getPanId());
				sendMlmeDown(setRequest);
			} else if (confirm->getPibAttribute() == MAC_PAN_ID) {
				MlmeSet_request* setRequest = new MlmeSet_request(
						"MLME-SET.request", MLME_SET_REQUEST);
				setRequest->setPibAttribute(MAC_SHORT_ADDRESS);
				setRequest->setPibAttributeValueArraySize(1);
				setRequest->setPibAttributeValue(0, 0x0000);
				sendMlmeDown(setRequest);
			} else if (confirm->getPibAttribute() == MAC_SHORT_ADDRESS) {
				MlmeSet_request* setRequest = new MlmeSet_request(
						"MLME-SET.request", MLME_SET_REQUEST);
				setRequest->setPibAttribute(MAC_BEACON_PAYLOAD);
				MacBeaconPayload payload;
				unsigned int* payloadArray;
				payloadArray = (unsigned int*) &payload;
				payload.networkAddress = 0x0000;
				payload.deviceType = getFFDAppLayer()->getRole();
				payload.rxOnWhenIdle = getMacPib()->getMacRxOnWhenIdle();
				payload.depth = 0x00;
				/** @comment Coordinator has no beacon time offset */
				payload.beaconTimestamp = 0x00000000;
				payload.beaconTransmissionTimeOffset = 0x00000000;
				int payloadSize = (int) (((double) sizeof(MacBeaconPayload))
						/ ((double) sizeof(unsigned int)));
				if (payloadSize * sizeof(unsigned int)
						< sizeof(MacBeaconPayload))
					payloadSize++;
				setRequest->setPibAttributeValueArraySize(payloadSize);
				for (int i = 0; i < payloadSize; i++) {
					setRequest->setPibAttributeValue(i, payloadArray[i]);
				}
				sendMlmeDown(setRequest);
			} else if (confirm->getPibAttribute() == MAC_BEACON_PAYLOAD) {
				MlmeStart_request* startRequest = new MlmeStart_request(
						"MLME-START.request", MLME_START_REQUEST);
				startRequest->setPanId(getPanId());
				startRequest->setLogicalChannel(getLogicalChannel());
				startRequest->setChannelPage(getChannelPageFromChannels(
						request->getScanChannels()));
				startRequest->setStartTime(rand());
				startRequest->setBeaconOrder(request->getBeaconOrder());
				startRequest->setSuperframeOrder(request->getSuperframeOrder());
				startRequest->setPanCoordinator((logName().substr(0, 11)
						== "coordinator"));
				startRequest->setBatteryLifeExtension(false);
				startRequest->setCoordRealignment(false);
				startRequest->setCoordRealignKeySourceArraySize(0);
				startRequest->setBeaconKeySourceArraySize(0);
				/** @fixme for now, omitting the security features of the message*/
				sendMlmeDown(startRequest);
				/** @note this is the best time to prepare cskip for distributing addresses */
				setCskip(calculateCskip());
			} else if (confirm->getPibAttribute() == MAC_ASSOCIATION_PERMIT) {
				/** @comment no actions needed, the upper layer has already been notified */
			}
		} else if (getLastUpperMsg()->getKind() == NLME_PERMIT_JOINING_REQUEST) {
			NlmePermitJoining_confirm* response =
					new NlmePermitJoining_confirm(
							"NLME-PERMIT-JOINING.confirm",
							NLME_PERMIT_JOINING_CONFIRM);
			response->setStatus(confirm->getStatus());
			sendNlmeUp(response);
		}
	} else if (msg->getKind() == MLME_START_CONFIRM) {
		MlmeStart_confirm* confirm = check_and_cast<MlmeStart_confirm *> (msg);
		NlmeNetworkFormation_confirm* response =
				new NlmeNetworkFormation_confirm(
						"NLME-NETWORK-FORMATION.confirm",
						NLME_NETWORK_FORMATION_CONFIRM);
		/** @note here we play with the MAC status still */
		response->setStatus(confirm->getStatus());
		sendNlmeUp(response);
	} else if (msg->getKind() == MLME_BEACON_NOTIFY_INDICATION) {
		MlmeBeaconNotify_indication* indication = check_and_cast<
				MlmeBeaconNotify_indication *> (msg);
		NeighborTableEntry neighbor;
		MacBeaconPayload * macBeaconPayload;
		unsigned int* sdu;
		sdu = new unsigned int[indication->getSduArraySize()];
		for (unsigned int i = 0; i < indication->getSduArraySize(); i++) {
			sdu[i] = indication->getSdu(i);
		}
		macBeaconPayload = (MacBeaconPayload*) sdu;
		neighbor.panId = indication->getPanDescriptor().coordPanId;
		neighbor.extendedAddress
				= getMcps()->getLastLowerMsg()->getSourceAddress();
		neighbor.networkAddress = macBeaconPayload->networkAddress;
		neighbor.deviceType = macBeaconPayload->deviceType;
		neighbor.rxOnWhenIdle = macBeaconPayload->rxOnWhenIdle;
		neighbor.relationship = OTHER;
		neighbor.depth = macBeaconPayload->depth;
		neighbor.beaconOrder = indication->getPanDescriptor().beaconOrder;
		neighbor.permitJoining
				= indication->getPanDescriptor().associationPermit;
		neighbor.logicalChannel = indication->getPanDescriptor().logicalChannel;
		neighbor.incomingBeaconTimestamp = macBeaconPayload->beaconTimestamp;
		neighbor.beaconTransmissionTimeOffset
				= macBeaconPayload->beaconTransmissionTimeOffset;
		addNeighborTableEntry(neighbor);
	} else if (msg->getKind() == MLME_ASSOCIATE_INDICATION) {
		MlmeAssociate_indication* indication = check_and_cast<
				MlmeAssociate_indication *> (msg);
		MlmeAssociate_response* response = new MlmeAssociate_response(
				"MLME-ASSOCIATE.response", MLME_ASSOCIATE_RESPONSE);
		response->setDeviceAddress(indication->getDeviceAddress());
		/** @COMMENT let's determine whether there's a space for the device association
		 * if the device wants to join as router, check whether we can associate more routers */
		if ((getNwkPib()->getNwkMaxChildren() == getAssociatedRouters()
				+ getAssociatedEndDevices()) || (indication->getDeviceType()
				== ROUTER && getNwkPib()->getNwkMaxRouters()
				== getAssociatedRouters())) {
			response->setStatus(PAN_AT_CAPACITY);
			sendMlmeDown(response);
			delete (msg);
			return;
		}
		if (hasNeighborTableEntry(indication->getDeviceAddress())) {
			NeighborTableEntry entry = getNeighborTableEntry(
					indication->getDeviceAddress());
			/** @TODO check the device capabilities. if they differ, update */
		} else {
			/** @COMMENT the device is not in the neighbor table. add it */
			NeighborTableEntry entry;
			entry.panId = getMacPib()->getMacPANId();
			entry.extendedAddress = indication->getDeviceAddress();
			entry.deviceType = indication->getDeviceType();
			entry.rxOnWhenIdle = indication->getReceiverOnWhenIdle();
			addNeighborTableEntry(entry);
		}
		NeighborTableEntry entry = getNeighborTableEntry(
				indication->getDeviceAddress());
		deleteNeighborTableEntry(indication->getDeviceAddress());
		if (indication->getAllocateAddress())
			/** @comment transformation between deviceType 0x00 (COORDINATOR) - 0x02 (END DEVICE)
			 * into the deviceType bool true (FFD) and false (RFD) */
			entry.networkAddress = assignNetworkAddress(
					indication->getDeviceType() == ROUTER);
		else
			/** @note with this network address the device is forced to use the IEEE 64-bit address */
			entry.networkAddress = 0xFFFE;
		entry.beaconOrder = getMacPib()->getMacBeaconOrder();
		entry.relationship = CHILD;
		entry.depth = getDepth() + 1;
		entry.potentialParent = false;
		addNeighborTableEntry(entry);
		response->setAssocShortAddress(entry.networkAddress);
		response->setStatus(ASSOCIATION_SUCCESSFUL);
		response->setSecurityLevel(0x00);
		if (indication->getDeviceType() == ROUTER)
			setAssociatedRouters(getAssociatedRouters() + 1);
		else
			setAssociatedEndDevices(getAssociatedEndDevices() + 1);
		sendMlmeDown(response);
	}
	delete (msg);
}

void Nlme::handleNlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg);
	if (msg->getKind() == NLME_NETWORK_FORMATION_REQUEST) {
		NlmeNetworkFormation_request* request = check_and_cast<
				NlmeNetworkFormation_request *> (msg);
		setDepth(0x00);
		MlmeScan_request* scan = new MlmeScan_request("MLME-SCAN.request",
				MLME_SCAN_REQUEST);
		scan->setScanType(ED_SCAN);
		scan->setScanChannels(request->getScanChannels());
		scan->setScanDuration(request->getScanDuration());
		sendMlmeDown(scan);
	} else if (msg->getKind() == NLME_PERMIT_JOINING_REQUEST) {
		NlmePermitJoining_request *request = check_and_cast<
				NlmePermitJoining_request *> (msg);
		MlmeSet_request* response = new MlmeSet_request("MLME-SET.request",
				MLME_SET_REQUEST);
		response->setPibAttribute(MAC_ASSOCIATION_PERMIT);
		response->setPibAttributeValueArraySize(1);
		if (request->getPermitDuration() == 0x00) {
			response->setPibAttributeValue(0, (unsigned int) false);
		} else {
			response->setPibAttributeValue(0, (unsigned int) true);
			if (request->getPermitDuration() != 0xFF) {
				cMessage* timer = new cMessage("JOINING-PERMITTED.timer",
						TIMER_JOINING_PERMITTED);
				scheduleAt(simTime() + (double) (request->getPermitDuration()),
						timer);
			}
		}
		sendMlmeDown(response);
	} else if (msg->getKind() == NLME_NETWORK_DISCOVERY_REQUEST) {
		NlmeNetworkDiscovery_request* request = check_and_cast<
				NlmeNetworkDiscovery_request *> (msg);
		MlmeScan_request* scan = new MlmeScan_request("MLME-SCAN.request",
				MLME_SCAN_REQUEST);
		FFDAppLayer
				*appLayer =
						(FFDAppLayer *) (getParentModule()->getParentModule()->getModuleByRelativePath(
								"app"));
		if (appLayer->getRole() == ROUTER) {
			scan->setScanType(ACTIVE_SCAN);
		} else {
			/** @todo implement passive scan at the mlme layer */
			scan->setScanType(PASSIVE_SCAN);
		}
		scan->setScanChannels(request->getScanChannels());
		scan->setScanDuration(request->getScanDuration());
		scan->setChannelPage(request->getScanChannels() >> 28);
		sendMlmeDown(scan);
	} else if (msg->getKind() == NLME_JOIN_REQUEST) {
		NlmeJoin_request* request = check_and_cast<NlmeJoin_request *> (msg);
		/** @COMMENT check whether we're already associated */
		if (getMacPib()->getMacAssociatedPANCoord()) {
			NlmeJoin_confirm* confirm = new NlmeJoin_confirm(
					"NLME-JOIN.confirm", NLME_JOIN_CONFIRM);
			confirm->setStatus(NWK_INVALID_REQUEST);
			sendNlmeUp(confirm);
			return;
		}
		if (request->getRejoinNetwork()) {
			/** @TODO add network rejoining procedures */
		} else {
			NeighborTableEntry parent;
			parent = findRouterForJoining(request->getPanId());
			NwkCapabilityInformation capability;
			capability.alternatePanCoordinator = false;
			if (request->getJoinAsRouter()) {
				capability.deviceType = ROUTER;
			} else {
				capability.deviceType = END_DEVICE;
			}
			capability.powerSource = request->getPowerSource();
			capability.receiverOnWhenIdle = request->getRxOnWhenIdle();
			capability.securityCapability = false;
			capability.allocateAddress = true;
			getNwkPib()->setNwkCapabilityInformation(capability);
			MlmeAssociate_request* associate = new MlmeAssociate_request(
					"MLME-ASSOCIATE.request", MLME_ASSOCIATE_REQUEST);
			associate->setLogicalChannel(parent.logicalChannel);
			/** @TODO set channel page */
			associate->setCoordAddrMode(LONG_ADDRESS);
			associate->setCoordPanId(parent.panId);
			associate->setCoordAddress(parent.extendedAddress);
			associate->setAlternatePanCoordinator(
					capability.alternatePanCoordinator);
			associate->setDeviceType(capability.deviceType);
			associate->setPowerSource(capability.powerSource);
			associate->setReceiverOnWhenIdle(capability.receiverOnWhenIdle);
			associate->setSecurityCapability(capability.securityCapability);
			associate->setAllocateAddress(capability.allocateAddress);
			associate->setSecurityLevel(0x00);
			associate->setKeySourceArraySize(0);
			/** @TODO this should be interchangeable with SHORT_ADDRESS */
			getMcps()->getNextEncapsulation()->destinationAddressingMode
					= LONG_ADDRESS;
			getMcps()->getNextEncapsulation()->destinationAddress
					= parent.extendedAddress;
			getMcps()->getNextEncapsulation()->destinationPanIdentifier
					= parent.panId;
			sendMlmeDown(associate);
		}
	}
}

void Nlme::handleNwkPibMsg(cMessage *msg) {
	delete (msg);
}

void Nlme::handleNldeMsg(cMessage *msg) {
	delete (msg);
}

void Nlme::sendMlmeDown(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, mlmeSapOut);
}

void Nlme::sendNlmeUp(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, nlmeSapOut);
}

void Nlme::sendNlde(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, nldeOut);
}

void Nlme::sendNwkPib(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, nwkPibOut);
}

unsigned char Nlme::getChannelPageFromChannels(unsigned int channels) {
	return (unsigned char) (channels >> 26);
}

unsigned short Nlme::assignNetworkAddress(bool deviceType) {
	int rm = getNwkPib()->getNwkMaxRouters();

	/** deviceType true -> FFD, false -> RFD*/
	if (deviceType) {
		return getNetworkAddress() + getCskip() * getAssociatedRouters() + 1;
	} else {
		return getNetworkAddress() + getCskip() * rm
				+ getAssociatedEndDevices() + 1;
	}
	return 0xFFFE;
}

unsigned short Nlme::calculateCskip() {

	int rm = getNwkPib()->getNwkMaxRouters();
	int cm = getNwkPib()->getNwkMaxChildren();
	int lm = getNwkPib()->getNwkMaxDepth();
	int d = getDepth();
	int cskip;

	if (lm == d)
		return 0;

	if (rm == 1) {
		cskip = 1 + cm * (lm - d - 1);
	} else {
		cskip = (1 + cm - rm - (cm * ((int) power(rm, (lm - d - 1))))) / (1
				- rm);
	}
	return cskip;
}

double Nlme::power(int a, int b) {
	double result = 1.0;
	if (b >= 0) {
		for (int i = 0; i < b; i++) {
			result *= a;
		}
	} else {
		for (int i = 0; i > b; i--) {
			result /= a;
		}
	}
	return result;
}

Nlme::~Nlme(){
	delete (lastUpperMsg);
	delete (networkDescriptors);

};
