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

void Behavior::doMove()
{
    
}

Behavior::~Behavior()
{
}

