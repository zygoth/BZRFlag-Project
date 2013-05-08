/* 
 * File:   PotentialFieldTeam.cpp
 * Author: zygoth
 * 
 * Created on May 8, 2013, 11:15 AM
 */

#include "PotentialFieldTeamAI.h"
#include "PotentialFieldTankAI.h"
using namespace std;

PotentialFieldTeamAI::PotentialFieldTeamAI(BZRC* connection) : TeamAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new PotentialFieldTankAI(connection, i));
    }
}

void PotentialFieldTeamAI::controlTeam()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

PotentialFieldTeamAI::~PotentialFieldTeamAI()
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

