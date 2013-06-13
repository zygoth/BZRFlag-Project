/* 
 * File:   Behavior.cpp
 * Author: zygoth
 * 
 * Created on June 10, 2013, 2:22 PM
 */

#include "Behavior.h"

Behavior::Behavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies)
{
    connection = server;
    this->myColor = myColor;
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

Behavior::Behavior(const Behavior& other)
{
    this->connection = other.connection;
    this->myColor = other.myColor;
    this->tankNumber = other.tankNumber;
    this->enemies = other.enemies;
    this->SHOTRANGE = other.SHOTRANGE;
    this->SHOTSPEED = other.SHOTSPEED;
}

Behavior_t Behavior::getType()
{
    return myType;
}

void Behavior::doMove()
{
    
}

tank_t Behavior::getMyTank()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t me = myTanks.at(tankNumber);
    
    return me;
}

Behavior::~Behavior()
{
}

