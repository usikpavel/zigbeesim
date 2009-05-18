/* -*- mode:c++ -*- ********************************************************
 * file:        SnrDecider802154.h
 *
 * author:      Bernard Halas
 *
 * copyright:   (C) 2009 Czech Technical University, Faculty of
 *              Electrical Engineering
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 ***************************************************************************
 * part of:     ZigBee Simulation model
 * description: - Module handling the message error detection
 ***************************************************************************
 * based on:    SnrDecider.h
 *
 * author:      Marc Loebbers
 *
 * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
 *              Technische Universitaet Berlin, Germany.
 ***************************************************************************/

#include "SnrDecider802154.h"
#include "AirFrame_m.h"
#include "FWMath.h"


Define_Module(SnrDecider802154);


void SnrDecider802154::initialize(int stage)
{
    BasicDecider::initialize(stage);

    if (stage == 0) {
        snrThresholdLevel = FWMath::dBm2mW(par("snrThresholdLevel"));
    }
}


/**
 *  Checks the received sduList (from the PhySDU header) if it contains an
 *  snr level above the threshold
 */
bool SnrDecider802154::snrOverThreshold(const SnrList& snrlist) const
{
    bool rval = true;
    for(SnrList::const_iterator iter = snrlist.begin(); iter != snrlist.end(); ++iter)
    {
        if (iter->snr <= snrThresholdLevel) {
            EV << "Message got lost. MessageSnr: " << iter->snr
               << " Threshold: " << snrThresholdLevel << endl;
            rval = false;
            break;
        }
    }
    return rval;
}

void SnrDecider802154::handleLowerMsg(AirFrame *af, const SnrList& receivedList)
{
    if(snrOverThreshold(receivedList)) {
        EV << "Message handed on to Pd\n";
        sendUp(af->decapsulate());
    }
    delete af;
}
