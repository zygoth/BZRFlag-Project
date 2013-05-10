/* 
 * File:   PotentialFieldTankAI.cpp
 * Author: zygoth
 * 
 * Created on May 8, 2013, 11:17 AM
 */

#include "PotentialFieldTankAI.h"
#include <cmath>
#include <cstdlib>

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
    
    TankVector* newVector = fieldCalculator->calculateVector(myTank.pos[0], myTank.pos[1], targetColor, tankNumber);
    
    //Calculate Speed
    
    // Reduce the speed if the discrepancy is high
    //double discrepancy = abs(differenceBetweenTwoAngles(myTank.angle, newVector->getAngle()));
    //double speedMultiplier = .1;
    //if(discrepancy < 1.5)speedMultiplier = 1;
    connection->speed(tankNumber, newVector->getVelocity());
    
    // Calculate angularVelocity
    
    double newVelocity = pdController->calculateAngularVelocity(myTank.angle, newVector->getAngle());
    connection->angvel(tankNumber, newVelocity);
    
    // Shoot all the time
    
    connection->shoot(tankNumber);
    
    delete newVector;
}

PotentialFieldTankAI::~PotentialFieldTankAI()
{
    delete fieldCalculator;
    delete pdController;
}

