/* 
 * File:   ShooterCommanderAI.cpp
 * Author: zygoth
 * 
 * Created on June 4, 2013, 12:02 PM
 */

#include "ShooterCommanderAI.h"
#include "ShooterTankAI.h"

ShooterCommanderAI::ShooterCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new ShooterTankAI(connection, i, myColor));
    }
}

void ShooterCommanderAI::controlTeam()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < tankAIs.size(); i++)
    {
        tankAIs[i]->controlTank();
    }
}

ShooterCommanderAI::~ShooterCommanderAI() 
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

