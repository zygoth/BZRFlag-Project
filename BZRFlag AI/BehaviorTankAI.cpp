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
#include "DefendBehavior.h"
#include "EvadeBehavior.h"

BehaviorTankAI::BehaviorTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder) : TankAI(server)
{
    this->tankNumber = tankNumber;
    this->enemies = enemies;
    this->pathFinder = pathFinder;
    this->currentPriority = CAPTURE;
    this->currentBehavior = new GoToBehavior(server, tankNumber, myColor, enemies, pathFinder, Point(30,-60));
    
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

void BehaviorTankAI::doCapture()
{
    
}

void BehaviorTankAI::doDefend()
{
    tank_t me = getMyTank();
    Point myLocation(me.pos[0], me.pos[1]);
    
    //  if we're close, start the defense behavior
    if(SearchTools::distance(myLocation, pointToDefend) < 10 && 
            currentBehavior->getType() != DEFENDBEHAVIOR)
    {
        Behavior* newBehavior = new DefendBehavior(*currentBehavior);
        delete currentBehavior;
        currentBehavior = newBehavior;
    }
}

void BehaviorTankAI::setToDefend(Point p)
{
    this->currentPriority = DEFEND;
    this->pointToDefend = p;
    
    
    // Start them going towards the point to defend.
    Behavior* newBehavior = new GoToBehavior(*currentBehavior, pathFinder, p);
    delete currentBehavior;
    currentBehavior = newBehavior;
}

void BehaviorTankAI::setToCapture()
{
    this->currentPriority = CAPTURE;
}

void BehaviorTankAI::setToEvade()
{
    this->currentPriority = EVADE;
}

tank_t BehaviorTankAI::getMyTank()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t me = myTanks.at(tankNumber);
    
    return me;
}

BehaviorTankAI::~BehaviorTankAI() 
{
    
}

