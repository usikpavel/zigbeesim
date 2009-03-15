#include "Mlme.h"

Define_Module( Mlme)
;

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
	}
	delete (msg);
}

void Mlme::handlePlmeMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msgName == "PLME-SET-TRX-STATE.confirm") {
		msgName = getLastUpperMsg()->getName();
		if (msgName == "MLME-SCAN.request") {
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
				unsigned int base = 0x00000001;
				for (int channel = getCurrentChannel(); channel < 27; channel++) {
					/** if there's a scan request for the channel */
					if ((request->getScanChannels() & (base << channel))
							!= 0x00000000) {
						/** @comment aBaseSuperframeDuration*(2^scanDuration + 1)*/
						int scanTimeSymbols =
								(getMacPib()->getBaseSuperFrameDuration())
										* (((2 << request->getScanDuration())
												/ 2) + 1);
						double activeTimer = symbolsToSeconds(scanTimeSymbols,
								channel, request->getChannelPage());
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
						set->setPIBAttribute(PHY_CURRENT_PAGE);
						set->setPIBAttributeValueArraySize(1);
						set->setPIBAttributeValue(0,
								request->getChannelPage());
						setCurrentPage(request->getChannelPage());
						sendPlmeDown(set);
						break;
					}
				}
			}
		}
	} else if (msg->getKind() == PLME_SET_CONFIRM) {
		PlmeSet_confirm* confirm = check_and_cast<PlmeSet_confirm *> (msg);
		if (confirm->getPIBAttribute() == PHY_CURRENT_CHANNEL) {
			if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
				MlmeScan_request* request =
						check_and_cast<MlmeScan_request *> (getLastUpperMsg());
				if (request->getScanType() == ED_SCAN) {
					if (timer->isScheduled()) {
						PlmeEd_request* ed = new PlmeEd_request();
						ed->setName("PLME-ED.request");
						ed->setKind(PLME_ED_REQUEST);
						sendPlmeDown(ed);
					}
				} //else if (request->getScanType() == ACTIVE_SCAN) {






				//}
			}
		} else if (confirm->getPIBAttribute() == PHY_CURRENT_PAGE) {
			if (getLastUpperMsg()->getKind() == MLME_SCAN_REQUEST) {
				switchRadioToChannel(getCurrentChannel());
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
			}
			setScannedChannels(0);
		}

	}
}

void Mlme::handleMacPibMsg(cMessage *msg) {
	std::string msgName = msg->getName();
}

void Mlme::handleMcpsMsg(cMessage *msg) {
	delete (msg);
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
	seconds = symbols / symbolRate;
	return seconds;
}

void Mlme::switchRadioToChannel(unsigned int channel) {
	PlmeSet_request* requestChannel = new PlmeSet_request();
	requestChannel->setName("PLME-SET.request");
	requestChannel->setKind(PLME_SET_REQUEST);
	requestChannel->setPIBAttribute(PHY_CURRENT_CHANNEL);
	requestChannel->setPIBAttributeValueArraySize(1);
	requestChannel->setPIBAttributeValue(0, channel);
	std::stringstream commentStream;
	commentStream << "Switching radio to channel " << channel;
	comment(CHANNEL, commentStream.str());
	setCurrentChannel(channel);
	sendPlmeDown(requestChannel);
}
