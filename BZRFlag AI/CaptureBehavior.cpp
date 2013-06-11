/* 
 * File:   CaptureBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 11, 2013, 12:19 PM
 */

#include "CaptureBehavior.h"

CaptureBehavior::CaptureBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : Behavior(server, tankNumber, myColor, enemies)
{
    
}

CaptureBehavior::CaptureBehavior(const CaptureBehavior& orig) : Behavior(orig)
{
    
}

void CaptureBehavior::doMove()
{
    
}

CaptureBehavior::~CaptureBehavior()
{
    
}

