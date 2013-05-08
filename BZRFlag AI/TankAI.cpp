/*
 * TankAI.cpp
 *
 *  Created on: May 4, 2013
 *      Author: Ben
 */

#include "TankAI.h"

TankAI::TankAI(BZRC* connection)
{
    this->connection = connection;
}

TankAI::TankAI(BZRC* connection, int tankNumber, TeamColor myColor, TeamColor targetColor) 
{
    this->connection = connection;
    this->tankNumber = tankNumber;
    this->myColor = myColor;
    this->targetColor = targetColor;
}

/**
 * This method should be overwritten by child classes who want to control
 * a tank.
 */
void TankAI::controlTank()
{
    
}

TankAI::~TankAI() 
{
    
}

