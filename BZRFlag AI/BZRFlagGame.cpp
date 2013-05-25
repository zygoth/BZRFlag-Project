/* 
 * File:   BZRFlagGame.cpp
 * Author: zygoth
 * 
 * Created on May 7, 2013, 1:04 PM
 */

#include "BZRFlagGame.h"
#include "CommanderAI.h"
#include "DumbCommanderAI.h"
#include "PotentialFieldCommanderAI.h"
#include "PotentialFieldPrinter.h"
#include "SearchCommanderAI.h"

BZRFlagGame::BZRFlagGame()
{
    
}

void BZRFlagGame::playGame(string hostName, int portNumber, string gameType)
{
    BZRC* connection = connectToServer(hostName, portNumber);
    
    CommanderAI* commanderAI;
    
    if(gameType.compare("DUMB") == 0)
        commanderAI = new DumbCommanderAI(connection);
    
    if(gameType.compare("POTENTIAL") == 0)
        commanderAI = new PotentialFieldCommanderAI(connection);
    
    if(gameType.compare("SEARCH") == 0)
        commanderAI = new SearchCommanderAI(connection);
    
    
    PotentialFieldPrinter fieldPrinter;
    //string GNUOutput = fieldPrinter.getGNUPlotFile(connection);
    //cout << GNUOutput << endl;
    //cout.flush();
    fieldPrinter.GNUOutputToFile(connection, "GNUPLOT");
    cout << "Vectors printed." << endl;
    cout.flush();
    
    try
    {
        while(true)
        {
            commanderAI->controlTeam();
        }
    }
    catch(...)
    {
        cout << "End of control." << endl;
    }
}

BZRC* BZRFlagGame::connectToServer(string hostName, int portNumber)
{
    BZRC* connection = new BZRC(hostName.c_str(), portNumber, false);
    
    if (!connection->GetStatus())
    {
        connection->Close();
        delete connection;
        throw "Can't connect to BZRC server.";
    }
    
    return connection;
}

BZRFlagGame::~BZRFlagGame()
{
    
}

