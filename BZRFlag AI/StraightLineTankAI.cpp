/* 
 * File:   StraightLineTankAI.cpp
 * Author: zygoth
 * 
 * Created on June 3, 2013, 2:36 PM
 */

#include "StraightLineTankAI.h"

StraightLineTankAI::StraightLineTankAI(BZRC* connection, int tankNumber, TeamColor myColor) : TankAI(connection)
{
    this->tankNumber = tankNumber;
    
    movementTimer = time(&movementTimer);
    isTurning = true;
}

void StraightLineTankAI::controlTank()
{
    time_t nowTime = time(&nowTime);
    double secondsElapsed = (double(nowTime - movementTimer) / CLOCKS_PER_SEC) * 1000000;
    
    secondsElapsed = (double(nowTime - movementTimer) / CLOCKS_PER_SEC) * 1000000;
    
    if(secondsElapsed >= 4)
    {
        if(isTurning)
        {
            connection->angvel(tankNumber, 0);
            connection->speed(tankNumber, 1);
            isTurning = false;
            movementTimer = time(&movementTimer);
        }
        else
        {
            if(secondsElapsed >= 10)
            {
                connection->angvel(tankNumber, 1);
                connection->speed(tankNumber, 0);
                isTurning = true;
                movementTimer = time(&movementTimer);
            }
        }
    }
}

StraightLineTankAI::~StraightLineTankAI()
{
}

