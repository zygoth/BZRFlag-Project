/* 
 * File:   BZRFlagGame.h
 * Author: zygoth
 *
 * Created on May 7, 2013, 1:04 PM
 */

#ifndef BZRFLAGGAME_H
#define	BZRFLAGGAME_H

#include <string>
#include "470bot.h"

using namespace std;

class BZRFlagGame
{
public:
    BZRFlagGame();
    void playGame(string hostName, int portNumber, string gameType);
    virtual ~BZRFlagGame();
private:
    BZRC* connectToServer(string hostName, int portNumber);

};

#endif	/* BZRFLAGGAME_H */

