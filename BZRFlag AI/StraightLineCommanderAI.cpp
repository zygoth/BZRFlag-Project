/* 
 * File:   StraightLineCommanderAI.cpp
 * Author: zygoth
 * 
 * Created on June 3, 2013, 2:39 PM
 */

#include "StraightLineCommanderAI.h"
#include "StraightLineTankAI.h"

StraightLineCommanderAI::StraightLineCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new StraightLineTankAI(connection, i, myColor));
    }
}

void StraightLineCommanderAI::controlTeam()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

StraightLineCommanderAI::~StraightLineCommanderAI()
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

