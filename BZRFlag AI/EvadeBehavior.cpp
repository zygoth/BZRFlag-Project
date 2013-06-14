/* 
 * File:   EvadeBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 11, 2013, 12:08 PM
 */

#include "EvadeBehavior.h"
#include "SearchTools.h"
#include <cmath>

EvadeBehavior::EvadeBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : Behavior(server, tankNumber, myColor, enemies)
{
    myType = EVADEBEHAVIOR;
    action = 0;
}

EvadeBehavior::EvadeBehavior(const EvadeBehavior& orig) : Behavior(orig)
{
    myType = EVADEBEHAVIOR;
    action = 0;
}

void EvadeBehavior::doMove()
{
    vector<shot_t> bullets;
    connection->get_shots(&bullets);
    
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t target = myTanks.at(tankNumber);
    
    if(action < 2)
    {
        for(int i = 0; i < bullets.size(); i++)
        {
            if(SearchTools::distance(target.pos[0], target.pos[1], 
                                     bullets[i].pos[0], bullets[i].pos[1]) < SHOTRANGE);
            {
//                avoidCheck(target, bullets[i]);
            }
        }
    }
    else
    {
        // turn
    }
    if(action > 0)
    {
        // slowdown
    }
    
    bullets.clear();
    myTanks.clear();
}

EvadeBehavior::~EvadeBehavior()
{
    
}

