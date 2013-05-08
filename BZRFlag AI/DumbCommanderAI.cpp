/*
 * DumbTeamAI.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "DumbCommanderAI.h"
#include "DumbTankAI.h"

DumbCommanderAI::DumbCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new DumbTankAI(connection, i));
    }
}

void DumbCommanderAI::controlTeam()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

DumbCommanderAI::~DumbCommanderAI() 
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

