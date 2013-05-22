/* 
 * File:   SearchTankAI.cpp
 * Author: zygoth
 * 
 * Created on May 22, 2013, 3:26 PM
 */

#include "SearchTankAI.h"

SearchTankAI::SearchTankAI(BZRC* connection) : TankAI(connection)
{
}

void SearchTankAI::controlTank()
{
    
}

SearchTankAI::~SearchTankAI()
{
    delete PFCalculator;
}

