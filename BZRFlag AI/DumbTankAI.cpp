/*
 * DumbTankAI.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "DumbTankAI.h"
#include <sys/time.h>
#include <time.h>

DumbTankAI::DumbTankAI(BZRC* connection, int tankNumber) 
{
    this->tankNumber = tankNumber;
    this->connection = connection;
    
    startClock = clock();
}

void DumbTankAI::controlTank()
{   
    //clock_t nowClock = clock();

    //int secondsElapsed = (int) (double(nowClock - startClock) / CLOCKS_PER_SEC);
    
    connection->angvel(tankNumber, 1);
    connection->speed(tankNumber, 1);
}

DumbTankAI::~DumbTankAI() 
{
    
}

