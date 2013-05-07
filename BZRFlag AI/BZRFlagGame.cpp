/* 
 * File:   BZRFlagGame.cpp
 * Author: zygoth
 * 
 * Created on May 7, 2013, 1:04 PM
 */

#include "BZRFlagGame.h"
#include "470bot.h"
#include "TeamAI.h"
#include "DumbTeamAI.h"
#include "TeamAI.h"

BZRFlagGame::BZRFlagGame()
{
    
}

void BZRFlagGame::playGame(string hostName, int portNumber)
{
    connectToServer(hostName, portNumber);
    
    TeamAI* teamAI = new DumbTeamAI();
    
    try
    {
        while(true)
        {
            teamAI->controlTeam();
        }
    }
    catch(...)
    {
        cout << "End of control." << endl;
    }
}

void BZRFlagGame::connectToServer(string hostName, int portNumber)
{
    BZRC MyTeam = BZRC(hostName.c_str(), portNumber, false);
    
    if (!MyTeam.GetStatus())
    {
        throw "Can't connect to BZRC server.";
    }
}

BZRFlagGame::~BZRFlagGame()
{
    
}

