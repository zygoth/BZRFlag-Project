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

BehaviorTankAI::BehaviorTankAI(BZRC* server, int tankNumber, TeamColor myColor,
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
void BehaviorTankAI::controlTank()
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
    //cout << "time for shot to hit:\t" << timeForShotToHit << endl;
    Point futureLocation = targetedEnemy->getTargetPoint(timeForShotToHit);
    double targetAngle = atan2((futureLocation.y - me.pos[1]) , (futureLocation.x - me.pos[0]));
    double angularVelocity = pdController.calculateAngularVelocity(me.angle, targetAngle);
    
    //cout << "target Location:\t" << targetLocation.x << ",\t " << targetLocation.y << endl;
    //cout << "predicted location:\t" << futureLocation.x << ",\t " << futureLocation.y << endl;
    //cout << "CURRENT:  " << me.angle << endl;
    //cout << "TARGET:   " << targetAngle << endl;
    
    connection->speed(tankNumber, 0);
    connection->angvel(tankNumber, angularVelocity * 4);// / abs(angularVelocity));
    
    if(abs(differenceBetweenTwoAngles(me.angle, targetAngle)) < .01)
    {
        connection->shoot(tankNumber);
    }
}

void BehaviorTankAI::setToDefend(Point p)
{
    this->currentPriority = DEFEND;
    this->pointToDefend = p;
}

void BehaviorTankAI::setToCapture()
{
    this->currentPriority = CAPTURE;
}

void BehaviorTankAI::setToEvade()
{
    this->currentPriority = EVADE;
}

BehaviorTankAI::~BehaviorTankAI() 
{
    
}

