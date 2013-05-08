/*
 * TeamAI.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef COMMANDERAI_H_
#define COMMANDERAI_H_

#include "CommanderAI.h"

CommanderAI::CommanderAI(BZRC* connection)
{
    this->connection = connection;
    myColor = determineMyColor();
}

/**
 * This method should be implemented by subclasses to control the team of
 * tanks.
 */
void CommanderAI::controlTeam()
{
    
}

TeamColor CommanderAI::pickRandomTarget()
{
    vector<team_t> allTeams;
    connection->get_teams(&allTeams);
    int randIndex = rand() % allTeams.size();
    
    TeamColor targetColor = stringToTeamColor(allTeams[randIndex].color);
    
    if(targetColor != myColor)
    {
        return targetColor;
    }
    else // pick the next one in the list
    {
        return stringToTeamColor(allTeams[(randIndex + 1) % allTeams.size()].color);
    }
}

TeamColor CommanderAI::determineMyColor()
{
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    if(myTanks.size() == 0)
    {
        throw "My team has no tanks.  Terminating.\n";
    }
    
    tank_t myTank = myTanks.front();
    string callSign = myTank.callsign;
    
    TeamColor myColor = stringToTeamColor(callSign);
        
    return myColor;
}

CommanderAI::~CommanderAI()
{
    // TODO Auto-generated destructor stub
}

#endif /* COMMANDERAI_H_ */