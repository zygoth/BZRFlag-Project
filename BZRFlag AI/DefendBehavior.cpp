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
    DEADSTRING = "dead";
    this->myType = DEFENDBEHAVIOR;
}

DefendBehavior::DefendBehavior(const Behavior& orig) : Behavior(orig)
{
    currentTarget = NULL;
    DEADSTRING = "dead";
    this->myType = DEFENDBEHAVIOR;
}

void DefendBehavior::doMove()
{
    vector<otank_t> otherTanks;
    connection->get_othertanks(&otherTanks);
    
    tank_t me = getMyTank();
    
    // Check if the currentTarget needs to be changed

    selectTarget(&otherTanks, me);
    
    if(currentTarget == NULL)
    {
        return;
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

/**
 * Changes currentTarget to be the closest alive tank.
 * @param otherTanks
 */
void DefendBehavior::selectTarget(vector<otank_t>* otherTanks, tank_t me)
{
    Point myPosition(me.pos[0], me.pos[1]);
    Point enemyPosition;
    int minDistance = 1000000;
    
    for(int i = 0; i < otherTanks->size(); i++)
    {
        enemyPosition.x = otherTanks->at(i).pos[0];
        enemyPosition.y = otherTanks->at(i).pos[1];
        
        if(SearchTools::distance(myPosition, enemyPosition) < minDistance &&
                !DEADSTRING.compare(otherTanks->at(i).status) == 0)
        {
            currentTarget = &enemies->at(i);
        }
    }
}

DefendBehavior::~DefendBehavior()
{
    
}

