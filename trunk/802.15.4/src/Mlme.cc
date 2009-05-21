/* -*- mode:c++ -*- ********************************************************
 * file:        Mlme.cc
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
 * description: - Module describing the behavior of the mac management entity
 ***************************************************************************/
#include "Mlme.h"

Define_Module( Mlme);

void Mlme::initialize(int stage) {
	BasicModule::initialize(stage);

	if (stage == 0) {
		plmeSapOut = findGate("plmeSapOut");
		plmeSapIn = findGate("plmeSapIn");
		mlmeSapOut = findGate("mlmeSapOut");
		mlmeSapIn = findGate("mlmeSapIn");
		macPibOut = findGate("macPibOut");
		macPibIn = findGate("macPibIn");
		mcpsOut = findGate("mcpsOut");
		mcpsIn = findGate("mcpsIn");

		commentsLevel = COMMENT_ALL;
		if (logName().substr(0, 11) == "coordinator") {
			setRole(COORDINATOR);
		}
	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
		lastBeacon = new MacBeacon();
		timer = new cMessage("timer");
		beaconTimer = new cMessage("Beacon timer", TIMER_BEACON);
		backoffTimer = new cMessage("Backoff timer", TIMER_BACKOFF);
		capSlotTimer = new cMessage("CAP slot timer", TIMER_CAP_SLOT);
		superframeTimer = new cMessage("Superframe timer", TIMER_SUPERFRAME);
		dataRequestTimer = new cMessage("Data request timer",
				TIMER_DATA_REQUEST);
		timeoutMsg = new cMessage("", DUMMY_MSG);
		setBackoffPeriod((SimTime) 0.0);
		setBackoffExponent(getMacPib()->getMacMinBE());
		setNumberOfBackoffs(0);
		setScannedChannels(0);
		energyLevels = new char[32];
		scannedPanDescriptors = new PanDescriptor[0];
		setDataRequestScheduled(false);
	}
}

void Mlme::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == plmeSapIn) {
		handlePlmeMsg(msg);
	} else if (msg->getArrivalGateId() == mlmeSapIn) {
		handleMlmeMsg(msg);
	} else if (msg->getArrivalGateId() == macPibIn) {
		handleMacPibMsg(msg);
	} else if (msg->getArrivalGateId() == mcpsIn) {
		handleMcpsMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void Mlme::handleSelfMsg(cMessage *msg) {
	if (msg->getKind() == TIMER_ED_SCAN) {
		return;
	} else if (msg->getKind() == TIMER_ACTIVE_SCAN) {
		setCurrentChannel(getCurrentChannel() + 1);
		MlmeScan_request* request = check_and_cast<MlmeScan_request *> (
				getLastUpperMsg());
		PlmeSetTrxState_request* changeState = new PlmeSetTrxState_request(
				"PLME-SET-TRX-STATE.request", PLME_SET_TRX_STATE_REQUEST);
		if ((request->getScanChannels() >> getCurrentChannel()) > 0x00000000) {
			/** @comment continue with the active scan */
			changeState->setState(PHY_TX_ON);
		} else {
			/** @comment active scan finished */
			/** turning radio off */
			changeState->setState(PHY_TRX_OFF);
			setLayerStage(2);
		}
		sendPlmeDown(changeState);
	} else if (msg->getKind() == TIMER_BEACON) {
		/** @todo better to put into some method the beacon creation */
		MacBeacon* beacon = new MacBeacon("Beacon Command", MAC_BEACON_FRAME);
		beacon->setBeaconOrder(getMacPib()->getMacBeaconOrder());
		beacon->setSuperframeOrder(getMacPib()->getMacSuperframeOrder());
		/** @todo set FinalCapSlot according to GTS request */
		beacon->setFinalCapSlot(16);
		beacon->setBatteryLifeExtension(false);
		beacon->setPanCoordinator(getRole() == COORDINATOR);
		beacon->setAssociationPermit(getMacPib()->getMacAssociationPermit());
		beacon->setGtsDescriptorCount(0);
		beacon->setGtsPermit(getMacPib()->getMacGTSPermit());
		beacon->setNumberOfShortAddressesPending(0);
		beacon->setNumberOfExtendedAddressesPending(0);
		/** @todo define all beacon options */
		beacon->setMacBeaconPayloadArraySize(
				getMacPib()->getMacBeaconPayloadLength());
		for (int i = 0; i < getMacPib()->getMacBeaconPayloadLength(); i++) {
			beacon->setMacBeaconPayload(i,
					getMacPib()->getMacBeaconPayload()[i]);
		}
		/** @fixme add the right beacon length */
		beacon->setByteLength(5 + sizeof(MacBeaconPayload));
		sendMcps(beacon);
		scheduleAt(simTime() + getBeaconPeriod(), beaconTimer);
	} else if (msg->getKind() == TIMER_DATA_REQUEST) {
		if (timeoutMsg->getKind() != DUMMY_MSG) {
			/** @comment no reply from the ffd, letting know the upper layer */
			sendMlmeUp(timeoutMsg);
			timeoutMsg = new cMessage("", DUMMY_MSG);
			return;
		}
		MlmeAssociate_request* request =
				check_and_cast<MlmeAssociate_request *> (getLastUpperMsg());
		MacCommand* macCommand = new MacCommand("Data Request Command",
				MAC_COMMAND_FRAME);
		macCommand->setCommandType(DATA_REQUEST);
		macCommand->setCommandPayloadArraySize(0);
		macCommand->setByteLength(1);
		McpsEncapsulation encapsulation;
		encapsulation.sourceAddressingMode = LONG_ADDRESS;
		encapsulation.sourceAddress = getMacPib()->getExtendedAddress();
		encapsulation.destinationAddressingMode = request->getCoordAddrMode();
		encapsulation.destinationAddress = request->getCoordAddress();
		encapsulation.destinationPanIdentifier = request->getCoordPanId();
		getMcps()->setNextEncapsulation(encapsulation);
		sendMcps(macCommand);
	} else if (msg->getKind() == TIMER_CAP_SLOT) {
		if (getCapSlotNumber() < 16) {
			setCapSlotNumber(getCapSlotNumber() + 1);
			if (getCapSlotNumber() <= getLastBeacon()->getFinalCapSlot() && !backoffTimer->isScheduled()) {
				if (getMcps()->getFrameQueueLength() > 0 || getMcps()->getPriorityFrameQueueLength() > 0) {
					/** @comment start the CCA procedure */
					PlmeCca_request *request = new PlmeCca_request("PLME-CCA.request", PLME_CCA_REQUEST);
					sendPlmeDown(request);
				} else {
					/** @comment no data in the queues */
				}
			}
			if (getCapSlotNumber() == getLastBeacon()->getFinalCapSlot()) {
				comment(COMMENT_SUPERFRAME, "Starting Content Free Period");
				setSuperframePeriod(CFP);
			}
			scheduleAt(simTime() + getCapSlotDuration(), capSlotTimer);
		} else {
			comment(COMMENT_SUPERFRAME, "Starting Inactive Period");
			setSuperframePeriod(INACTIVE);
			/** @comment turn off the radio */
		}
	} else if (msg->getKind() == TIMER_BACKOFF) {
		/** @comment backoff timer is just blocking the start of the CCA procedure */
		if (getSuperframePeriod() != CAP) {
			/** @comment backoff shot at the CFP or Inactive period - not good
			 * reschedule it to hit the incoming CAP period */
			scheduleAt(simTime() + getSuperframeDuration() - (getCapSlotDuration()*getLastBeacon()->getFinalCapSlot()), backoffTimer);
		}
	}
}

void Mlme::handlePlmeMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msg->getKind() == PLME_SET_TRX_STATE_CONFIRM) {
		msgName = getLastUpperMsg()->getName();
		if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
			MlmeScan_request* request = check_and_cast<MlmeScan_request *> (
					getLastUpperMsg());
			if (request->getScanType() == ED_SCAN) {
				unsigned int base = 0x00000001;
				/** doing scan on up to 27 channels */
				for (int channel = 0; channel < 27; channel++) {
					/** if there's a scan request for the channel */
					if ((request->getScanChannels() & (base << channel))
							!= 0x00000000) {
						/** @comment aBaseSuperframeDuration*(2^scanDuration + 1)*/
						int scanTimeSymbols =
								(getMacPib()->getBaseSuperFrameDuration())
										* (((2 << request->getScanDuration())
												/ 2) + 1);
						double edTimer = symbolsToSeconds(scanTimeSymbols,
								channel, 0);
						std::stringstream commentStream;
						commentStream << "Performing ED scan for " << edTimer
								<< " seconds on channel " << channel;
						comment(COMMENT_TIMER, commentStream.str());
						timer->setName("ED-SCAN.timer");
						timer->setKind(TIMER_ED_SCAN);
						scheduleAt(simTime() + edTimer, timer);
						switchRadioToChannel(channel);
						break;
					}
				}
			} else if (request->getScanType() == ACTIVE_SCAN) {
				if (getLayerStage() == 0) {
					setLayerStage(1);
					unsigned int base = 0x00000001;
					for (int channel = getCurrentChannel(); channel < 27; channel++) {
						/** if there's a scan request for the channel */
						if ((request->getScanChannels() & (base << channel))
								!= 0x00000000) {
							/** @comment aBaseSuperframeDuration*(2^scanDuration + 1)*/
							int
									scanTimeSymbols =
											(getMacPib()->getBaseSuperFrameDuration())
													* (((2
															<< request->getScanDuration())
															/ 2) + 1);
							double activeTimer = symbolsToSeconds(
									scanTimeSymbols, channel,
									request->getChannelPage());
							std::stringstream commentStream;
							commentStream << "Performing Active scan for "
									<< activeTimer << " seconds on channel "
									<< channel;
							setCurrentChannel(channel);
							comment(COMMENT_TIMER, commentStream.str());
							timer->setName("ACTIVE-SCAN.timer");
							timer->setKind(TIMER_ACTIVE_SCAN);
							scheduleAt(simTime() + activeTimer, timer);
							PlmeSet_request* set = new PlmeSet_request(
									"PLME-SET.request", PLME_SET_REQUEST);
							set->setPibAttribute(PHY_CURRENT_PAGE);
							set->setPibAttributeValueArraySize(1);
							set->setPibAttributeValue(0,
									request->getChannelPage());
							setCurrentPage(request->getChannelPage());
							sendPlmeDown(set);
							setCurrentChannel(channel);
							break;
						}
					}
				} else if (getLayerStage() == 1) {
					setLayerStage(0);
					/** @comment here we're just waiting for the beacons */
				} else if (getLayerStage() == 2) {
					/** @comment active scan finished, radio turned off */
					MlmeScan_confirm *confirm = new MlmeScan_confirm(
							"MLME-SCAN.confirm", MLME_SCAN_CONFIRM);
					confirm->setStatus(MAC_SUCCESS);
					confirm->setScanType(ACTIVE_SCAN);
					confirm->setChannelPage(request->getChannelPage());
					/** @todo include unscanned channels variable here */
					/** @todo include result list size variable here */
					confirm->setResultListSize(
							getScannedPanDescriptorsArraySize());
					confirm->setPanDescriptorListArraySize(
							getScannedPanDescriptorsArraySize());
					for (int i = 0; i < getScannedPanDescriptorsArraySize(); i++) {
						confirm->setPanDescriptorList(i,
								getScannedPanDescriptors()[i]);
					}
					confirm->setEnergyDetectListArraySize(0);
					sendMlmeUp(confirm);
				}
			}
		}
	} else if (msg->getKind() == PLME_SET_CONFIRM) {
		PlmeSet_confirm* confirm = check_and_cast<PlmeSet_confirm *> (msg);
		if (getLastUpperMsg()->getKind() == MLME_SET_REQUEST) {
			MlmeSet_request* request = check_and_cast<MlmeSet_request *> (
					getLastUpperMsg());
			MlmeSet_confirm* response = new MlmeSet_confirm("MLME-SET.confirm",
					MLME_SET_CONFIRM);
			response->setStatus(MAC_SUCCESS);
			response->setPibAttribute(request->getPibAttribute());
			response->setPibAttributeIndex(request->getPibAttributeIndex());
			sendMlmeUp(response);
		} else if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
			MlmeScan_request* request = check_and_cast<MlmeScan_request *> (
					getLastUpperMsg());
			if (confirm->getPibAttribute() == PHY_CURRENT_CHANNEL) {
				if (request->getScanType() == ED_SCAN) {
					if (timer->isScheduled()) {
						PlmeEd_request* ed = new PlmeEd_request(
								"PLME-ED.request", PLME_ED_REQUEST);
						sendPlmeDown(ed);
					}
				} else if (request->getScanType() == ACTIVE_SCAN) {
					MacCommand* beaconRequest = new MacCommand(
							"Beacon Request Command", MAC_COMMAND_FRAME);
					beaconRequest->setCommandType(BEACON_REQUEST);
					beaconRequest->setCommandPayloadArraySize(0);
					beaconRequest->setByteLength(1);
					sendMcps(beaconRequest);
				}
			} else if (confirm->getPibAttribute() == PHY_CURRENT_PAGE) {
				if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
					switchRadioToChannel(getCurrentChannel());
				}
			}
		} else if (getLastUpperMsg()->getKind() == MLME_ASSOCIATE_REQUEST) {
			MlmeAssociate_request* request = check_and_cast<
					MlmeAssociate_request *> (getLastUpperMsg());
			if (confirm->getPibAttribute() == PHY_CURRENT_CHANNEL) {
				/** @TODO omitting the channel page PIB attribute */
				MacCommand* command = new MacCommand(
						"Associate Request Command", MAC_COMMAND_FRAME);
				command->setCommandType(ASSOCIATE_REQUEST);
				/** @COMMENT Command Frame Identifier (1B) + Capability Information (1B) */
				command->setByteLength(2);
				NwkCapabilityInformation capability;
				unsigned char* commandPayload;
				commandPayload = (unsigned char*) &capability;
				capability.alternatePanCoordinator
						= request->getAlternatePanCoordinator();
				capability.deviceType = request->getDeviceType();
				capability.powerSource = request->getPowerSource();
				capability.receiverOnWhenIdle
						= request->getReceiverOnWhenIdle();
				capability.securityCapability
						= request->getSecurityCapability();
				capability.allocateAddress = request->getAllocateAddress();
				command->setCommandPayloadArraySize(sizeof(capability));
				for (unsigned int i = 0; i < sizeof(capability); i++) {
					command->setCommandPayload(i, commandPayload[i]);
				}
				scheduleAt(simTime() + backoffPeriod, backoffTimer);
				sendMcps(command);
			}
		}
	} else if (msg->getKind() == PLME_ED_CONFIRM) {
		PlmeEd_confirm* confirm = check_and_cast<PlmeEd_confirm *> (msg);
		MlmeScan_request* request = check_and_cast<MlmeScan_request *> (
				getLastUpperMsg());
		/** @todo we should handle confirm status msg like TRX_OFF, or TX_ON */
		if (confirm->getStatus() == PHY_SUCCESS) {
			getEnergyLevels()[getScannedChannels()] = confirm->getEnergyLevel();
			setScannedChannels(getScannedChannels() + 1);
		}
		/** If the ED scan is still going on...*/
		if (timer->isScheduled()) {
			PlmeEd_request* ed = new PlmeEd_request("PLME-ED.request",
					PLME_ED_REQUEST);
			sendPlmeDown(ed);
		} else {
			unsigned int base = 0x00000001;
			/** doing scan on up to 27 channels */
			for (int channel = getCurrentChannel() + 1; channel < 27; channel++) {
				/** if there's a scan request for the channel */
				if ((request->getScanChannels() & (base << channel))
						!= 0x00000000) {
					/** @comment aBaseSuperframeDuration*(2^scanDuration + 1)*/
					int scanTimeSymbols =
							(getMacPib()->getBaseSuperFrameDuration()) * (((2
									<< request->getScanDuration()) / 2) + 1);
					double edTimer = symbolsToSeconds(scanTimeSymbols, channel,
							0);
					std::stringstream commentStream;
					commentStream << "Performing ED scan for " << edTimer
							<< " seconds on channel " << channel;
					comment(COMMENT_TIMER, commentStream.str());
					timer->setName("ED-SCAN.timer");
					scheduleAt(simTime() + edTimer, timer);
					switchRadioToChannel(channel);
					delete (msg);
					return;
				}
			}
			MlmeScan_confirm* response = new MlmeScan_confirm(
					"MLME-SCAN.confirm", MLME_SCAN_CONFIRM);
			response->setStatus(MAC_SUCCESS);
			response->setScanType(ED_SCAN);
			response->setResultListSize(request->getScanChannels());
			response->setEnergyDetectListArraySize(getScannedChannels());
			for (int i = 0; i < getScannedChannels(); i++) {
				response->setEnergyDetectList(i, getEnergyLevels()[i]);
			}
			sendMlmeUp(response);
		}
	} else if (msg->getKind() == PLME_CCA_CONFIRM) {
		PlmeCca_confirm *confirm = check_and_cast<PlmeCca_confirm *>(msg);
		if (confirm->getStatus() == PHY_IDLE) {
			/** @comment channel clear, transmit the frame */
			getMcps()->sendCapFrame();
			resetBackoffPeriod();
		} else {
			if (getNumberOfBacoffs() == getMacPib()->getMacMaxCSMABackoffs()
				|| getBackoffExponent() == getMacPib()->getMacMaxBE()) {
				setNumberOfBackoffs(0);
				setBackoffExponent(getMacPib()->getMacMinBE());
				/** @TODO reset the backoff period*/
				resetBackoffPeriod();
				/** @TODO send notice to upper layer that the channel is not accessible */
			} else {
				recalculateBackoffPeriod();
			}
		}
	}
	delete (msg);
}

void Mlme::handleMlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg);
	std::string msgName = msg->getName();
	if (msg->getKind() == MLME_SCAN_REQUEST) {
		MlmeScan_request* request = check_and_cast<MlmeScan_request *> (msg);
		resetScannedPanDescriptors();
		if (timer->isScheduled() && (timer->getKind() == TIMER_ED_SCAN
				|| timer->getKind() == TIMER_ACTIVE_SCAN || timer->getKind()
				== TIMER_PASSIVE_SCAN || timer->getKind() == TIMER_ORPHAN_SCAN)) {
			MlmeScan_confirm* response = new MlmeScan_confirm(
					"MLME-SCAN.confirm", MLME_SCAN_CONFIRM);
			response->setStatus(MAC_SCAN_IN_PROGRESS);
			sendMlmeUp(response);
		} else {
			PlmeSetTrxState_request* changeState = new PlmeSetTrxState_request(
					"PLME-SET-TRX-STATE.request", PLME_SET_TRX_STATE_REQUEST);
			if (request->getScanType() == ED_SCAN) {
				changeState->setState(PHY_RX_ON);
			} else if (request->getScanType() == ACTIVE_SCAN) {
				changeState->setState(PHY_TX_ON);
				setCurrentChannel(0);
			}
			sendPlmeDown(changeState);
			setScannedChannels(0);
		}
	} else if (msg->getKind() == MLME_SET_REQUEST) {
		MlmeSet_request* request = check_and_cast<MlmeSet_request *> (msg);
		if (request->getPibAttribute() <= 0x09) {
			/** @comment we do have a PHY PIB attribute passed */
			if (request->getPibAttribute() == PHY_CURRENT_CHANNEL) {
				switchRadioToChannel(request->getPibAttributeValue(0));
				return;
			}
			PlmeSet_request* setRequest = new PlmeSet_request(
					"PLME-SET.request", PLME_SET_REQUEST);
			setRequest->setPibAttribute(request->getPibAttribute());
			setRequest->setPibAttributeValueArraySize(
					request->getPibAttributeValueArraySize());
			for (unsigned int i = 0; i
					< request->getPibAttributeValueArraySize(); i++) {
				setRequest->setPibAttributeValue(i,
						request->getPibAttributeValue(i));
			}
			sendPlmeDown(setRequest);
		} else {
			/** @comment we do have a MAC PIB attribute passed */
			/** @todo add here the possibility to change indexes in the tables
			 * through the PIB Attribute Index */
			unsigned int* value =
					new unsigned int[request->getPibAttributeValueArraySize()];
			for (unsigned int i = 0; i
					< request->getPibAttributeValueArraySize(); i++) {
				value[i] = request->getPibAttributeValue(i);
			}
			MlmeSet_confirm* response = new MlmeSet_confirm("MLME-SET.confirm",
					MLME_SET_CONFIRM);
			MacEnum status = getMacPib()->setPibAttribute(
					(PibIdentifier) request->getPibAttribute(), value);
			response->setStatus(status);
			response->setPibAttribute(request->getPibAttribute());
			response->setPibAttributeIndex(request->getPibAttributeIndex());
			sendMlmeUp(response);
		}
	} else if (msg->getKind() == MLME_START_REQUEST) {
		MlmeStart_request* request = check_and_cast<MlmeStart_request *> (msg);
		MlmeStart_confirm* response = new MlmeStart_confirm(
				"MLME-START.confirm", MLME_START_CONFIRM);
		if (getMacPib()->getMacShortAddress() == 0xFFFF) {
			response->setStatus(MAC_NO_SHORT_ADDRESS);
			sendMlmeUp(response);
		}
		if (!request->getCoordRealignment()) {
			/** @note Logical Channel and Channel Page are set within the previous MLME-SET.request command */
			getMacPib()->setMacPANId(request->getPanId());
			getMacPib()->setMacBeaconOrder(request->getBeaconOrder());
			getMacPib()->setMacSuperframeOrder(request->getSuperframeOrder());
			getMacPib()->setMacBattLifeExt(request->getBatteryLifeExtension());
			int beaconDelaySymbols = getMacPib()->getBaseSuperFrameDuration();
			beaconDelaySymbols = beaconDelaySymbols
					<< getMacPib()->getMacBeaconOrder();
			setBeaconPeriod(symbolsToSeconds(beaconDelaySymbols,
					getCurrentChannel(), getCurrentPage()));
			std::stringstream commentStream;
			commentStream << "The beacon period set to: " << getBeaconPeriod() << " s.";
			comment(COMMENT_BEACON, commentStream.str());
			/** @note the value of startTime is ignored while we're coordinator */
			if (getRole() == COORDINATOR) {
				scheduleAt(simTime(), beaconTimer);
			}
			response->setStatus(MAC_SUCCESS);
			sendMlmeUp(response);
		} else {
			/** @todo coord realignment set to true */
		}
	} else if (msg->getKind() == MLME_ASSOCIATE_REQUEST) {
		MlmeAssociate_request* associate = check_and_cast<
				MlmeAssociate_request *> (msg);
		/** @COMMENT let's set the appropriate MAC PIB and PHY PIB attributes*/
		getMacPib()->setMacPANId(associate->getCoordPanId());
		if (associate->getCoordAddrMode() == SHORT_ADDRESS) {
			getMacPib()->setMacCoordShortAddress(associate->getCoordAddress());
		} else {
			getMacPib()->setMacCoordExtendedAddress(
					associate->getCoordAddress());
		}
		getMacPib()->setMacRxOnWhenIdle(associate->getReceiverOnWhenIdle());
		if (!associate->getSecurityCapability())
			getMacPib()->setMacSecurityEnabled(false);
		PlmeSet_request* setRequest = new PlmeSet_request("PLME-SET.request",
				PLME_SET_REQUEST);
		setRequest->setPibAttribute(PHY_CURRENT_CHANNEL);
		setRequest->setPibAttributeValueArraySize(1);
		setRequest->setPibAttributeValue(0, associate->getLogicalChannel());
		sendPlmeDown(setRequest);
	} else if (msg->getKind() == MLME_ASSOCIATE_RESPONSE) {
		/** @note here we are waiting for the data request frame from the child */
	}
}

void Mlme::handleMacPibMsg(cMessage *msg) {
	std::string msgName = msg->getName();
}

void Mlme::handleMcpsMsg(cMessage *msg) {
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		std::string msgName = msg->getName();
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		if (command->getCommandType() == BEACON_REQUEST) {
			PlmeSetTrxState_request *request = new PlmeSetTrxState_request(
					"PLME-SET-TRX-STATE.request", PLME_SET_TRX_STATE_REQUEST);
			request->setState(PHY_RX_ON);
			sendPlmeDown(request);
			delete (command);
		} else if (command->getCommandType() == ASSOCIATE_REQUEST) {
			if (msgName == "Command sent") {
				delete (msg);
				return;
			}
			if (!getMacPib()->getMacAssociationPermit()) {
				comment(COMMENT_PAN,
						"Association not allowed, discarding request");
				delete (command);
				return;
			}
			MlmeAssociate_indication* indication =
					new MlmeAssociate_indication("MLME-ASSOCIATE.indication",
							MLME_ASSOCIATE_INDICATION);
			unsigned char* payload;
			NwkCapabilityInformation* capability;
			payload = new unsigned char[sizeof(NwkCapabilityInformation)];
			for (unsigned int i; i < sizeof(NwkCapabilityInformation); i++) {
				payload[i] = command->getCommandPayload(i);
			}
			capability = (NwkCapabilityInformation*) payload;
			indication->setDeviceAddress(
					getMcps()->getLastLowerMsg()->getSourceAddress());
			indication->setAlternatePanCoordinator(
					capability->alternatePanCoordinator);
			indication->setDeviceType(capability->deviceType);
			indication->setPowerSource(capability->powerSource);
			indication->setReceiverOnWhenIdle(capability->receiverOnWhenIdle);
			indication->setSecurityCapability(capability->securityCapability);
			indication->setAllocateAddress(capability->allocateAddress);
			indication->setSecurityLevel(0x00);
			sendMlmeUp(indication);
			delete (command);
		} else if (command->getCommandType() == DATA_REQUEST) {
			if (getLastUpperMsg()->getKind() == MLME_ASSOCIATE_RESPONSE) {
				unsigned short assocShortAddress;
				MlmeAssociate_response *response = check_and_cast<MlmeAssociate_response *>(getLastUpperMsg()->dup());
				MacCommand* macCommand = new MacCommand("Associate Response Command", MAC_COMMAND_FRAME);
				macCommand->setCommandType(ASSOCIATE_RESPONSE);
				macCommand->setCommandPayloadArraySize(3);
				macCommand->setByteLength(4);
				assocShortAddress = response->getAssocShortAddress();
				unsigned char *commandPayload;
				commandPayload = (unsigned char*) &assocShortAddress;
				macCommand->setCommandPayload(0, commandPayload[0]);
				macCommand->setCommandPayload(1, commandPayload[1]);
				macCommand->setCommandPayload(2, response->getStatus());
				McpsEncapsulation encapsulation;
				encapsulation.destinationAddress = response->getDeviceAddress();
				encapsulation.destinationPanIdentifier = getMacPib()->getMacPANId();
				getMcps()->setNextEncapsulation(encapsulation);
				sendMcps(macCommand);
			}
		} else if (command->getCommandType() == ASSOCIATE_RESPONSE) {
			/** @TODO finish association process */
			setLayerStage(0);
		}
	} else if (msg->getKind() == MAC_BEACON_FRAME) {
		std::string msgName = msg->getName();
		if (msgName == "Beacon sent") {
			if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
				MlmeStart_confirm* confirm = new MlmeStart_confirm(
						"MLME-START.confirm", MLME_START_CONFIRM);
				confirm->setStatus(MAC_SUCCESS);
				sendMlmeUp(confirm);
			}
			delete (msg);
		} else if (msgName == "Beacon Command") {
			MacBeacon* macBeacon = check_and_cast<MacBeacon *> (msg);
			setLastBeacon(macBeacon->dup());
			PdMsg* pdBeacon = getMcps()->getLastLowerMsg()->dup();
			if ((pdBeacon->getSourceAddressingMode() == LONG_ADDRESS
					&& pdBeacon->getSourceAddress()
							== getMacPib()->getMacCoordExtendedAddress())
					|| (pdBeacon->getSourceAddressingMode() == SHORT_ADDRESS
							&& pdBeacon->getSourceAddress()
									== getMacPib()->getMacCoordShortAddress())) {
				/** @comment now we found the beacon from the coordinator we'd like to work with */
				/** @comment capSlotDuration = aBaseSlotDuration * 2^superframeOrder */
				/** @FIXME random problems here with the SimTime :-\ */
				std::stringstream commentStream;
				commentStream << "Starting the Contention Access Period";
				setCapSlotDuration((SimTime) symbolsToSeconds(
						getMacPib()->getBaseSlotDuration() * (1
								<< macBeacon->getSuperframeOrder()),
						getCurrentChannel(), getCurrentPage()));

				setCapSlotNumber(1);
				setSuperframePeriod(CAP);
				commentStream.str().clear();
				commentStream << "; CAP slot duration: " << getCapSlotDuration();
				comment(COMMENT_SUPERFRAME, commentStream.str());
				scheduleAt(getPd()->getLastMsgTimestamp()
						+ getCapSlotDuration(), capSlotTimer);
				setSuperframeDuration((SimTime)(symbolsToSeconds(
						getMacPib()->getBaseSlotDuration() * (1
								<< macBeacon->getBeaconOrder()),
						getCurrentChannel(), getCurrentPage()) - 0.0000004));
				scheduleAt(getPd()->getLastMsgTimestamp()
						+ getSuperframeDuration(), superframeTimer);
				setLastBeaconTimestamp(getPd()->getLastMsgTimestamp());
				McpsEncapsulation encapsulation;
				encapsulation.sourceAddressingMode = NOT_PRESENT;
				setDataRequestScheduled(false);
				for (int i = 0; i
						< macBeacon->getNumberOfShortAddressesPending(); i++) {
					if (macBeacon->getAddressList(i)
							== getMacPib()->getMacShortAddress()) {
						/** @TODO we have a message pending from the coordinator
						 * use short address */
						encapsulation.sourceAddressingMode = SHORT_ADDRESS;
						encapsulation.sourceAddress
								= getMacPib()->getMacShortAddress();
						break;
					}
				}
				for (int i = 0; i
						< macBeacon->getNumberOfExtendedAddressesPending(); i++) {
					if (macBeacon->getAddressList(i
							+ macBeacon->getNumberOfShortAddressesPending())
							== getMacPib()->getExtendedAddress()) {
						/** @TODO we have a message pending from the coordinator
						 * use a long address */
						encapsulation.sourceAddressingMode = LONG_ADDRESS;
						encapsulation.sourceAddress
								= getMacPib()->getExtendedAddress();
						break;
					}
				}
				if (encapsulation.sourceAddressingMode != NOT_PRESENT) {
					/** @comment coordinator has a data waiting for us
					 * let's ask for it */
					if (macBeacon->getPanCoordinator()) {
						encapsulation.destinationAddressingMode = NOT_PRESENT;
					} else {
						if (getMacPib()->getMacCoordShortAddress() != 0xFFFE) {
							encapsulation.destinationAddressingMode
									= SHORT_ADDRESS;
							encapsulation.destinationAddress
									= getMacPib()->getMacCoordShortAddress();
						} else {
							encapsulation.destinationAddressingMode
									= LONG_ADDRESS;
							encapsulation.destinationAddress
									= getMacPib()->getMacCoordExtendedAddress();
						}
					}
					encapsulation.destinationPanIdentifier
							= getMacPib()->getMacPANId();
					getMcps()->setNextEncapsulation(encapsulation);
					if (getMacPib()->getMacAutoRequest()) {
						/** @TODO send data request frame*/
					}
				}
			}
			PanDescriptor panDescriptor;
			/** @todo make an option to use also long addresses */
			panDescriptor.coordAddrMode = SHORT_ADDRESS;
			panDescriptor.coordPanId = pdBeacon->getSourcePanIdentifier();
			/** @note here i guess, we're talking about the related ffd address, not the PAN coord address*/
			panDescriptor.coordAddress = pdBeacon->getSourceAddress();
			panDescriptor.logicalChannel = getCurrentChannel();
			panDescriptor.channelPage = getCurrentPage();
			panDescriptor.beaconOrder = macBeacon->getBeaconOrder();
			panDescriptor.superframeOrder = macBeacon->getSuperframeOrder();
			panDescriptor.finalCapSlot = macBeacon->getFinalCapSlot();
			panDescriptor.batteryLifeExtension
					= macBeacon->getBatteryLifeExtension();
			panDescriptor.panCoordinator = macBeacon->getPanCoordinator();
			panDescriptor.associationPermit = macBeacon->getAssociationPermit();
			panDescriptor.gtsPermit = macBeacon->getGtsPermit();
			/** @todo add some method to lower layers to deal with the link quality of the last received msg */
			/* panDescriptor.linkQuality = */
			/* panDescriptor.timeStamp = */
			if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
				MlmeScan_request* scan = check_and_cast<MlmeScan_request *> (
						getLastUpperMsg());
				if (scan->getScanType() == ACTIVE_SCAN || scan->getScanType()
						== PASSIVE_SCAN) {
					if (!isPanScanned(panDescriptor)) {
						addScannedPanDescriptor(panDescriptor);
					}
				}
			}
			if (macBeacon->getMacBeaconPayloadArraySize() != 0) {
				MlmeBeaconNotify_indication* indication =
						new MlmeBeaconNotify_indication(
								"MLME-BEACON-NOTIFY.indication",
								MLME_BEACON_NOTIFY_INDICATION);
				indication->setBsn(pdBeacon->getSequenceNumber());
				indication->setPanDescriptor(panDescriptor);
				indication->setNumberOfShortAddressesPending(
						macBeacon->getNumberOfShortAddressesPending());
				indication->setNumberOfExtendedAddressesPending(
						macBeacon->getNumberOfExtendedAddressesPending());
				indication->setAddressListArraySize(
						macBeacon->getAddressListArraySize());
				for (unsigned int i = 0; i
						< macBeacon->getAddressListArraySize(); i++) {
					indication->setAddressList(i, macBeacon->getAddressList(i));
				}
				indication->setSduArraySize(
						macBeacon->getMacBeaconPayloadArraySize());
				for (unsigned int i = 0; i
						< macBeacon->getMacBeaconPayloadArraySize(); i++) {
					indication->setSdu(i, macBeacon->getMacBeaconPayload(i));
				}
				sendMlmeUp(indication);
			}
			delete (pdBeacon);
			delete (msg);
		}
	} else if (msg->getKind() == MAC_ACK_FRAME) {
		if (!getDataRequestScheduled() && getLayerStage() == 0) {
			if (getLastUpperMsg()->getKind() == MLME_ASSOCIATE_REQUEST) {
				scheduleAt(simTime() + symbolsToSeconds(getMacPib()->getMacResponseWaitTime()*getMacPib()->getBaseSuperFrameDuration(), getCurrentChannel(), getCurrentPage()), dataRequestTimer);
				setDataRequestScheduled(true);
				setLayerStage(1);
			}
		}
	}
}

void Mlme::sendPlmeDown(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, plmeSapOut);
}

void Mlme::sendMlmeUp(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, mlmeSapOut);
}

void Mlme::sendMacPib(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, macPibOut);
}

void Mlme::sendMcps(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, mcpsOut);
}

double Mlme::symbolsToSeconds(int symbols, int channel, int page) {
	int symbolRate = 0;
	double seconds;
	if (page == 0) {
		if (channel == 0) {
			symbolRate = 20000;
		} else if (channel <= 10) {
			symbolRate = 40000;
		} else {
			symbolRate = 62500;
		}
	} else if (page == 1) {
		if (channel == 1) {
			symbolRate = 12500;
		} else if (channel <= 10) {
			symbolRate = 50000;
		} else {
			commentError("Unsupported channel number with channel page 1");
		}
	} else if (page == 2) {
		if (channel == 1) {
			symbolRate = 25000;
		} else if (channel <= 10) {
			symbolRate = 62500;
		} else {
			commentError("Unsupported channel number with channel page 2");
		}
	}
	seconds = (double) symbols / (double) symbolRate;
	return seconds;
}

void Mlme::switchRadioToChannel(unsigned int channel) {
	PlmeSet_request* requestChannel = new PlmeSet_request("PLME-SET.request",
			PLME_SET_REQUEST);
	requestChannel->setPibAttribute(PHY_CURRENT_CHANNEL);
	requestChannel->setPibAttributeValueArraySize(1);
	requestChannel->setPibAttributeValue(0, channel);
	std::stringstream commentStream;
	commentStream << "Switching radio to channel " << channel;
	comment(COMMENT_CHANNEL, commentStream.str());
	setCurrentChannel(channel);
	sendPlmeDown(requestChannel);
}

void Mlme::recalculateBackoffPeriod() {
	setNumberOfBackoffs(getNumberOfBacoffs() + 1);
	setBackoffExponent(getBackoffExponent() + 1);
	setBackoffPeriod(calculateBackoffPeriod());
}

void Mlme::resetBackoffPeriod() {
	setNumberOfBackoffs(0);
	setBackoffExponent(getMacPib()->getMacMinBE());
	setBackoffPeriod(calculateBackoffPeriod());
}

SimTime Mlme::calculateBackoffPeriod() {
	return (rand()%(1<<getBackoffExponent()))*getCapSlotDuration();
}
