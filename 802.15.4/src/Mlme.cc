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

		commentsLevel = ALL;

	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
		timer = new cMessage();
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
	std::string msgName = msg->getName();
	if (msgName == "ED.timer") {
		return;
	} else if (msgName == "ACTIVE.timer") {
		setCurrentChannel(getCurrentChannel() + 1);
		MlmeScan_request* request = check_and_cast<MlmeScan_request *> (
				getLastUpperMsg());
		PlmeSetTrxState_request* changeState = new PlmeSetTrxState_request();
		changeState->setName("PLME-SET-TRX-STATE.request");
		changeState->setKind(PLME_SET_TRX_STATE_REQUEST);
		if ((request->getScanChannels() >> getCurrentChannel()) > 0x00000000) {
			/** @comment continue with the active scan */
			changeState->setState(PHY_TX_ON);
		} else {
			/** @comment active scan finished */
			/** @comment turning radio off */
			changeState->setState(PHY_TRX_OFF);
			setLayerStage(2);
		}
		sendPlmeDown(changeState);
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
						comment(TIMER, commentStream.str());
						timer->setName("ED.timer");
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
							comment(TIMER, commentStream.str());
							timer->setName("ACTIVE.timer");
							scheduleAt(simTime() + activeTimer, timer);
							PlmeSet_request* set = new PlmeSet_request();
							set->setName("PLME-SET.request");
							set->setKind(PLME_SET_REQUEST);
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
					int scannedChannelsSize = sizeof(getScannedChannels())
							/ sizeof(PanDescriptor);
					confirm->setPanDescriptorListArraySize(scannedChannelsSize);
					for (int i = 0; i < scannedChannelsSize; i++) {
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
						PlmeEd_request* ed = new PlmeEd_request();
						ed->setName("PLME-ED.request");
						ed->setKind(PLME_ED_REQUEST);
						sendPlmeDown(ed);
					}
				} else if (request->getScanType() == ACTIVE_SCAN) {
					MacCommand* beaconRequest = new MacCommand();
					beaconRequest->setName("Beacon Request Command");
					beaconRequest->setKind(MAC_COMMAND_FRAME);
					beaconRequest->setCommandType(BEACON_REQUEST);
					beaconRequest->setCommandPayloadArraySize(0);
					beaconRequest->setByteLength(8);
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
			PlmeEd_request* ed = new PlmeEd_request();
			ed->setName("PLME-ED.request");
			ed->setKind(PLME_ED_REQUEST);
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
					comment(TIMER, commentStream.str());
					scheduleAt(simTime() + edTimer, timer);

					switchRadioToChannel(channel);
					delete (msg);
					return;
				}
			}
			MlmeScan_confirm* response = new MlmeScan_confirm();
			response->setName("MLME-SCAN.confirm");
			response->setKind(MLME_SCAN_CONFIRM);
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
		msgName = timer->getName();
		if (timer->isScheduled() && (msgName == "ED.timer" || msgName
				== "ACTIVE.timer" || msgName == "PASSIVE.timer" || msgName
				== "ORPHAN.timer")) {
			MlmeScan_confirm* response = new MlmeScan_confirm();
			response->setName("MLME-SCAN.confirm");
			response->setKind(MLME_SCAN_CONFIRM);
			response->setStatus(MAC_SCAN_IN_PROGRESS);
			sendMlmeUp(response);
		} else {
			if (request->getScanType() == ED_SCAN) {
				PlmeSetTrxState_request* changeState =
						new PlmeSetTrxState_request();
				changeState->setName("PLME-SET-TRX-STATE.request");
				changeState->setKind(PLME_SET_TRX_STATE_REQUEST);
				changeState->setState(PHY_RX_ON);
				sendPlmeDown(changeState);
			} else if (request->getScanType() == ACTIVE_SCAN) {
				PlmeSetTrxState_request* changeState =
						new PlmeSetTrxState_request();
				changeState->setName("PLME-SET-TRX-STATE.request");
				changeState->setKind(PLME_SET_TRX_STATE_REQUEST);
				changeState->setState(PHY_TX_ON);
				sendPlmeDown(changeState);
				setCurrentChannel(0);
			}
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
			PlmeSet_request* setRequest = new PlmeSet_request();
			setRequest->setName("PLME-SET.request");
			setRequest->setKind(PLME_SET_REQUEST);
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
			MlmeSet_confirm* response = new MlmeSet_confirm("MLME-SET.confirm", MLME_SET_CONFIRM);
			MacEnum status = getMacPib()->setPibAttribute(
					(PibIdentifier) request->getPibAttribute(), value);
			response->setStatus(status);
			response->setPibAttribute(request->getPibAttribute());
			response->setPibAttributeIndex(request->getPibAttributeIndex());
			sendMlmeUp(response);
		}
	} else if (msg->getKind() == MLME_START_REQUEST) {

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
	PlmeSet_request* requestChannel = new PlmeSet_request();
	requestChannel->setName("PLME-SET.request");
	requestChannel->setKind(PLME_SET_REQUEST);
	requestChannel->setPibAttribute(PHY_CURRENT_CHANNEL);
	requestChannel->setPibAttributeValueArraySize(1);
	requestChannel->setPibAttributeValue(0, channel);
	std::stringstream commentStream;
	commentStream << "Switching radio to channel " << channel;
	comment(CHANNEL, commentStream.str());
	setCurrentChannel(channel);
	sendPlmeDown(requestChannel);
}
