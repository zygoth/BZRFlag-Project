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
    PFCalculator = new PotentialFieldCalculator(connection);
    
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t myTank = myTanks[tankNumber];
    
    targetGenerator = new TargetPointCalculator(myTank.pos[0] + filter->getGrid().width/2.0, 
                                                myTank.pos[1] + filter->getGrid().height/2.0);
    settledGrid = filter;
    
    myTanks.clear();
}

void SearchTankAI::controlTank()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t myTank = myTanks[tankNumber];
    
    //get target point
    int height = settledGrid->getGrid().height;
    int width = settledGrid->getGrid().width;
    Point target = targetGenerator->getTarget(myTank.pos[0] + width/2, myTank.pos[1] + height/2, settledGrid->getGrid());
    int x = target.x - width/2;
    int y = target.y - height/2;
    
    TankVector* newVector = PFCalculator->calculateSearcherVector(x, y, tankNumber);
    
    // Calculate Speed
    int xDistance = x - myTank.pos[0];
    int yDistance = y - myTank.pos[1];
    if(abs(xDistance) < 25 && abs(yDistance) < 25)
        connection->speed(tankNumber, 0.0);
    else
        connection->speed(tankNumber, newVector->getVelocity());
    
    // Calculate angularVelocity
    
    double newVelocity = controller->calculateAngularVelocity(myTank.angle, newVector->getAngle());
    connection->angvel(tankNumber, newVelocity);
    
    // update the settledGrid
    vector<grid_t> tankMap;
    
//    if(abs(xDistance) < 50 && abs(yDistance) < 50)
//    {
        connection->get_occgrid(&tankMap, tankNumber);
        settledGrid->addInput(tankMap.at(0));
//    }
    
    delete newVector;
}

SearchTankAI::~SearchTankAI()
{
    delete PFCalculator;
    delete controller;
    delete targetGenerator;
    delete settledGrid;
}

