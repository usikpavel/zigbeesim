#include "Nlme.h"
#include <string>

Define_Module(Nlme)
;

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

		commentsLevel = ALL;
	} else if (stage == 1) {
		lastUpperMsg = new cMessage();
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
	delete (msg);
}

void Nlme::handleMlmeMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	if (msgName == "MLME-SCAN.confirm") {
		MlmeScan_confirm* confirm = check_and_cast<MlmeScan_confirm *> (msg);
		if (confirm->getStatus() == MAC_SUCCESS) {
			NlmeNetworkFormation_request* request = check_and_cast<NlmeNetworkFormation_request *>(getLastUpperMsg());
			MlmeScan_request* scan = new MlmeScan_request();
			scan->setName("MLME-SCAN.request");
			scan->setKind(MLME_SCAN_REQUEST);
			scan->setScanType(ACTIVE_SCAN);
			scan->setScanChannels(request->getScanChannels());
			scan->setScanDuration(request->getScanDuration());
			scan->setChannelPage(request->getScanChannels()>>28);
			sendMlmeDown(scan);
		}
	}
	delete (msg);
}

void Nlme::handleNlmeMsg(cMessage *msg) {
	setLastUpperMsg(msg);
	std::string msgName = msg->getName();
	if (msg->getKind() == NLME_NETWORK_FORMATION_REQUEST) {
		NlmeNetworkFormation_request* request = check_and_cast<
				NlmeNetworkFormation_request *> (msg);
		MlmeScan_request* scan = new MlmeScan_request();
		scan->setName("MLME-SCAN.request");
		scan->setKind(MLME_SCAN_REQUEST);
		scan->setScanType(ED_SCAN);
		scan->setScanChannels(request->getScanChannels());
		scan->setScanDuration(request->getScanDuration());
		sendMlmeDown(scan);
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
