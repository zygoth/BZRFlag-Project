/* 
 * File:   EvaderTankAI.cpp
 * Author: zygoth
 * 
 * Created on June 3, 2013, 3:37 PM
 */

#include "EvaderTankAI.h"

EvaderTankAI::EvaderTankAI(BZRC* connection, int tankNumber, TeamColor myColor) : TankAI(connection)
{
    this->tankNumber = tankNumber;
    
    movementTimer = time(&movementTimer);
}

void EvaderTankAI::controlTank()
{
    time_t nowTime = time(&nowTime);
    double secondsElapsed = (double(nowTime - movementTimer) / CLOCKS_PER_SEC) * 1000000;
    
    
    if ((int) secondsElapsed % 4 == 0)
    {
        double randomAngvel = (double)((rand() % 11) - 5) / 5;
        connection->angvel(tankNumber, randomAngvel);
    }

    if ((int) secondsElapsed % 2 == 0)
    {
        double randomSpeed = (double)(rand() % 10 + 3) / 9;
        connection->speed(tankNumber, randomSpeed);
    }    
}

EvaderTankAI::~EvaderTankAI()
{
}

