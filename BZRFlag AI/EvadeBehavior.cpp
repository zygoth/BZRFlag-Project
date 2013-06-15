/* 
 * File:   EvadeBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 11, 2013, 12:08 PM
 */

#include "EvadeBehavior.h"
#include "SearchTools.h"
#include "BZRCTools.h"
#include "PotentialFieldCalculator.h"
#include <cmath>

EvadeBehavior::EvadeBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, 
                UniformCostArraySearcher* pathFinder) : Behavior(server, tankNumber, myColor, enemies)
{
    myType = EVADEBEHAVIOR;
    action = 0;
    path = pathFinder;
}

EvadeBehavior::EvadeBehavior(const Behavior& orig, UniformCostArraySearcher* pathFinder) : Behavior(orig)
{
    myType = EVADEBEHAVIOR;
    action = 0;
    path = pathFinder;
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
            if(BZRCTools::hitCheck(target, bullets[i], SHOTRANGE, path))
            {
                double angle = atan2((bullets[i].pos[1] - target.pos[1]), 
                                     (bullets[i].pos[0] - target.pos[0]));
                angle = PotentialFieldCalculator::getAngleBetween(angle, target.angle);
                
                if(abs(angle) < 3.14159/4)
                {
                    if(angle > 0)
                        targetAngle = PotentialFieldCalculator::getAngleBetween(target.angle-3.14159/2, 0.0);
                    else
                        targetAngle = PotentialFieldCalculator::getAngleBetween(target.angle+3.14159/2, 0.0);
                    action = 2;
                }
                else if (abs(angle) > 3.14159 * 3/4)
                {
                    if(angle > 0)
                        targetAngle = PotentialFieldCalculator::getAngleBetween(target.angle+3.14159/2, 0.0);
                    else
                        targetAngle = PotentialFieldCalculator::getAngleBetween(target.angle-3.14159/2, 0.0);
                    action = 2;                    
                }
                else
                    action = 1;
            }
        }
    }
    if(action == 2)
    {
        double angularVelocity = pdController.calculateAngularVelocity(target.angle, targetAngle);
        connection->angvel(tankNumber, angularVelocity);
    }
    if(action == 1)
    {
        connection->speed(tankNumber,0.1);
    }
    
    bullets.clear();
    myTanks.clear();
}

EvadeBehavior::~EvadeBehavior()
{
    
}

