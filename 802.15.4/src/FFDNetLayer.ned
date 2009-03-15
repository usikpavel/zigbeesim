//***************************************************************************
// * file:        RFDNetLayer.ned
// *
// * author:      Bernard Halas
// *
// * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
// *              Technische Universitaet Berlin, Germany.
// *
// *              This program is free software; you can redistribute it 
// *              and/or modify it under the terms of the GNU General Public 
// *              License as published by the Free Software Foundation; either
// *              version 2 of the License, or (at your option) any later 
// *              version.
// *              For further information see file COPYING 
// *              in the top level directory
// ***************************************************************************
// * part of:     framework implementation developed by tkn
// * description: network layer: general class for the network layer
// *              subclass to create your own network layer
// ***************************************************************************
// * changelog:   $Revision: 260 $
// *              last modified:   $Date: 2006-04-13 17:32:54 +0200 (Do, 13 Apr 2006) $
// *              by:              $Author: koepke $
// **************************************************************************/


// Basic class for the network layer
// 
// This is the generic class for all network layer modules. If you
// want to implement your own network layer you have to subclass your
// module from this class.
//
// @author Daniel Willkomm
module FFDNetLayer
{
    gates:
        input nldeSapIn;
        output nldeSapOut;
        
        input nlmeSapIn;
        output nlmeSapOut;
        
        input mcpsSapIn;
        output mcpsSapOut;
        
        input mlmeSapIn;
        output mlmeSapOut;
    submodules:
        nwkPib: NwkPib;
        nlme: Nlme;
        nlde: Nlde;
    connections:
        // external connections
        nldeSapIn --> nlde.nldeSapIn;
        nldeSapOut <-- nlde.nldeSapOut;
        
        nlmeSapIn --> nlme.nlmeSapIn;
        nlmeSapOut <-- nlme.nlmeSapOut;
        
        mcpsSapIn --> nlde.mcpsSapIn;
        mcpsSapOut <-- nlde.mcpsSapOut;
        
        mlmeSapIn --> nlme.mlmeSapIn;
        mlmeSapOut <-- nlme.mlmeSapOut;
        
        //internal connections
        nlde.nlmeOut --> nlme.nldeIn;
        nlde.nlmeIn <-- nlme.nldeOut;
        
        nlme.nwkPibOut --> nwkPib.nlmeIn;
        nlme.nwkPibIn <-- nwkPib.nlmeOut;
}
