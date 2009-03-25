//***************************************************************************
//* file:        CSMAMacLayer.ned
//*
//* author:      Marc L�bbers
//*
//* copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
//*              Technische Universitaet Berlin, Germany.
//*
//*              This program is free software; you can redistribute it
//*              and/or modify it under the terms of the GNU General Public
//*              License as published by the Free Software Foundation; either
//*              version 2 of the License, or (at your option) any later
//*              version.
//*              For further information see file COPYING
//*              in the top level directory
//***************************************************************************
//* part of:     framework implementation developed by tkn
//* description: MAC layer class for the CSMAMac
//**************************************************************************/


//
// 802.15.4 MAC protocol
//
module Mac802154
{
    gates:
        input mcpsSapIn;
        output mcpsSapOut;

        input mlmeSapIn;
        output mlmeSapOut;

        input pdSapIn;
        output pdSapOut;

        input plmeSapIn;
        output plmeSapOut;
    submodules:
        mcps: Mcps;
        macPib: MacPib;
        mlme: Mlme;
    connections:
        // external connections
        mcpsSapIn --> mcps.mcpsSapIn;
        mcpsSapOut <-- mcps.mcpsSapOut;

        mlmeSapIn --> mlme.mlmeSapIn;
        mlmeSapOut <-- mlme.mlmeSapOut;

        pdSapIn --> mcps.pdSapIn;
        pdSapOut <-- mcps.pdSapOut;

        plmeSapIn --> mlme.plmeSapIn;
        plmeSapOut <-- mlme.plmeSapOut;

        // internal connections
        mcps.mlmeOut --> mlme.mcpsIn;
        mcps.mlmeIn <-- mlme.mcpsOut;

		mlme.macPibOut --> macPib.mlmeIn;
		mlme.macPibIn <-- macPib.mlmeOut;
}
