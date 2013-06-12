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
    tank_t me = getMyTank();
    Point myPosition = Point(me.pos[0], me.pos[1]);
    double currentAngle = me.angle;
    
    pathFinder->search(myPosition, targetPoint, &intermediatePoint, 20);    
    
    double targetAngle = atan2((intermediatePoint.y - myPosition.y) , (intermediatePoint.x - myPosition.x));
    double angularVelocity = pdController.calculateAngularVelocity(currentAngle, targetAngle);
    double speed;
    if(abs(differenceBetweenTwoAngles(currentAngle, targetAngle)) < 1)
    {
        speed = 1;
    }
    else
    {
        speed = 0;
    }
    
    connection->speed(tankNumber, speed);
    connection->angvel(tankNumber, angularVelocity);
}

GoToBehavior::~GoToBehavior()
{
    
}

