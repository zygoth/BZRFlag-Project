#ifndef MAIN_H
#define	MAIN_H

#define _CRT_SECURE_NO_DEPRECATE 1
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "BZRFlagGame.h"
#include "BFSArraySearcher.h"

using namespace std;

char *kDefaultServerName = "localhost";
const int kDefaultServerPort = 4000;

void printMainErrorMessage()
{
        cout << "Please tell me which program to run.  \"agent HOSTNAME PORTNUMBER\",";
        cout << "\"potentialfieldprinter\", or \"search ALGORITHM\"\n";
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
    
    BZRC* connection = new BZRC(hostName, portNumber, false);
    
    if(strcmp(algorithmType, "BFS") == 0)
    {
        BFSArraySearcher* searcher = new BFSArraySearcher();
        
        //searcher.
    }
    else
    if(strcmp(algorithmType, "DFS") == 0)
    {
        // do a DFS search
    }
    else
    if(strcmp(algorithmType, "ID") == 0)
    {
        // do a ID search
    }
    else
    if(strcmp(algorithmType, "UNIFORM_COST") == 0)
    {
        // do a uniform cost search
    }
    else
    if(strcmp(algorithmType, "ASTAR") == 0)
    {
        // do an A* search
    }
    else
    {
        printMainErrorMessage();
    }
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