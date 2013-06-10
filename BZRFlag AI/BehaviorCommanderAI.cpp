/* 
 * File:   BehaviorCommanderAI.cpp
 * Author: zygoth
 * 
 * Created on June 10, 2013, 1:59 PM
 */

#include "BehaviorCommanderAI.h"
#include "BehaviorTankAI.h"

BehaviorCommanderAI::BehaviorCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<otank_t> otherTanks;
    connection->get_othertanks(&otherTanks);
    
    for(int i = 0; i < otherTanks.size(); i++)
    {
        TankTargeter t(connection, i);
        tankTargeters.push_back(t);
    }
    
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new BehaviorTankAI(connection, i, myColor, &tankTargeters));
    }    
}

void BehaviorCommanderAI::controlTeam()
{    
    /**
     * Update enemy positions
     */
    for(int i = 0; i < tankTargeters.size(); i++)
    {
        tankTargeters[i].update();
    }
    
    /**
     * Control the individual tanks
     */
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

BehaviorCommanderAI::~BehaviorCommanderAI() 
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

