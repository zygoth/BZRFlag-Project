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
        tankAIs.push_back(new ShooterTankAI(connection, i, myColor, &tankTargeters));
    }    
}

void ShooterCommanderAI::controlTeam()
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

ShooterCommanderAI::~ShooterCommanderAI() 
{
    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

