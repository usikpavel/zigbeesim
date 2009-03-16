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

struct PANDescriptor {
	unsigned char coordAddrMode;
	unsigned short coordPANId;
	unsigned long coordAddress;
	unsigned char logicalChannel;
	unsigned char channelPage;
	unsigned short superframeSpec;
	bool GTSPermit;
	unsigned char linkQuality;
	unsigned int timeStamp;
	unsigned char securityFailure;
	unsigned char securityLevel;
	unsigned char keyIdMode;
	unsigned char keySource[8];
	unsigned char kedyIndex;
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
    PANDescriptor panDescriptorList[];
};

message McpsMsg extends cPacket {
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
    unsigned char PIBAttribute;
    unsigned int PIBAttributeValue[];
};

message PlmeSet_confirm extends PlmeMsg {
    unsigned char status;
    unsigned char PIBAttribute;
};

message PlmeEd_request extends PlmeMsg {
};

message PlmeEd_confirm extends PlmeMsg {
    unsigned char status;
    unsigned char energyLevel;
};

message PdMsg extends cPacket {
};

message PdData_request extends PdMsg {
    unsigned int psduLength;
    unsigned char psdu[];
};

message PdData_confirm extends PdMsg {
};
