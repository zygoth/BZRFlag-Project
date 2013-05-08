/*
 * DumbTankAI.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "DumbTankAI.h"
#include <sys/time.h>
#include <time.h>

DumbTankAI::DumbTankAI(BZRC* server, int tankNumber) 
{
    this->tankNumber = tankNumber;
    this->server = server;
    
    shotTimer = time(&shotTimer);
    movementTimer = time(&movementTimer);
    isTurning = true;
}

/**
 * This tank turns for 4 seconds, then moves forward for 4 seconds, shooting
 * every 3 seconds.
 */
void DumbTankAI::controlTank()
{   
    //clock_t nowClock = clock();
    time_t nowTime = time(&nowTime);
    double secondsElapsed = (double(nowTime - shotTimer) / CLOCKS_PER_SEC) * 1000000;
    
    if(secondsElapsed >= 3)
    {
        server->shoot(tankNumber);
        shotTimer = time(&shotTimer);
    }
    
    secondsElapsed = (double(nowTime - movementTimer) / CLOCKS_PER_SEC) * 1000000;
    
    if(secondsElapsed >= 4)
    {
        if(isTurning)
        {
            server->angvel(tankNumber, 0);
            server->speed(tankNumber, .5);
            isTurning = false;
        }
        else
        {
            server->angvel(tankNumber, .5);
            server->speed(tankNumber, 0);
            isTurning = true;
        }
        
        movementTimer = time(&shotTimer);
    }
}

DumbTankAI::~DumbTankAI() 
{
    
}

