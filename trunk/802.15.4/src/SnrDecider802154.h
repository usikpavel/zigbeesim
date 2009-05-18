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


#ifndef SNR_DECIDER802154_H
#define SNR_DECIDER802154_H

#include <BasicDecider.h>

/**
 * @brief a simple snr decider...
 *
 * This decider simply takes a look at the sduList contained in the
 * received PhySDU packet and checks whether one of the mentioned snr
 * levels is lower than the snrThresholdLevel which has to be read in at
 * the beginning of a simulation. (suggestion: from the omnetpp.ini
 * file!)
 *
 * @author Marc L�bbers, Andreas Koepke
 *
 * @ingroup decider
 */
class  SnrDecider802154 : public BasicDecider
{
  protected:
    /** @brief Level for decision [mW]
     *
     * When a packet contains an snr level higher than snrThresholdLevel it
     * will be considered as lost. This parameter has to be specified at the
     * beginning of a simulation (omnetpp.ini) in dBm.
     */
    double snrThresholdLevel;

  public:

    virtual void initialize(int);

  protected:
    bool snrOverThreshold(const SnrList &) const;
    virtual void handleLowerMsg(AirFrame*, const SnrList &);

    virtual void handleSelfMsg( cMessage *msg ){
	error("SnrDecider does not handle self messages\n");
    };
};

#endif
