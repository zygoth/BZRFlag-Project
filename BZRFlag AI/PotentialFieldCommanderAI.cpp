/* 
 * File:   PotentialFieldTeam.cpp
 * Author: zygoth
 * 
 * Created on May 8, 2013, 11:15 AM
 */

#include "PotentialFieldCommanderAI.h"
#include "PotentialFieldTankAI.h"
#include "PotentialFieldCalculator.h"
#include "DumbTankAI.h"

using namespace std;

PotentialFieldCommanderAI::PotentialFieldCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new PotentialFieldTankAI(connection, i, myColor, pickRandomTarget()));
    }
}

void PotentialFieldCommanderAI::controlTeam()
{    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

PotentialFieldCommanderAI::~PotentialFieldCommanderAI()
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

