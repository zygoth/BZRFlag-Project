/*
 * DumbTeamAI.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "DumbTeamAI.h"
#include "DumbTankAI.h"

DumbTeamAI::DumbTeamAI(BZRC* connection) : TeamAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new DumbTankAI(connection, i));
    }
}

void DumbTeamAI::controlTeam()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

DumbTeamAI::~DumbTeamAI() 
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

