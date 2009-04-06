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
	if (msg->getKind() == JOINING_PERMITTED_TIMER) {
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
	std::cout << "x" << endl;
	if (msg->getKind() == MLME_SCAN_CONFIRM) {
		std::cout << "-";
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
					for (unsigned int i = 0; i < confirm->getPanDescriptorListArraySize(); i++) {
						if (getPanId() == confirm->getPanDescriptorList(i).coordPanId) {
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
			std::cout << "2";
			NlmeNetworkDiscovery_confirm* response =
					new NlmeNetworkDiscovery_confirm(
							"NLME-NETWORK-DISCOVERY.confirm",
							NLME_NETWORK_DISCOVERY_CONFIRM);
			std::cout << "3";
			response->setNetworkCount(confirm->getResultListSize());
			std::cout << "4";
			for (unsigned int i = 0; i < confirm->getResultListSize(); i++) {
				std::cout << "A";
				NetworkDescriptor descriptor;
				std::cout << "B";
				/** @test this might try to access some restricted areas */
				descriptor.panId = confirm->getPanDescriptorList(i).coordPanId;
				std::cout << "C";
				descriptor.logicalChannel
						= confirm->getPanDescriptorList(i).logicalChannel;
				std::cout << "D";
				/** @todo include stack profile, zigbee version,  into descriptor */
				// descriptor.stackProfile =
				// descriptor.zigbeeVersion =
				descriptor.beaconOrder
						= confirm->getPanDescriptorList(i).beaconOrder;
				std::cout << "E";
				descriptor.superframeOrder
						= confirm->getPanDescriptorList(i).superframeOrder;
				std::cout << "F";
				addNetworkDescriptor(descriptor);
				std::cout << "G";
			}
			std::cout << "5";
			response->setNetworkDescriptorListArraySize(
					getNetworkDescriptorsArraySize());
			std::cout << "6";
			for (int i = 0; i < getNetworkDescriptorsArraySize(); i++) {
				std::cout << "A";
				response->setNetworkDescriptorList(i,
						getNetworkDescriptors()[i]);
			}
			std::cout << "7";
			response->setStatus(confirm->getStatus());
			std::cout << "8";
			sendNlmeUp(response);
			std::cout << "9";
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
				MlmeSet_request* setRequest = new MlmeSet_request("MLME-SET.request", MLME_SET_REQUEST);
				setRequest->setPibAttribute(MAC_BEACON_PAYLOAD);
				MacBeaconPayload payload;
				unsigned int* payloadArray;
				payloadArray = (unsigned int*) &payload;
				payload.networkAddress = 0x0000;
				payload.deviceType = getFFDAppLayer()->getRole();
				payload.rxOnWhenIdle = getMacPib()->getMacRxOnWhenIdle();
				int payloadSize = (int) (((double)sizeof(MacBeaconPayload))/((double)sizeof(unsigned int)));
				if (payloadSize * sizeof(unsigned int) < sizeof(MacBeaconPayload)) payloadSize++;
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
				/** @fixme for now, omitting the security features of the message*/
				sendMlmeDown(startRequest);
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
		MlmeBeaconNotify_indication* indication = check_and_cast<MlmeBeaconNotify_indication *>(msg);
		NeighborTableEntry neighbor;
		MacBeaconPayload* macBeaconPayload;
		unsigned int* sdu;
		sdu = new unsigned int[indication->getSduArraySize()];
		for (unsigned int i = 0; i < indication->getSduArraySize(); i++) {
			sdu[i] =  indication->getSdu(i);
		}
		macBeaconPayload = (MacBeaconPayload*) sdu;
		neighbor.networkAddress = macBeaconPayload->networkAddress;
		neighbor.deviceType = macBeaconPayload->deviceType;
		neighbor.rxOnWhenIdle = macBeaconPayload->rxOnWhenIdle;
		neighbor.relationship = OTHER;
		neighbor.depth = macBeaconPayload->depth;
		neighbor.beaconOrder = indication->getPanDescriptor().beaconOrder;
		neighbor.permitJoining = indication->getPanDescriptor().associationPermit;
		neighbor.logicalChannel = indication->getPanDescriptor().logicalChannel;
		neighbor.incomingBeaconTimestamp = 1;
		neighbor.beaconTransmissionTimeOffset = 1;
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
						JOINING_PERMITTED_TIMER);
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
		if (!request->getRejoinNetwork()) {

		} /**@todo add network rejoining procedures */
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
	unsigned char page;
	page = (unsigned char) (channels >> 26);
	return page;
}
