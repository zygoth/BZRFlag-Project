#ifndef MAIN_H
#define	MAIN_H

#define _CRT_SECURE_NO_DEPRECATE 1
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "BZRFlagGame.h"
using namespace std;

char *kDefaultServerName = "localhost";
const int kDefaultServerPort = 4000;

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
    
}

void printMainErrorMessage()
{
        cout << "Please tell me which program to run.  \"agent HOSTNAME PORTNUMBER\",";
        cout << "\"potentialfieldprinter\", or \"search ALGORITHM\"\n";
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