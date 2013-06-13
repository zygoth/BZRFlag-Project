/* 
 * File:   BehaviorTankAI.cpp
 * Author: zygoth
 * 
 * Created on June 10, 2013, 2:02 PM
 */

#include "BehaviorTankAI.h"
#include "PotentialFieldCalculator.h"
#include "Point.h"
#include "SearchTools.h"
#include "PDController.h"
#include "GoToBehavior.h"

BehaviorTankAI::BehaviorTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder) : TankAI(server)
{
    this->tankNumber = tankNumber;
    this->enemies = enemies;
    this->pathFinder = pathFinder;
    this->currentPriority = CAPTURE;
    this->currentBehavior = new GoToBehavior(server, tankNumber, myColor, enemies, pathFinder, Point(0,0));
    
    vector<constant_t> constants;
    connection->get_constants(&constants);
    
    string shotSpeed = "shotspeed";
    string shotRange = "shotrange";
    for(int i = 0; i < constants.size(); i++)
    {
        if(shotSpeed.compare(constants[i].name) == 0)
        {
            SHOTSPEED = atoi(constants[i].value.c_str());
        }
        
        if(shotRange.compare(constants[i].name) == 0)
        {
            SHOTRANGE = atoi(constants[i].value.c_str());
        }
    }
}

/**
 * 
 */
void BehaviorTankAI::controlTank()
{   
    /**
     * switch(currentPriority)
     *  case CAPTURE: doCapture()
     *  case DEFEND:  doDefense()
     *  case EVADE:  doEvade()
     * 
     * 
     */
    currentBehavior->doMove();
}

void BehaviorTankAI::setToDefend(Point p)
{
    this->currentPriority = DEFEND;
    this->pointToDefend = p;
}

void BehaviorTankAI::setToCapture()
{
    this->currentPriority = CAPTURE;
}

void BehaviorTankAI::setToEvade()
{
    this->currentPriority = EVADE;
}

BehaviorTankAI::~BehaviorTankAI() 
{
    
}

