#include "MacPib.h"

Define_Module(MacPib)
;

void MacPib::initialize(int stage) {
	BasicModule::initialize(stage);
	if (stage == 0) {
		mlmeOut = findGate("mlmeOut");
		mlmeIn = findGate("mlmeIn");

		resetMacPibValues();
		commentsLevel = ALL;
		macBeaconPayload = new unsigned char[1];
	}
}

void MacPib::handleMessage(cMessage *msg) {
	if (!msg->isSelfMessage()) {
		commentMsgReceived(msg);
	}
	if (msg->getArrivalGateId() == mlmeIn) {
		handleMlmeMsg(msg);
	} else {
		handleSelfMsg(msg);
	}
}

void MacPib::handleSelfMsg(cMessage *msg) {
	delete (msg);
}

void MacPib::handleMlmeMsg(cMessage *msg) {
	std::string msgName = msg->getName();
	delete (msg);
}

void MacPib::sendMlme(cMessage *msg) {
	commentMsgSending(msg);
	sendDelayed(msg, 0.0, mlmeOut);
}

void MacPib::resetMacPibValues() {
	setBaseSlotDuration(60);
	setBaseSuperFrameDuration(960);
	setGTSDescPersistenceTime(4);
	setMaxBeaconOverhead(75);
	setMaxBeaconPayloadLength(52);
	setMaxLostBeacons(4);
	setMaxMACSafePayloadSize(102);
	setMaxMACPayloadSize(118);
	setMaxMPDUUnsecuredOverhead(25);
	setMaxSIFSFrameSize(18);
	setMinCAPLength(440);
	setMinMPDUOverhead(9);
	setNumSuperframeSlots(16);
	setUnitBackoffPeriod(20);
	setMacAssociatedPANCoord(false);
	setMacAssociationPermit(false);
	setMacAutoRequest(true);
	setMacBattLifeExt(false);
	setMacBeaconPayloadLength(0);
	setMacBeaconOrder(15);
	setMacBeaconTxTime(0x00000000);
	setMacBSN(rand() % 256);
	setMacCoordShortAddress(0xFFFF);
	setMacDSN(rand() % 256);
	setMacGTSPermit(true);
	setMacMaxBE(5);
	setMacMaxCSMABackoffs(4);
	setMacMaxFrameRetries(3);
	setMacMinBE(3);
	setMacPANId(0xFFFF);
	setMacPromiscuousMode(false);
	setMacResponseWaitTime(32);
	setMacRxOnWhenIdle(false);
	setMacSecurityEnabled(false);
	setMacShortAddress(0xFFFF);
	setMacSuperframeOrder(15);
	setMacTransactionPersistenceTime(0x01F4);
}

MacEnum MacPib::setPIBAttribute(MacPibIdentifier attribute, unsigned int* value) {
	MacEnum status = MAC_SUCCESS;
	switch (attribute) {
	case MAC_ACK_WAIT_DURATION:
		setMacAckWaitDuration(value[0]);
		break;
	case MAC_ASSOCIATED_PAN_COORD:
		setMacAssociatedPANCoord(value[0]);
		break;
	case MAC_ASSOCIATION_PERMIT:
		setMacAssociationPermit(value[0]);
		break;
	case MAC_AUTO_REQUEST:
		setMacAutoRequest(value[0]);
		break;
	case MAC_BATT_LIFE_EXT:
		setMacBattLifeExt(value[0]);
		break;
	case MAC_BATT_LIFE_EXT_PERIODS:
		if ((value[0] < 6) || (value[0] > 41)) {
			return MAC_INVALID_PARAMETER;
		}
		setMacBattLifeExtPeriods(value[0]);
		break;
	case MAC_BEACON_PAYLOAD:
		/** @todo check this int* to char* conversion between the arrays */
		std::cout << "!!!HAZARD" << endl;
		setMacBeaconPayload((unsigned char*) value);
		break;
	case MAC_BEACON_PAYLOAD_LENGTH:
		if (value[0] > getMaxBeaconPayloadLength()) {
			return MAC_INVALID_PARAMETER;
		}
		setMacBeaconPayloadLength(value[0]);
		break;
	case MAC_BEACON_ORDER:
		if (value[0] > 15) {
			return MAC_INVALID_PARAMETER;
		}
		setMacBeaconOrder(value[0]);
		break;
	case MAC_BEACON_TX_TIME:
		if (value[0] > 0x00FFFFFF) {
			return MAC_INVALID_PARAMETER;
		}
		setMacBeaconTxTime(value[0]);
		break;
	case MAC_BSN:
		if (value[0] > 0xFF) {
			return MAC_INVALID_PARAMETER;
		}
		setMacBSN(value[0]);
	case MAC_COORD_EXTENDED_ADDRESS:
		/** @todo watch the long* and int* conversion */
		std::cout << "!!!HAZARD" << endl;
		setMacCoordExtendedAddress(((unsigned long*) value)[0]);
		break;
	case MAC_COORD_SHORT_ADDRESS:
		setMacCoordShortAddress(value[0]);
		break;
	case MAC_DSN:
		setMacDSN(value[0]);
		break;
	case MAC_GTS_PERMIT:
		setMacGTSPermit(value[0]);
		break;
	case MAC_MAX_BE:
		if ((value[0] < 3) || (value[0] > 8)) {
			return MAC_INVALID_PARAMETER;
		}
		setMacMaxBE(value[0]);
		break;
	case MAC_MAX_CSMA_BACKOFFS:
		if (value[0] > 5) {
			return MAC_INVALID_PARAMETER;
		}
		setMacMaxCSMABackoffs(value[0]);
		break;
	case MAC_MAX_FRAME_TOTAL_WAIT_TIME:
		setMacMaxFrameTotalWaitTime(value[0]);
		break;
	case MAC_MAX_FRAME_RETRIES:
		if (value[0] > 7) {
			return MAC_INVALID_PARAMETER;
		}
		setMacMaxFrameRetries(value[0]);
		break;
	case MAC_MIN_BE:
		if (value[0] > getMacMaxBE()) {
			return MAC_INVALID_PARAMETER;
		}
		setMacMinBE(value[0]);
		break;
	case MAC_PAN_ID:
		if (value[0] > 0xFFFF) {
			return MAC_INVALID_PARAMETER;
		}
		setMacPANId(value[0]);
		break;
	case MAC_PROMISCUOUS_MODE:
		setMacPromiscuousMode(value[0]);
		break;
	case MAC_RESPONSE_WAIT_TIME:
		if ((value[0] < 2) || (value[0] > 64)) {
			return MAC_INVALID_PARAMETER;
		}
		setMacResponseWaitTime(value[0]);
		break;
	case MAC_RX_ON_WHEN_IDLE:
		setMacRxOnWhenIdle(value[0]);
		break;
	case MAC_SECURITY_ENABLED:
		setMacSecurityEnabled(value[0]);
		break;
	case MAC_SHORT_ADDRESS:
		if (value[0] > 0xFFFF) {
			return MAC_INVALID_PARAMETER;
		}
		setMacShortAddress(value[0]);
		break;
	case MAC_SUPERFRAME_ORDER:
		if (value[0] > 15) {
			return MAC_INVALID_PARAMETER;
		}
		setMacSuperframeOrder(value[0]);
		break;
	case MAC_SYNC_SYMBOL_OFFSET:
		if (value[0] > 0x0400) {
			return MAC_INVALID_PARAMETER;
		}
		setMacSyncSymbolOffset(value[0]);
		break;
	case MAC_TIMESTAMP_SUPPORTED:
		setMacTimestampSupported(value[0]);
		break;
	case MAC_TRANSACTION_PERSISTENCE_TIME:
		if (value[0] > 0xFFFF) {
			return MAC_INVALID_PARAMETER;
		}
		setMacTransactionPersistenceTime(value[0]);
		break;
	default:
		status = MAC_READ_ONLY;
	}
	return status;
}

unsigned int* MacPib::getPIBAttribute(MacPibIdentifier attribute) {
	unsigned int* value;
	switch (attribute) {
	case MAC_A_BASE_SLOT_DURATION:
		value = new unsigned int[1];
		value[0] = getBaseSlotDuration();
	case MAC_A_BASE_SUPERFRAME_DURATION:
		value = new unsigned int[1];
		value[0] = getBaseSuperFrameDuration();
	case MAC_A_EXTENDED_ADDRESS:
		value = new unsigned int[1];
		value[0] = getExtendedAddress();
	case MAC_A_GTS_DESC_PERSISTENCE_TIME:
		value = new unsigned int[1];
		value[0] = getGTSDescPersistenceTime();
	case MAC_A_MAX_BEACON_OVERHEAD:
		value = new unsigned int[1];
		value[0] = getMaxBeaconOverhead();
	case MAC_A_MAX_BEACON_PAYLOAD_LENGTH:
		value = new unsigned int[1];
		value[0] = getMaxBeaconPayloadLength();
	case MAC_A_MAX_LOST_BEACONS:
		value = new unsigned int[1];
		value[0] = getMaxLostBeacons();
	case MAC_A_MAX_MAC_SAFE_PAYLOAD_SIZE:
		value = new unsigned int[1];
		value[0] = getMaxMACSafePayloadSize();
	case MAC_A_MAX_MAC_PAYLOAD_SIZE:
		value = new unsigned int[1];
		value[0] = getMaxMACPayloadSize();
	case MAC_A_MAX_MPDU_UNSECURED_PAYLOAD:
		value = new unsigned int[1];
		value[0] = getMaxMPDUUnsecuredOverhead();
	case MAC_A_MAX_SIFS_FRAME_SIZE:
		value = new unsigned int[1];
		value[0] = getMaxSIFSFrameSize();
	case MAC_A_MIN_CAP_LENGTH:
		value = new unsigned int[1];
		value[0] = getMinCAPLength();
	case MAC_A_MIN_MPDU_OVERHEAD:
		value = new unsigned int[1];
		value[0] = getMinMPDUOverhead();
	case MAC_A_NUM_SUPERFRAME_SLOTS:
		value = new unsigned int[1];
		value[0] = getNumSuperframeSlots();
	case MAC_A_UNIT_BACKOFF_PERIOD:
		value = new unsigned int[1];
		value[0] = getUnitBackoffPeriod();
	case MAC_ACK_WAIT_DURATION:
		value = new unsigned int[1];
		value[0] = getMacAckWaitDuration();
	case MAC_ASSOCIATED_PAN_COORD:
		value = new unsigned int[1];
		value[0] = getMacAssociatedPANCoord();
	case MAC_ASSOCIATION_PERMIT:
		value = new unsigned int[1];
		value[0] = getMacAssociationPermit();
	case MAC_AUTO_REQUEST:
		value = new unsigned int[1];
		value[0] = getMacAutoRequest();
	case MAC_BATT_LIFE_EXT:
		value = new unsigned int[1];
		value[0] = getMacBattLifeExt();
	case MAC_BATT_LIFE_EXT_PERIODS:
		value = new unsigned int[1];
		value[0] = getMacBattLifeExtPeriods();
	case MAC_BEACON_PAYLOAD:
		value = (unsigned int*)getMacBeaconPayload();
	case MAC_BEACON_PAYLOAD_LENGTH:
		value = new unsigned int[1];
		value[0] = getMacBeaconPayloadLength();
	case MAC_BEACON_ORDER:
		value = new unsigned int[1];
		value[0] = getMacBeaconOrder();
	case MAC_BEACON_TX_TIME:
		value = new unsigned int[1];
		value[0] = getMacBeaconTxTime();
	case MAC_BSN:
		value = new unsigned int[1];
		value[0] = getMacBSN();
	case MAC_COORD_EXTENDED_ADDRESS:
		value = new unsigned int[1];
		value[0] = getMacCoordExtendedAddress();
	case MAC_COORD_SHORT_ADDRESS:
		value = new unsigned int[1];
		value[0] = getMacCoordShortAddress();
	case MAC_DSN:
		value = new unsigned int[1];
		value[0] = getMacDSN();
	case MAC_GTS_PERMIT:
		value = new unsigned int[1];
		value[0] = getMacGTSPermit();
	case MAC_MAX_BE:
		value = new unsigned int[1];
		value[0] = getMacMaxBE();
	case MAC_MAX_CSMA_BACKOFFS:
		value = new unsigned int[1];
		value[0] = getMacMaxCSMABackoffs();
	case MAC_MAX_FRAME_TOTAL_WAIT_TIME:
		value = new unsigned int[1];
		value[0] = getMacMaxFrameTotalWaitTime();
	case MAC_MAX_FRAME_RETRIES:
		value = new unsigned int[1];
		value[0] = getMacMaxFrameRetries();
	case MAC_MIN_BE:
		value = new unsigned int[1];
		value[0] = getMacMinBE();
	case MAC_PAN_ID:
		value = new unsigned int[1];
		value[0] = getMacPANId();
	case MAC_PROMISCUOUS_MODE:
		value = new unsigned int[1];
		value[0] = getMacPromiscuousMode();
	case MAC_RESPONSE_WAIT_TIME:
		value = new unsigned int[1];
		value[0] = getMacResponseWaitTime();
	case MAC_RX_ON_WHEN_IDLE:
		value = new unsigned int[1];
		value[0] = getMacRxOnWhenIdle();
	case MAC_SECURITY_ENABLED:
		value = new unsigned int[1];
		value[0] = getMacSecurityEnabled();
	case MAC_SHORT_ADDRESS:
		value = new unsigned int[1];
		value[0] = getMacShortAddress();
	case MAC_SUPERFRAME_ORDER:
		value = new unsigned int[1];
		value[0] = getMacSuperframeOrder();
	case MAC_SYNC_SYMBOL_OFFSET:
		value = new unsigned int[1];
		value[0] = getMacSyncSymbolOffset();
	case MAC_TIMESTAMP_SUPPORTED:
		value = new unsigned int[1];
		value[0] = getMacTimestampSupported();
	case MAC_TRANSACTION_PERSISTENCE_TIME:
		value = new unsigned int[1];
		value[0] = getMacTransactionPersistenceTime();
	}
	return value;
}
