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

BZRFlagGame::BZRFlagGame()
{
    
}

void BZRFlagGame::playGame(string hostName, int portNumber)
{
    BZRC* connection = connectToServer(hostName, portNumber);
    
    CommanderAI* commanderAI = new PotentialFieldCommanderAI(connection);
    
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

