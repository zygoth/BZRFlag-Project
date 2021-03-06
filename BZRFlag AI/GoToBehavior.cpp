/* 
 * File:   GoToBehavior.cpp
 * Author: zygoth
 * 
 * Created on June 12, 2013, 2:29 PM
 */

#include "GoToBehavior.h"
#include "SearchTools.h"

GoToBehavior::GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder,
                Point targetPoint)
                : Behavior(server, tankNumber, myColor, enemies)
{
    this->pathFinder = pathFinder;
    this->targetPoint = targetPoint;
    this->myType = GOTOBEHAVIOR;
    
    tank_t me = getMyTank();
    this->intermediatePoint = Point(me.pos[0], me.pos[1]);
}

GoToBehavior::GoToBehavior(const Behavior& orig, UniformCostArraySearcher* pathFinder, 
                           Point targetPoint) : Behavior(orig)
{
    this->pathFinder = pathFinder;
    this->targetPoint = targetPoint;
    this->myType = GOTOBEHAVIOR;
    
    tank_t me = getMyTank();
    this->intermediatePoint = Point(me.pos[0], me.pos[1]);
}

void GoToBehavior::doMove()
{
    tank_t me = getMyTank();
    Point myPosition = Point(me.pos[0], me.pos[1]);
    double currentAngle = me.angle;
    
    //if(SearchTools::distance(myPosition, intermediatePoint) < 15)
    //searchCounter++;
    //if(searchCounter % 5 == 0)
    {
        if(pathFinder->search(myPosition, targetPoint, &intermediatePoint, 1) == false)
        {
            //cout << "couldn't find path" << endl;
        }
        else
        {
           //cout << "found path" << endl;
        }
    }
    
    double targetAngle = atan2((intermediatePoint.y - myPosition.y) , (intermediatePoint.x - myPosition.x));
    double angularVelocity = pdController.calculateAngularVelocity(currentAngle, targetAngle);
    double speed;
    if(abs(differenceBetweenTwoAngles(currentAngle, targetAngle)) < .9)
    {
        speed = 1;
    }
    else
    {
        speed = .3;
    }
    
    if(SearchTools::distance(myPosition, targetPoint) < 30)
    {
        speed = .2;
        //cout << "I have arrived!" << endl;
    }
    
    //If we're too close to an ally, move away    
     vector<tank_t> mytanks;
     connection->get_mytanks(&mytanks);
     for(int i = 0; i < mytanks.size(); i++)
     {
         if(i == tankNumber)
         {
             continue;
         }
         
         if(SearchTools::distance(Point(me.pos[0], me.pos[1]), Point(mytanks[i].pos[0], mytanks[i].pos[1])) < 12)
         {
             angularVelocity = .5;
         }
     }
     

    
    connection->speed(tankNumber, speed);
    connection->angvel(tankNumber, angularVelocity);
}

GoToBehavior::~GoToBehavior()
{
    
}

