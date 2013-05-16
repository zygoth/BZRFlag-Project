#ifndef MAIN_H
#define	MAIN_H

#define _CRT_SECURE_NO_DEPRECATE 1
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "BZRFlagGame.h"
#include "BFSArraySearcher.h"
#include "DFSArraySearcher.h"
#include "SearchTools.h"
#include "IDArraySearcher.h"
#include "UniformCostArraySearcher.h"

using namespace std;

char *kDefaultServerName = "localhost";
const int kDefaultServerPort = 4000;

void printMainErrorMessage()
{
        cout << "Please tell me which program to run.  \"agent HOSTNAME PORTNUMBER\",";
        cout << "\"potentialfieldprinter\", or \"search ALGORITHM HOSTNAME PORTNUMBER\"\n";
}

void doAgentMain(int argc, char *argv[])
{
    char* pcHost = kDefaultServerName;
    int nPort = kDefaultServerPort;
    
    if (argc >= 3)
    {
        pcHost = argv[2];
    }
    
    if (argc >= 4)
    {
        nPort = atoi(argv[3]);
    }
    
    string hostName(pcHost);    
    BZRFlagGame* game = new BZRFlagGame();
    
    game->playGame(hostName, nPort);

    delete game;
    
    exit(0);
}

void doPotentialFieldPrinterMain(int argc, char *argv[])
{

}

void doSearchMain(int argc, char *argv[])
{
    // Parse arguments and check for correctness
    
    char* algorithmType;
    char* hostName;
    int portNumber;
    
    if(argc < 5)
    {
        printMainErrorMessage();
    }
    
    algorithmType = argv[2];
    hostName = argv[3];    
    portNumber = atoi(argv[4]);
    
    // Get the data we need to do the search from the server
    
    BZRC* connection = new BZRC(hostName, portNumber, false);
    
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    tank_t firstTank = myTanks.front();
    
    vector<grid_t> occVector;
    connection->get_occgrid(&occVector, 0);
    grid_t occMatrix = occVector.front();
    
    vector<flag_t> flags;
    connection->get_flags(&flags);
    flag_t greenFlag = SearchTools::getFlagOfColor(connection, "green");
    Point goalPoint(greenFlag.pos[0] - occMatrix.x, greenFlag.pos[1] - occMatrix.y);
    
    Point startPoint(firstTank.pos[0] - occMatrix.x, firstTank.pos[1] - occMatrix.y);
    
    // Actually do the search, using the class specified in the command line args
    
    if(strcmp(algorithmType, "BFS") == 0)
    {
        BFSArraySearcher* searcher = new BFSArraySearcher();        
        vector<Point> pathToGoal;
        
        searcher->getPathToGoal(occMatrix.grid, occMatrix.xdim, occMatrix.ydim,
                                startPoint, goalPoint, pathToGoal);
    }
    else
    if(strcmp(algorithmType, "DFS") == 0)
    {
        DFSArraySearcher* searcher = new DFSArraySearcher();
        vector<Point> pathToGoal;

        searcher->getPathToGoal(occMatrix.grid, occMatrix.xdim, occMatrix.ydim,
                startPoint, goalPoint, pathToGoal);
    }
    else
    if(strcmp(algorithmType, "ID") == 0)
    {
        IDArraySearcher* searcher = new IDArraySearcher();
        vector<Point> pathToGoal;
        
        searcher->getPathToGoal(occMatrix.grid, occMatrix.xdim, occMatrix.ydim,
                startPoint, goalPoint, pathToGoal);
    }
    else
    if(strcmp(algorithmType, "UNIFORM_COST") == 0)
    {
        UniformCostArraySearcher* searcher = new UniformCostArraySearcher();
        vector<Point> pathToGoal;
        
        searcher->search(occMatrix.grid, occMatrix.xdim, occMatrix.ydim,
                startPoint, goalPoint, pathToGoal, false, false);
    }
    else
    if(strcmp(algorithmType, "ASTAR") == 0)
    {
        UniformCostArraySearcher* searcher = new UniformCostArraySearcher();
        vector<Point> pathToGoal;
        
        searcher->search(occMatrix.grid, occMatrix.xdim, occMatrix.ydim,
                startPoint, goalPoint, pathToGoal, true, false);
        
    }
    else
    {
        printMainErrorMessage();
    }
    
    delete connection;
}



int main(int argc, char *argv[]) 
{
    if(argc < 1)
    {
        printMainErrorMessage();
        exit(1);
    }
    
    if(strcmp(argv[1], "agent") == 0)
    {
        doAgentMain(argc, argv);
    }
    else 
    if(strcmp(argv[1], "potentialfieldprinter") == 0)
    {
        doPotentialFieldPrinterMain(argc, argv);
    }    
    else 
    if(strcmp(argv[1], "search") == 0)
    {
        doSearchMain(argc, argv);
    }
    else
    {
        printMainErrorMessage();
        exit(1);
    }
}



#endif	/* MAIN_H */