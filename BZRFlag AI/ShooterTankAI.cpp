/* 
 * File:   ShooterTankAI.cpp
 * Author: zygoth
 * 
 * Created on June 4, 2013, 12:01 PM
 */

#include "ShooterTankAI.h"
#include "PotentialFieldCalculator.h"

ShooterTankAI::ShooterTankAI(BZRC* server, int tankNumber, TeamColor myColor) : TankAI(server)
{
    this->tankNumber = tankNumber;
}

/**
 * 
 */
void ShooterTankAI::controlTank()
{   
    
}

ShooterTankAI::~ShooterTankAI() 
{
    
}

