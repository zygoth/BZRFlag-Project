/* 
 * File:   GoToBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 12, 2013, 2:29 PM
 */

#include "GoToBehavior.h"

GoToBehavior::GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder,
                Point targetPoint)
                : Behavior(server, tankNumber, myColor, enemies)
{
    this->pathFinder = pathFinder;
    this->targetPoint = targetPoint;
}

GoToBehavior::GoToBehavior(const Behavior& orig, UniformCostArraySearcher* pathFinder, 
                           Point targetPoint) : Behavior(orig)
{
    this->pathFinder = pathFinder;
    this->targetPoint = targetPoint;
}

void GoToBehavior::doMove()
{
    
}

GoToBehavior::~GoToBehavior()
{
    
}

