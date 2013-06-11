/* 
 * File:   EvadeBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 11, 2013, 12:08 PM
 */

#include "EvadeBehavior.h"

EvadeBehavior::EvadeBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : Behavior(server, tankNumber, myColor, enemies)
{
    
}

EvadeBehavior::EvadeBehavior(const EvadeBehavior& orig) : Behavior(orig)
{
    
}

void EvadeBehavior::doMove()
{
    
}

EvadeBehavior::~EvadeBehavior()
{
    
}

