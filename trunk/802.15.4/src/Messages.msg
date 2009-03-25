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

enum PhyEnum;
enum MacEnum;
struct PanDescriptor;

// Application<-->Network layer interface messages
message NlmeMsg extends cMessage {
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
    
};

message NldeMsg extends cMessage {
};

// Network<-->Nic layer interface messages
message MlmeMsg extends cMessage {
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
    unsigned int logicalChannel;
    unsigned char channelPage;
    unsigned int startTime;
    unsigned char beaconOrder;
    unsigned char superFrameOrder;
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

message McpsMsg extends cPacket {
};

message MacCommand extends McpsMsg {
    unsigned char commandType;
    unsigned char commandPayload[];
};

message MacBeacon extends McpsMsg {
};

// Physical layer messages
message PlmeMsg extends cMessage {
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

message PdMsg extends cPacket {
    // MHR fields
    // MHR fields - FrameControl
    unsigned char frameType;
    bool securityEnabled;
    bool framePending;
    bool ackRequest;
    bool panIdCompression;
    char destinationAddressingMode;
    char frameVersion;
    char sourceAddressingMode;
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

message Frame802154 extends cPacket {
    
};