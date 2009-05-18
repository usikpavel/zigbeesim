/* -*- mode:c++ -*- ********************************************************
 * file:        BBInt.h
 *
 * author:      Bernard Halas
 *
 * copyright:   (C) 2008 Czech Technical University, Faculty of
 *              Electrical Engineering
 *
 *              This program is free software; you can redistribute it
 *              and/or modify it under the terms of the GNU General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later
 *              version.
 ***************************************************************************
 * part of:     ZigBee Simulation model
 * description: - Blackboard structure for publishing integer values
 ***************************************************************************/

#ifndef BBINT_H
#define BBINT_H

#include <omnetpp.h>

/**
 * @brief Class to create polymorphic object with integer field which is
 * publicable at on Blackboard
 *
 * @ingroup utils
 * @author Bernard Halas
 * @sa Blackboard
 **/
class BBInt : public cPolymorphic
{

private:
  /** @brief value*/
    int bbint;

public:
    int getInt() const { return bbint; }

    void setInt(int i) { bbint = i; }

  /** @brief Constructor*/
    BBInt(int i=0) : cPolymorphic(), bbint(i) {};

};


#endif
