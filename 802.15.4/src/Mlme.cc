#include "Mlme.h"

Define_Module(Mlme);

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
		beaconTimer = new cMessage("Beacon timer", BEACON_TIMER);
		setScannedChannels(0);
		energyLevels = new char[32];
		scannedPanDescriptors = new PanDescriptor[0];
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
	if (msg->getKind() == ED_TIMER) {
		return;
	} else if (msg->getKind() == ACTIVE_TIMER) {
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
	} else if (msg->getKind() == BEACON_TIMER) {
		/** @todo better to put into some method the beacon creation */
		MacBeacon* beacon = new MacBeacon("Beacon command", MAC_BEACON_FRAME);
		beacon->setBeaconOrder(getMacPib()->getMacBeaconOrder());
		beacon->setSuperframeOrder(getMacPib()->getMacSuperframeOrder());
		/** @todo set FinalCapSlot */
		//beacon->setFinalCapSlot();
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
						timer->setKind(ED_TIMER);
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
							timer->setKind(ACTIVE_TIMER);
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
		}
	} else if (msgName == "PLME-ED.confirm") {
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
	}
	delete (msg);
}

void Mlme::handleMlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg);
	std::string msgName = msg->getName();
	if (msg->getKind() == MLME_SCAN_REQUEST) {
		MlmeScan_request* request = check_and_cast<MlmeScan_request *> (msg);
		resetScannedPanDescriptors();
		if (timer->isScheduled() && (timer->getKind() == ED_TIMER
				|| timer->getKind() == ACTIVE_TIMER || timer->getKind()
				== PASSIVE_TIMER || timer->getKind() == ORPHAN_TIMER)) {
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
			for (int i = 0; i < request->getPibAttributeValueArraySize(); i++) {
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
			for (int i = 0; i < request->getPibAttributeValueArraySize(); i++) {
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
		if (!request->getCoordRealignment()) {
			/** @note Logical Channel and Channel Page are set within the previous MLME-SET.request command */
			getMacPib()->setMacPANId(request->getPanId());
			getMacPib()->setMacBeaconOrder(request->getBeaconOrder());
			getMacPib()->setMacSuperframeOrder(request->getSuperframeOrder());
			getMacPib()->setMacBattLifeExt(request->getBatteryLifeExtension());
			MlmeStart_confirm* response = new MlmeStart_confirm(
					"MLME-START.confirm", MLME_START_CONFIRM);
			int beaconDelaySymbols = getMacPib()->getBaseSuperFrameDuration();
			beaconDelaySymbols = beaconDelaySymbols
					<< getMacPib()->getMacBeaconOrder();
			setBeaconPeriod(symbolsToSeconds(beaconDelaySymbols,
					getCurrentChannel(), getCurrentPage()));
			std::stringstream commentStream;
			commentStream << "The beacon period set to: " << getBeaconPeriod()
					<< " s.";
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
	}
}

void Mlme::handleMacPibMsg(cMessage *msg) {
	std::string msgName = msg->getName();
}

void Mlme::handleMcpsMsg(cMessage *msg) {
	if (msg->getKind() == MAC_COMMAND_FRAME) {
		MacCommand* command = check_and_cast<MacCommand *> (msg);
		if (command->getCommandType() == BEACON_REQUEST) {
			PlmeSetTrxState_request *request = new PlmeSetTrxState_request(
					"PLME-SET-TRX-STATE.request", PLME_SET_TRX_STATE_REQUEST);
			request->setState(PHY_RX_ON);
			sendPlmeDown(request);
			delete (command);
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
		} else if (msgName == "Beacon command") {
			MacBeacon* macBeacon = check_and_cast<MacBeacon *> (msg);
			setLastBeacon(macBeacon->dup());
			/** @todo let's get rid of this one */
			PdMsg* pdBeacon = getMcps()->getLastBeacon()->dup();
			PanDescriptor panDescriptor;
			/** @todo make an option to use also long addresses */
			panDescriptor.coordAddrMode = SHORT_ADDRESS;
			panDescriptor.coordPanId = pdBeacon->getSourcePanIdentifier();
			if (macBeacon->getPanCoordinator()) {
				panDescriptor.coordAddress = pdBeacon->getSourceAddress();
			} else {
				/** @fixme how to find the coordinator address from the beacon msg?? */
				panDescriptor.coordAddress = (unsigned long) 0x00;
			}
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
				for (int i = 0; i < macBeacon->getAddressListArraySize(); i++) {
					indication->setAddressList(i, macBeacon->getAddressList(i));
				}
				indication->setSduArraySize(
						macBeacon->getMacBeaconPayloadArraySize());
				for (int i = 0; i < macBeacon->getMacBeaconPayloadArraySize(); i++) {
					indication->setSdu(i, macBeacon->getMacBeaconPayload(i));
				}
				sendMlmeUp(indication);
			}
			delete (pdBeacon);
			delete (msg);
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
