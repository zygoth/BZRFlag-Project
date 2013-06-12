/* 
 * File:   GoToBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 12, 2013, 2:29 PM
 */

#include "GoToBehavior.h"

GoToBehavior::GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder)
                : Behavior(server, tankNumber, myColor, enemies)
{
    this->pathFinder = pathFinder;
}

GoToBehavior::GoToBehavior(const GoToBehavior& orig, UniformCostArraySearcher* pathFinder) : Behavior(orig)
{
    this->pathFinder = pathFinder;
}

void GoToBehavior::doMove()
{
    
}

GoToBehavior::~GoToBehavior()
{
    
}

