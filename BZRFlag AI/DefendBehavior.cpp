/* 
 * File:   DefendBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 11, 2013, 12:15 PM
 */

#include "DefendBehavior.h"
#include "SearchTools.h"

DefendBehavior::DefendBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies) : Behavior(server, tankNumber, myColor, enemies)
{
    currentTarget = NULL;
}

DefendBehavior::DefendBehavior(const DefendBehavior& orig) : Behavior(orig)
{
    currentTarget = NULL;
}

void DefendBehavior::doMove()
{
    vector<otank_t> otherTanks;
    connection->get_othertanks(&otherTanks);
    string DEADSTRING = "dead";
    tank_t me = getMyTank();
    
    // Check if the currentTarget needs to be changed
    // Change it if we have no target, if the enemy tank is already dead, or
    // the tank is out of range.
    if(currentTarget == NULL || DEADSTRING.compare(otherTanks[currentTarget->getTankIndex()].status) == 0)
    {
        selectTarget();
    }
    
    // Aim and fire
    
    Point targetLocation = currentTarget->getCurrentPoint();
    double distanceToEnemy = SearchTools::distance(me.pos[0], me.pos[1], targetLocation.x, targetLocation.y);
    double timeForShotToHit = distanceToEnemy / SHOTSPEED;
    Point futureLocation = currentTarget->getTargetPoint(timeForShotToHit);
    double targetAngle = atan2((futureLocation.y - me.pos[1]) , (futureLocation.x - me.pos[0]));
    double angularVelocity = pdController.calculateAngularVelocity(me.angle, targetAngle);
    
    connection->speed(tankNumber, 0);
    connection->angvel(tankNumber, angularVelocity * 4);// / abs(angularVelocity));
    
    if(abs(differenceBetweenTwoAngles(me.angle, targetAngle)) < .01)
    {
        connection->shoot(tankNumber);
    }
}

void DefendBehavior::selectTarget()
{
    
}

DefendBehavior::~DefendBehavior()
{
    
}

