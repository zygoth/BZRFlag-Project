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
#include "BZRCTools.h"

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
    
     switch(currentPriority)
             
     {
        case CAPTURE: doCapture(); break;
        case DEFEND:  doDefend(); break;
        //case EVADE:  doEvade(); break;
     }
        
     currentBehavior->doMove();
    //currentBehavior->doMove();
}

void BehaviorTankAI::doCapture()
{    
    // TODO: if we're in danger, switch to evasion mode
    
    // Start them going towards the flag, or towards the enemy base if the flag
    // is already captured.
    flag_t enemyFlag;
    Point targetPoint;
    
    tank_t me = getMyTank();
    bool iHaveFlag = !(me.flag.compare("-") == 0);
    vector<flag_t> flags;
    connection->get_flags(&flags);
    
    
    for(int i = 0; i < flags.size(); i++)
    {
        if(stringToTeamColor(flags[i].color) == myColor)
        {
            continue;
        }
        
        if(flags[i].poss_color.compare("none") != 0 && !iHaveFlag) // somebody else has the flag, so camp at enemy base
        {
            vector<base_t> bases;
            connection->get_bases(&bases);
            
            for(int j = 0; j < bases.size(); j++)
            {
                if(stringToTeamColor(bases[j].color) == stringToTeamColor(flags[i].color))
                {
                    targetPoint = Point(bases[j].base_corner[0][0], bases[j].base_corner[0][1]);
                }
            }
        }
        else
        {
            if(iHaveFlag) // GO HOME!!!!
            {
                base_t myBase = BZRCTools::getBase(connection, myColor);
                targetPoint = Point(myBase.base_corner[0][0] + 10, myBase.base_corner[0][1] + 10);
            }
            else  // Grab the enemy flag!
            {
                targetPoint = Point(flags[i].pos[0], flags[i].pos[1]);
            }
        }
    }    
    
    // if the current behavior is different, change it.
    if(!(currentBehavior->getType() == GOTOBEHAVIOR) || 
            !(targetPoint.Compare( ((GoToBehavior*)currentBehavior) -> targetPoint) == 0))
    {
        Behavior* newBehavior = new GoToBehavior(*currentBehavior, pathFinder, targetPoint);
        delete currentBehavior;
        currentBehavior = newBehavior;
    }
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

