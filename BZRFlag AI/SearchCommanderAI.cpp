/* 
 * File:   SearchCommander.cpp
 * Author: zygoth
 * 
 * Created on May 22, 2013, 3:12 PM
 */

#include "SearchCommanderAI.h"
#include "GridFilter.h"
#include "SearchTankAI.h"
#include "GNUPrinter.h"

int GNUCounter = 0;

SearchCommanderAI::SearchCommanderAI(BZRC* connection) : CommanderAI(connection)
{
    vector<constant_t> constants;
    connection->get_constants(&constants);
    constant_t temp;
    int gridSize;
    double isTrueValue = 1.0;
    
    for(int i =0; i < constants.size(); i++)
    {
        temp = constants.at(i);
        if(temp.name.compare("worldsize") == 0)
        {
            gridSize = atoi(temp.value.c_str());
        }
        if(temp.name.compare("truepositive") == 0)
        {
            isTrueValue = atof(temp.value.c_str());
        }
    }
    
    grid = new GridFilter(gridSize, gridSize, isTrueValue);
    
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        tankAIs.push_back(new SearchTankAI(connection, i, myColor, grid));
    }
    
    searchDone = false;
}

void SearchCommanderAI::controlTeam()
{
    if(grid->isSettled() == false)
    {
        for(int i = 0; i < tankAIs.size(); i++)
        {
            tankAIs[i]->controlTank();
        }
        
        GNUCounter ++;
        if(GNUCounter % 30 != 0)
        {
            cout << GNUCounter << endl;
            return;
        }
        GNUPrinter printer;
        for(int i = 0; i < grid->getGrid().width; i++)
        {
            for(int j = 0; j < grid->getGrid().height; j++)
            {
                if(grid->getGrid().grid[i][j] == 1)
                {
                    printer.insertSquare(i, j);
                }
            }
        }        
        printer.outputToFile("OCCGRID");
        
        GNUPrinter printer2;
        for(int i = 0; i < grid->getGrid().width; i++)
        {
            for(int j = 0; j < grid->getGrid().height; j++)
            {
                if(grid->getGrid().grid[i][j] == 1 || grid->getGrid().grid[i][j] == 0)
                {
                    printer2.insertSquare(i, j);
                }
            }
        }        
        printer2.outputToFile("SETTLEDGRID");
    }
    else if(searchDone == false)
    {
        searchDone = true;
        
        
        
        // Get Corners
        // fixOffByOneErrors
        // Print out Grid
        // Print out Corners
    }
}

/**
 * This method goes through the list of corners gotten from the corner detection
 * algorithm and ensures that all points are located in occupied pixels.
 */
void SearchCommanderAI::fixOffByOneErrors()
{
    
}

SearchCommanderAI::~SearchCommanderAI()
{
    delete grid;

    for(int i = 0; i < tankAIs.size(); i++)
    {
        delete tankAIs[i];
    }
}

