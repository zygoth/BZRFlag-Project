/* 
 * File:   DefendBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 11, 2013, 12:15 PM
 */

#include "DefendBehavior.h"

DefendBehavior::DefendBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : Behavior(server, tankNumber, myColor, enemies)
{
    
}

DefendBehavior::DefendBehavior(const DefendBehavior& orig) : Behavior(orig)
{
    
}

void DefendBehavior::doMove()
{
    
}

DefendBehavior::~DefendBehavior()
{
    
}

