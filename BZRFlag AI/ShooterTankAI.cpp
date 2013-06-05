/* 
 * File:   ShooterTankAI.cpp
 * Author: zygoth
 * 
 * Created on June 4, 2013, 12:01 PM
 */

#include "ShooterTankAI.h"
#include "PotentialFieldCalculator.h"
#include "Point.h"
#include "SearchTools.h"
#include "PDController.h"

ShooterTankAI::ShooterTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : TankAI(server)
{
    this->tankNumber = tankNumber;
    this->enemies = enemies;
    
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
 * Shoots at the first enemy in the enemy list.
 */
void ShooterTankAI::controlTank()
{   
    if(enemies->empty())
    {
        return;
    }
    
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t me = myTanks.at(tankNumber);
    TankTargeter* targetedEnemy = &(enemies->front());
    
    Point targetLocation = targetedEnemy->getCurrentPoint();
    double distanceToEnemy = SearchTools::distance(me.pos[0], me.pos[1], targetLocation.x, targetLocation.y);
    double timeForShotToHit = distanceToEnemy / SHOTSPEED;
    Point futureLocation = targetedEnemy->getTargetPoint(timeForShotToHit);    
    double targetAngle = atan2((futureLocation.y - me.pos[1]) , (futureLocation.x - me.pos[0]));    
    double angularVelocity = pdController.calculateAngularVelocity(me.angle, targetAngle);
    
    
    connection->speed(tankNumber, 0);
    connection->angvel(tankNumber, angularVelocity);
    
    if(abs(differenceBetweenTwoAngles(me.angle, targetAngle)) < .1)
    {
        connection->shoot(tankNumber);
    }
}

ShooterTankAI::~ShooterTankAI() 
{
    
}

