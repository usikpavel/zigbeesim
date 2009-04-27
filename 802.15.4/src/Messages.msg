//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

cplusplus {{
#include "typedef.h"
}}

enum MacEnum;
enum PhyEnum;
enum FrameType;
struct NetworkDescriptor;
struct GtsDescriptor;
struct PanDescriptor;

// Application<-->Network layer interface messages
message NlmeMsg extends cPacket {
};

message NlmeNetworkFormation_request extends NlmeMsg {
    // 0x0FFFF800 for all 2.4 GHz channels
	// 0x000007FE for all 900 MHz channels
	// 0x00000001 for the 868 MHz channel
    unsigned int ScanChannels;
    unsigned char ScanDuration;
    unsigned char BeaconOrder;
    unsigned char SuperframeOrder;
    unsigned short PANId;
    unsigned char BatteryLifeExtension;
};

message NlmeNetworkFormation_confirm extends NlmeMsg {
  	unsigned char status;  
};

message NlmeNetworkDiscovery_request extends NlmeMsg {
    unsigned int ScanChannels;
    unsigned char ScanDuration;
};

message NlmeNetworkDiscovery_confirm extends NlmeMsg {
    unsigned char networkCount;
    NetworkDescriptor NetworkDescriptorList[];
    unsigned char status enum(MacEnum);
};

message NlmePermitJoining_request extends NlmeMsg {
    unsigned char permitDuration;
};

message NlmePermitJoining_confirm extends NlmeMsg {
    unsigned char status enum(MacEnum);
};

message NlmeStartRouter_request extends NlmeMsg {
    unsigned char beaconOrder;
    unsigned char superframeOrder;
    bool batteryLifeExtension;
};

message NlmeStartRouter_confirm extends NlmeMsg {
    unsigned char status enum(MacEnum); 
};

message NlmeJoin_request extends NlmeMsg {
    unsigned short panId;
    bool joinAsRouter;
    bool rejoinNetwork;
    unsigned int scanChannels;
    unsigned char scanDuration;
    bool powerSource;
    bool rxOnWhenIdle;
    bool macSecurity;
};

message NlmeJoin_indication extends NlmeMsg {
};

message NlmeJoin_confirm extends NlmeMsg {
    unsigned char status;
    unsigned short networkAddress;
    unsigned long extendedPanId;
    unsigned char currentChannel;
};

message NldeMsg extends cPacket {
};

// Network<-->Nic layer interface messages
message MlmeMsg extends cPacket {
};

message MlmeScan_request extends MlmeMsg {
    // 0x00 Energy Detection Scan (FFD only)
    // 0x01 Active Scan (FFD only)
    // 0x02 Passive Scan
    // 0x03 Orphan Only
    unsigned char scanType;
    unsigned int scanChannels;
    unsigned char scanDuration;
    unsigned char channelPage;
    unsigned char securityLevel;
    unsigned char keyIdMode;
    unsigned char keySource[];
    unsigned char kedyIndex;
};

message MlmeScan_confirm extends MlmeMsg {
    unsigned char status enum(MacEnum);
    unsigned char scanType;
    unsigned char channelPage;
    unsigned int unscannedChannels;
    unsigned int resultListSize;
    unsigned char energyDetectList[];
    PanDescriptor panDescriptorList[];
};

message MlmeSet_request extends MlmeMsg {
    unsigned char PibAttribute;
    unsigned char PibAttributeIndex;
    unsigned int PibAttributeValue[];
};

message MlmeSet_confirm extends MlmeMsg {
    unsigned char status;
    unsigned char PibAttribute;
    unsigned char PibAttributeIndex;
};

message MlmeStart_request extends MlmeMsg {
    unsigned short PanId;
    unsigned char logicalChannel;
    unsigned char channelPage;
    unsigned int startTime;
    unsigned char beaconOrder;
    unsigned char superframeOrder;
    bool panCoordinator;
    bool batteryLifeExtension;
    bool coordRealignment;
    unsigned char coordRealignSecurityLevel;
    unsigned char coordRealignKeyIdMode;
    unsigned char coordRealignKeySource[];
    unsigned char coordRealignKeyIndex;
    unsigned char beaconSecurityLevel;
    unsigned char beaconKeyIdMode;
    unsigned char beaconKeySource[];
    unsigned char beaconKeyIndex; 
};

message MlmeStart_confirm extends MlmeMsg {
    unsigned char status enum(MacEnum);
};

message MlmeAssociate_request extends MlmeMsg {
    unsigned char logicalChannel;
    unsigned char channelPage;
    unsigned char coordAddrMode;
    unsigned short coordPanId;
    unsigned long coordAddress;
	bool alternatePanCoordinator;
	bool deviceType;
	bool powerSource;
	bool receiverOnWhenIdle;
	bool securityCapability;
	bool allocateAddress;
	unsigned char securityLevel;
	unsigned char keyIdMode;
	unsigned char keySource[];
	unsigned char keyIndex;
};

message MlmeAssociate_confirm extends MlmeMsg {
};

message MlmeAssociate_indication extends MlmeMsg {
    unsigned long deviceAddress;
    bool alternatePanCoordinator;
	bool deviceType;
	bool powerSource;
	bool receiverOnWhenIdle;
	bool securityCapability;
	bool allocateAddress;
    unsigned char securityLevel;
	unsigned char keyIdMode;
	unsigned char keySource[];
	unsigned char keyIndex;
};

message MlmeAssociate_response extends MlmeMsg {
    unsigned long deviceAddress;
    unsigned short assocShortAddress;
    unsigned char status;
    unsigned char securityLevel;
    unsigned char keyIdMode;
    unsigned char keySource[];
    unsigned char keyIndex;
};

message MlmeBeaconNotify_indication extends MlmeMsg {
    unsigned char bsn;
    PanDescriptor panDescriptor;
    unsigned char numberOfShortAddressesPending;
  	unsigned char numberOfExtendedAddressesPending;
  	unsigned long addressList[];
  	unsigned int sduLength;
  	unsigned int sdu[];
};

message McpsMsg extends cPacket {
};

message MacBeacon extends McpsMsg {
  	unsigned char beaconOrder;
  	unsigned char superframeOrder;
  	unsigned char finalCapSlot;
  	bool batteryLifeExtension;
  	bool panCoordinator;
  	bool associationPermit;
  	unsigned char gtsDescriptorCount;
  	bool gtsPermit;
  	unsigned char directionMask;
  	GtsDescriptor gtsList[];
  	unsigned char numberOfShortAddressesPending;
  	unsigned char numberOfExtendedAddressesPending;
  	unsigned long addressList[];
  	unsigned int macBeaconPayload[];
};

message MacCommand extends McpsMsg {
    unsigned char commandType;
    unsigned char commandPayload[];
};

message MacAck extends McpsMsg {
    unsigned char sequenceNumber;
};

// Physical layer messages
message PlmeMsg extends cPacket {
};

message PlmeSetTrxState_request extends PlmeMsg {
    unsigned char state enum(PhyEnum);
};

message PlmeSetTrxState_confirm extends PlmeMsg {
    unsigned char status enum(PhyEnum);
};

message PlmeSet_request extends PlmeMsg {
    unsigned char PibAttribute;
    unsigned int PibAttributeValue[];
};

message PlmeSet_confirm extends PlmeMsg {
    unsigned char status;
    unsigned char PibAttribute;
};

message PlmeEd_request extends PlmeMsg {
};

message PlmeEd_confirm extends PlmeMsg {
    unsigned char status;
    unsigned char energyLevel;
};

message PlmeCca_request extends PlmeMsg {
};

message PlmeCca_confirm extends PlmeMsg {
    unsigned char status enum(PhyEnum);
};

message PdMsg extends cPacket {
    // MHR fields
    // MHR fields - FrameControl
    unsigned char frameType enum(FrameType);
    bool securityEnabled;
    bool framePending;
    bool ackRequest;
    bool panIdCompression;
    unsigned char destinationAddressingMode;
    unsigned char frameVersion;
    unsigned char sourceAddressingMode;
    // MHR fields - end of FrameControl
    unsigned char sequenceNumber;
    unsigned short destinationPanIdentifier;
    unsigned long destinationAddress;
    unsigned short sourcePanIdentifier;
    unsigned long sourceAddress;
    unsigned char auxiliarySecurityHeader[];
    unsigned short fcs;
};

message PdData_request extends PdMsg {
    unsigned int psduLength;
};

message PdData_confirm extends PdMsg {
    unsigned char status enum(PhyEnum);
};

message PdData_indication extends PdMsg {
    unsigned char psduLength;
    unsigned char ppduLinkQuality;
};

message Frame802154 extends cPacket {
    
};