/* 
 * File:   EvaderCommanderAI.cpp
 * Author: zygoth
 * 
 * Created on June 3, 2013, 3:37 PM
 */

#include "EvaderCommanderAI.h"
#include "EvaderTankAI.h"
#include "StraightLineCommanderAI.h"
#include "StraightLineTankAI.h"

EvaderCommanderAI::EvaderCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new EvaderTankAI(connection, i, myColor));
    }
}

void EvaderCommanderAI::controlTeam()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

EvaderCommanderAI::~EvaderCommanderAI()
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

