/* 
 * File:   GoToBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 12, 2013, 2:29 PM
 */

#include "GoToBehavior.h"

GoToBehavior::GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : Behavior(server, tankNumber, myColor, enemies)
{
    
}

GoToBehavior::GoToBehavior(const GoToBehavior& orig) : Behavior(orig)
{
    
}

void GoToBehavior::doMove()
{
    
}

GoToBehavior::~GoToBehavior()
{
    
}

