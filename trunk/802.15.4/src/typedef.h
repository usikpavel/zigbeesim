#ifndef TYPEDEF_H_
#define TYPEDEF_H_

/** @brief Sets the level of comments to the EV output */
typedef enum {
	COMMENT_NOTHING			= 0x0000, // 0000 0000 0000 0000
	COMMENT_INITIALIZATION	= 0x0001, // 0000 0000 0000 0001
	COMMENT_TIMER			= 0x0002, // 0000 0000 0000 0010
	COMMENT_MESSAGE			= 0x0004, // 0000 0000 0000 0100
	COMMENT_CHANNEL			= 0x0008, // 0000 0000 0000 1000
	COMMENT_STATUS			= 0x0010, // 0000 0000 0001 0000
	COMMENT_BEACON			= 0x0020, // 0000 0000 0010 0000
	COMMENT_PAN				= 0x0040, // 0000 0000 0100 0000
	COMMENT_FRAME			= 0x0080, // 0000 0000 1000 0000
	COMMENT_SUPERFRAME		= 0x0100, // 0000 0001 0000 0000
	COMMENT_ERROR			= 0x8000, // 1000 0000 0000 0000
	COMMENT_ALL 			= 0xFFFF  // 1111 1111 1111 1111
} CommentsLevel;

/** @brief Role of the node (according to ZigBee spec.) */
typedef enum {
	COORDINATOR,
	ROUTER,
	END_DEVICE
} Role;

/** @brief Kinds of messages */
typedef enum {
	DUMMY_MSG,
	/** Timers */
	TIMER_START,
	TIMER_SFD_FRAME,
	TIMER_ED_SCAN,
	TIMER_ACTIVE_SCAN,
	TIMER_PASSIVE_SCAN,
	TIMER_ORPHAN_SCAN,
	TIMER_BEACON,
	TIMER_JOINING_PERMITTED,
	TIMER_DATA_REQUEST,
	TIMER_ACK,
	TIMER_CAP_SLOT,
	TIMER_BACKOFF,
	TIMER_SUPERFRAME,
	TIMER_CCA,
	/** NLME-SAP messages */
	NLME_NETWORK_DISCOVERY_REQUEST,
	NLME_NETWORK_DISCOVERY_CONFIRM,
	NLME_NETWORK_FORMATION_REQUEST,
	NLME_NETWORK_FORMATION_CONFIRM,
	NLME_PERMIT_JOINING_REQUEST,
	NLME_PERMIT_JOINING_INDICATION,
	NLME_PERMIT_JOINING_CONFIRM,
	NLME_START_ROUTER_REQUEST,
	NLME_START_ROUTER_CONFIRM,
	NLME_JOIN_REQUEST,
	NLME_JOIN_INDICATION,
	NLME_JOIN_CONFIRM,
	NLME_DIRECT_JOIN_REQUEST,
	NLME_DIRECT_JOIN_CONFIRM,
	NLME_LEAVE_REQUEST,
	NLME_LEAVE_INDICATION,
	NLME_LEAVE_CONFIRM,
	NLME_RESET_REQUEST,
	NLME_RESET_CONFIRM,
	NLME_SYNC_REQUEST,
	NLME_SYNC_CONFIRM,
	NLME_GET_REQUEST,
	NLME_GET_CONFIRM,
	NLME_SET_REQUEST,
	NLME_SET_CONFIRM,
	/** MLME-SAP messages */
	MLME_ASSOCIATE_REQUEST,
	MLME_ASSOCIATE_INDICATION,
	MLME_ASSOCIATE_RESPONSE,
	MLME_ASSOCIATE_CONFIRM,
	MLME_DISASSOCIATE_REQUEST,
	MLME_DISASSOCIATE_INDICATION,
	MLME_DISASSOCIATE_CONFIRM,
	MLME_BEACON_NOTIFY_INDICATION,
	MLME_GET_REQUEST,
	MLME_GET_CONFIRM,
	MLME_GTS_REQUEST,
	MLME_GTS_INDICATION,
	MLME_GTS_CONFIRM,
	MLME_ORPHAN_INDICATION,
	MLME_ORPHAN_RESPONSE,
	MLME_RESET_REQUEST,
	MLME_RESET_CONFIRM,
	MLME_RX_ENABLE_REQUEST,
	MLME_RX_ENABLE_CONFIRM,
	MLME_SCAN_REQUEST,
	MLME_SCAN_CONFIRM,
	MLME_CONN_STATUS_INDICATION,
	MLME_SET_REQUEST,
	MLME_SET_CONFIRM,
	MLME_START_REQUEST,
	MLME_START_CONFIRM,
	MLME_SYNC_REQUEST,
	MLME_SYNC_LOSS_INDICATION,
	MLME_POLL_REQUEST,
	MLME_POLL_CONFIRM,
	/** MAC internal messages */
	MAC_BEACON_FRAME,
	MAC_DATA_FRAME,
	MAC_ACK_FRAME,
	MAC_COMMAND_FRAME,
	/** PLME-SAP messages */
	PLME_CCA_REQUEST,
	PLME_CCA_CONFIRM,
	PLME_ED_REQUEST,
	PLME_ED_CONFIRM,
	PLME_GET_REQUEST,
	PLME_GET_CONFIRM,
	PLME_SET_TRX_STATE_REQUEST,
	PLME_SET_TRX_STATE_CONFIRM,
	PLME_SET_REQUEST,
	PLME_SET_CONFIRM,
	/** PD-SAP messages */
	PD_DATA_REQUEST,
	PD_DATA_CONFIRM,
	PD_DATA_INDICATION
} msgTypes;

struct NwkCapabilityInformation {
	bool alternatePanCoordinator;
	/** @note 0=RFD, 1=FFD*/
	bool deviceType;
	bool powerSource;
	bool receiverOnWhenIdle;
	bool securityCapability;
	bool allocateAddress;
};

struct NetworkDescriptor {
	unsigned short panId;
	unsigned char logicalChannel;
	unsigned char stackProfile;
	unsigned char zigbeeVersion;
	unsigned char beaconOrder;
	unsigned char superframeOrder;
	bool permitJoining;
};

struct NeighborTableEntry {
	unsigned short panId;
	unsigned long extendedAddress;
	unsigned short networkAddress;
	unsigned char deviceType;
	bool rxOnWhenIdle;
	unsigned char relationship;
	unsigned char depth;
	unsigned char beaconOrder;
	bool permitJoining;
	unsigned char transmitFailure;
	bool potentialParent;
	unsigned char lqi;
	unsigned char logicalChannel;
	unsigned int incomingBeaconTimestamp;
	unsigned int beaconTransmissionTimeOffset;
};

enum relationship {
	PARENT	= 0x00,
	CHILD	= 0x01,
	SIBLING	= 0x02,
	OTHER	= 0x03
};

struct RoutingTableEntry {
	unsigned short destinationAddress;
	unsigned char status;
	unsigned short nextHopAddress;
};

/** @brief NWK PIB Enumerations */
typedef enum {
	NWK_SUCCESS 				= 0x00,
	NWK_INVALID_PARAMETER 		= 0xC1,
	NWK_INVALID_REQUEST 		= 0xC2,
	NWK_NOT_PERMITTED 			= 0xC3,
	NWK_STARTUP_FAILURE 		= 0xC4,
	NWK_ALREADY_PRESENT 		= 0xC5,
	NWK_SYNC_FAILURE 			= 0xC6,
	NWK_TABLE_FULL 				= 0xC7,
	NWK_UNKNOWN_DEVICE 			= 0xC8,
	NWK_UNSUPPORTED_ATTRIBUTE 	= 0xC9,
	NWK_NO_NETWORKS 			= 0xCA,
	NWK_LEAVE_UNCONFIRMED 		= 0xCB,
	NWK_MAX_FRM_CNTR 			= 0xCC,
	NWK_NO_KEY 					= 0xCD,
	NWK_BAD_CCM_OUTPUT 			= 0xCE
} NwkEnum;

/** @brief ScanTypes */
typedef enum {
	ED_SCAN 		= 0x00,
	ACTIVE_SCAN 	= 0x01,
	PASSIVE_SCAN 	= 0x02,
	ORPHAN_ONLY 	= 0x03
} ScanTypes;

struct GtsDescriptor {
	unsigned short deviceShortAddress;
	unsigned char gtsStartingSlot;
	unsigned char gtsLength;
};

struct MacBeaconPayload {
	unsigned short networkAddress;
	unsigned char deviceType;
	bool rxOnWhenIdle;
	unsigned char depth;
	unsigned int beaconTimestamp;
	unsigned int beaconTransmissionTimeOffset;
};

struct McpsEncapsulation {
	unsigned char frameType;
	bool securityEnabled;
	bool framePending;
	bool ackRequest;
	bool panIdCompression;
	unsigned char destinationAddressingMode;
	unsigned char frameVersion;
	unsigned char sourceAddressingMode;
	unsigned char sequenceNumber;
	unsigned short destinationPanIdentifier;
	unsigned long destinationAddress;
	unsigned short sourcePanIdentifier;
	unsigned long sourceAddress;
};

struct PanDescriptor {
	unsigned char coordAddrMode;
	unsigned short coordPanId;
	unsigned long coordAddress;
	unsigned char logicalChannel;
	unsigned char channelPage;
	unsigned char beaconOrder;
	unsigned char superframeOrder;
	unsigned char finalCapSlot;
	bool batteryLifeExtension;
	bool panCoordinator;
	bool associationPermit;
	bool gtsPermit;
	unsigned char linkQuality;
	unsigned int timeStamp;
	unsigned char securityFailure;
	unsigned char securityLevel;
	unsigned char keyIdMode;
	unsigned char keySource[8];
	unsigned char kedyIndex;
};

typedef enum {
	CAP,
	CFP,
	INACTIVE
} SuperframePeriod;

typedef enum {
	ASSOCIATION_SUCCESSFUL	= 0x00,
	PAN_AT_CAPACITY			= 0x01,
	PAN_ACCESS_DENIED		= 0x02
} AssociationStatus;

/** @brief PIB identifiers */
typedef enum {
	/** PHY PIB Identifiers */
	PHY_CURRENT_CHANNEL 				= 0x00,
	PHY_CHANNELS_SUPPORTED 				= 0x01,
	PHY_TRANSMIT_POWER 					= 0x02,
	PHY_CCA_MODE 						= 0x03,
	PHY_CURRENT_PAGE 					= 0x04,
	PHY_MAX_FRAME_DURATION 				= 0x05,
	PHY_SHR_DURATION 					= 0x06,
	PHY_SYMBOLS_PER_OCTET 				= 0x07,
	PHY_A_MAX_PHY_PACKET_SIZE			= 0x08,
	PHY_A_TURNAROUND_TIME				= 0x09,
	/** MAC PIB Identifiers */
	MAC_A_BASE_SLOT_DURATION,
	MAC_A_BASE_SUPERFRAME_DURATION,
	MAC_A_EXTENDED_ADDRESS,
	MAC_A_GTS_DESC_PERSISTENCE_TIME,
	MAC_A_MAX_BEACON_OVERHEAD,
	MAC_A_MAX_BEACON_PAYLOAD_LENGTH,
	MAC_A_MAX_LOST_BEACONS,
	MAC_A_MAX_MAC_SAFE_PAYLOAD_SIZE,
	MAC_A_MAX_MAC_PAYLOAD_SIZE,
	MAC_A_MAX_MPDU_UNSECURED_PAYLOAD,
	MAC_A_MAX_SIFS_FRAME_SIZE,
	MAC_A_MIN_CAP_LENGTH,
	MAC_A_MIN_MPDU_OVERHEAD,
	MAC_A_NUM_SUPERFRAME_SLOTS,
	MAC_A_UNIT_BACKOFF_PERIOD,
	MAC_ACK_WAIT_DURATION 				= 0x40,
	MAC_ASSOCIATED_PAN_COORD 			= 0x56,
	MAC_ASSOCIATION_PERMIT 				= 0x41,
	MAC_AUTO_REQUEST 					= 0x42,
	MAC_BATT_LIFE_EXT 					= 0x43,
	MAC_BATT_LIFE_EXT_PERIODS 			= 0x44,
	MAC_BEACON_PAYLOAD					= 0x45,
	MAC_BEACON_PAYLOAD_LENGTH 			= 0x46,
	MAC_BEACON_ORDER 					= 0x47,
	MAC_BEACON_TX_TIME 					= 0x48,
	MAC_BSN 							= 0x49,
	MAC_COORD_EXTENDED_ADDRESS 			= 0x4A,
	MAC_COORD_SHORT_ADDRESS 			= 0x4B,
	MAC_DSN 							= 0x4C,
	MAC_GTS_PERMIT 						= 0x4D,
	MAC_MAX_BE 							= 0x57,
	MAC_MAX_CSMA_BACKOFFS 				= 0x4E,
	MAC_MAX_FRAME_TOTAL_WAIT_TIME 		= 0x58,
	MAC_MAX_FRAME_RETRIES 				= 0x59,
	MAC_MIN_BE 							= 0x4F,
	MAC_PAN_ID 							= 0x50,
	MAC_PROMISCUOUS_MODE 				= 0x51,
	MAC_RESPONSE_WAIT_TIME 				= 0x5A,
	MAC_RX_ON_WHEN_IDLE 				= 0x52,
	MAC_SECURITY_ENABLED 				= 0x5D,
	MAC_SHORT_ADDRESS 					= 0x53,
	MAC_SUPERFRAME_ORDER 				= 0x54,
	MAC_SYNC_SYMBOL_OFFSET 				= 0x5B,
	MAC_TIMESTAMP_SUPPORTED 			= 0x5C,
	MAC_TRANSACTION_PERSISTENCE_TIME	= 0x55,
	/** NWK PIB Identifiers */
	NWKC_COORDINATOR_CAPABLE,
	NWKC_DEFAULT_SECURITY_LEVEL,
	NWKC_DISCOVERY_RETRY_LIMIT,
	NWKC_MAX_DEPTH,
	NWKC_MIN_HEADER_OVERHEAD,
	NWKC_PROTOCOL_VERSION,
	NWKC_REPAIR_THRESHOLD,
	NWKC_ROUTE_DISCOVERY_TIME,
	NWKC_MAX_BROADCAST_JITTER,
	NWKC_INITIAL_RREQ_RETRIES,
	NWKC_RREQ_RETRIES,
	NWKC_RREQ_RETRY_INTERVAL,
	NWKC_MIN_RREQ_JITTER,
	NWKC_MAX_RREQ_JITTER,
	NWK_SEQUENCE_NUMBER					= 0x81,
	NWK_PASSIVE_ACK_TIMEOUT				= 0x82,
	NWK_MAX_BROADCAST_RETRIES			= 0x83,
	NWK_MAX_CHILDREN					= 0x84,
	NWK_MAX_DEPTH						= 0x85,
	NWK_MAX_ROUTERS						= 0x86,
	NWK_NEIGHBOR_TABLE					= 0x87,
	NWK_NETWORK_BROADCAST_DELIVERY_TIME	= 0x88,
	NWK_REPORT_CONSTANT_COST 	= 0x89,
	NWK_ROUTE_DISCOVERY_RETRIES_PERMITTED = 0x8A,
	NWK_ROUTE_TABLE						= 0x8B,
	NWK_SYM_LINK						= 0x8E,
	NWK_CAPABILITY_INFORMATION			= 0x8F,
	NWK_USE_TREE_ADDR_ALLOC				= 0x90,
	NWK_USE_TREE_ROUTING				= 0x91,
	NWK_NEXT_ADDRESS					= 0x92,
	NWK_AVAILABLE_ADDRESSES				= 0x93,
	NWK_ADDRESS_INCREMENT				= 0x94,
	NWK_TRANSACTION_PERSISTENCE_TIME	= 0x95
} PibIdentifier;

/** @brief MAC PIB Enumerations */
typedef enum {
	MAC_SUCCESS 					= 0x00,
	MAC_BEACON_LOSS 				= 0xE0,
	MAC_CHANNEL_ACCESS_FAILURE 		= 0xE1,
	MAC_COUNTER_ERROR 				= 0xDB,
	MAC_DENIED 						= 0xE2,
	MAC_DISABLE_TRX_FEATURE 		= 0xE3,
	MAC_FRAME_TOO_LONG 				= 0xE5,
	MAC_IMPROPER_KEY_TYPE 			= 0xDC,
	MAC_IMPROPER_SECURITY_LEVEL 	= 0xDD,
	MAC_INVALID_ADDRESS 			= 0xF5,
	MAC_INVALID_GTS 				= 0xE6,
	MAC_INVALID_HANDLE 				= 0xE7,
	MAC_INVALID_INDEX 				= 0xF9,
	MAC_INVALID_PARAMETER 			= 0xE8,
	MAC_LIMIT_REACHED 				= 0xFA,
	MAC_NO_ACK 						= 0xE9,
	MAC_NO_BEACON 					= 0xEA,
	MAC_NO_DATA 					= 0xEB,
	MAC_NO_SHORT_ADDRESS 			= 0xEC,
	MAC_ON_TIME_TOO_LONG 			= 0xF6,
	MAC_OUT_OF_CAP 					= 0xED,
	MAC_PAN_ID_CONFLICT 			= 0xEE,
	MAC_PAST_TIME 					= 0xF7,
	MAC_READ_ONLY 					= 0xFB,
	MAC_REALIGNMENT 				= 0xEF,
	MAC_SCAN_IN_PROGRESS 			= 0xFC,
	MAC_SECURITY_ERROR 				= 0xE4,
	MAC_SUPERFRAME_OVERLAP 			= 0xFD,
	MAC_TRACKING_OFF 				= 0xF8,
	MAC_TRANSACTION_EXPIRED 		= 0xF0,
	MAC_TRANSACTION_OVERFLOW 		= 0xF1,
	MAC_TX_ACTIVE 					= 0xF2,
	MAC_UNAVAILABLE_KEY 			= 0xF3,
	MAC_UNSUPPORTED_ATTRIBUTE 		= 0xF4,
	MAC_UNSUPPORTED_LEGACY 			= 0xDE,
	MAC_UNSUPPORTED_SECURITY 		= 0xDF
} MacEnum;

typedef enum {
	ASSOCIATE_REQUEST				= 0x01,
	ASSOCIATE_RESPONSE				= 0x02,
	DISASSOCIATION_INDICATION		= 0x03,
	DATA_REQUEST					= 0x04,
	PAN_ID_CONFLICT_NOTIFIACTION	= 0x05,
	ORPHAN_NOTIFICATION				= 0x06,
	BEACON_REQUEST					= 0x07,
	COORDINATOR_REALIGNMENT			= 0x08,
	GTS_REQUEST						= 0x09
} CommandFrameIdentifier;

typedef enum {
	BEACON		= 0x00,
	DATA		= 0x01,
	ACK			= 0x02,
	COMMAND		= 0x03
} FrameType;

typedef enum {
	NOT_PRESENT		= 0x00,
	SHORT_ADDRESS	= 0x02,
	LONG_ADDRESS	= 0x03
} AddressingMode;

/** @brief PHY PIB Enumerations */
typedef enum {
	PHY_BUSY 					= 0x00,
	PHY_BUSY_RX 				= 0x01,
	PHY_BUSY_TX 				= 0x02,
	PHY_FORCE_TRX_OFF 			= 0x03,
	PHY_IDLE 					= 0x04,
	PHY_INVALID_PARAMETER 		= 0x05,
	PHY_RX_ON 					= 0x06,
	PHY_SUCCESS 				= 0x07,
	PHY_TRX_OFF 				= 0x08,
	PHY_TX_ON 					= 0x09,
	PHY_UNSUPPORTED_ATTRIBUTE 	= 0x0A,
	PHY_READ_ONLY 				= 0x0B
} PhyEnum;

#endif /* TYPEDEF_H_ */
