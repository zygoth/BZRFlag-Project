/*
 * TeamAI.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "TeamAI.h"
#include "TankAI.h"

TeamAI::TeamAI(BZRC* connection)
{
    this->connection = connection;
}

/**
 * This method should be implemented by subclasses to control the team of
 * tanks.
 */
void TeamAI::controlTeam()
{
    
}

TeamAI::~TeamAI()
{
    // TODO Auto-generated destructor stub
}

