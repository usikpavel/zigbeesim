/* -*- mode:c++ -*- ********************************************************
 * file:        SnrDecider.cc
 *
 * author:      Marc Loebbers, Andreas Koepke
 *
 * copyright:   (C) 2004 Telecommunication Networks Group (TKN) at
 *              Technische Universitaet Berlin, Germany.
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 *              For further information see file COPYING
 *              in the top level directory
 ***************************************************************************
 * part of:     framework implementation developed by tkn
 **************************************************************************/

#include "SnrDecider802154.h"
#include "AirFrame_m.h"
#include "FWMath.h"


Define_Module(SnrDecider802154);


void SnrDecider802154::initialize(int stage)
{
    SnrDecider::initialize(stage);

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
        EV << "Message handed on to Mac\n";
        sendUp(af->decapsulate());
    }
    delete af;
}
