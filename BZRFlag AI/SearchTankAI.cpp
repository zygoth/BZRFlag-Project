/* 
 * File:   SearchTankAI.cpp
 * Author: zygoth
 * 
 * Created on May 22, 2013, 3:26 PM
 */

#include "SearchTankAI.h"

SearchTankAI::SearchTankAI(BZRC* connection, int tankNumber, TeamColor myColor, GridFilter* filter) 
                : TankAI(connection, tankNumber, myColor, myColor)
{
    controller = new PDController();
    targetGenerator = new TargetPointCalculator(0,0);
    PFCalculator = new PotentialFieldCalculator(connection);
    settledGrid = filter;
}

void SearchTankAI::controlTank()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t myTank = myTanks[tankNumber];
    
    //get target point
    //Point target = targetGenerator->getTarget(myTank.pos[0], myTank.pos[1], fliter->)
    
    //TankVector* newVector = PFCalculator->calculateSearcherVector(targetX, targetY, tankNumber);
    
    // Calculate Speed
    //connection->speed(tankNumber, newVector->getVelocity());
    
    // Calculate angularVelocity
    
    //double newVelocity = controller->calculateAngularVelocity(myTank.angle, newVector->getAngle());
    //connection->angvel(tankNumber, newVelocity);
    
    //update settledGrid
    
    //delete newVector;
}

SearchTankAI::~SearchTankAI()
{
    delete PFCalculator;
    delete controller;
    delete targetGenerator;
    delete settledGrid;
}

