#define _CRT_SECURE_NO_DEPRECATE 1
#include <iostream>
#include <unistd.h>
#include "BZRFlagGame.h"
#include "470bot.h"
using namespace std;

const char *kDefaultServerName = "localhost";
const int kDefaultServerPort = 4000;

int main(int argc, char *argv[]) 
{
    const char* pcHost = kDefaultServerName;
    int nPort = kDefaultServerPort;
    
    if (argc >= 2)
    {
        pcHost = argv[1];
    }
    
    if (argc >= 3)
    {
        nPort = atoi(argv[2]);
    }
    
    string hostName(pcHost);    
    BZRFlagGame* game = new BZRFlagGame();
    
    game->playGame(hostName, nPort);

    delete game;
    return 0;
}