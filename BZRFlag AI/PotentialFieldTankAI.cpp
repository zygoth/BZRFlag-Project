/* 
 * File:   PotentialFieldTankAI.cpp
 * Author: zygoth
 * 
 * Created on May 8, 2013, 11:17 AM
 */

#include "PotentialFieldTankAI.h"

PotentialFieldTankAI::PotentialFieldTankAI(BZRC* connection, int tankNumber, TeamColor myColor, TeamColor targetColor) 
                        : TankAI(connection, tankNumber, myColor, targetColor)
{
    fieldCalculator = new PotentialFieldCalculator(connection);
    pdController = new PDController();
}

void PotentialFieldTankAI::controlTank()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t myTank = myTanks[tankNumber];
    
    TankVector* newVector = fieldCalculator->calculateVector(myTank.pos[0], myTank.pos[1], myColor);
    
    connection->speed(tankNumber, newVector->getVelocity());
    
    double newVelocity = pdController->calculateAngularVelocity(myTank.angle, newVector->getAngle());
    connection->angvel(tankNumber, newVelocity);
    
    delete newVector;
}

PotentialFieldTankAI::~PotentialFieldTankAI()
{
    delete fieldCalculator;
    delete pdController;
}

