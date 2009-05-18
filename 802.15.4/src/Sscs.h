/* -*- mode:c++ -*- ********************************************************
 * file:        Sscs.h
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
 * description: - Module describing the behaviour of the sscs layer
 ***************************************************************************/
#ifndef __SSCS_H__
#define __SSCS_H__

#include <omnetpp.h>

/**
 * TODO - Generated class
 */
class Sscs : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
