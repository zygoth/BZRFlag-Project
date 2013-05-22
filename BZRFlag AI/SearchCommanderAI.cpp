/* 
 * File:   SearchCommander.cpp
 * Author: zygoth
 * 
 * Created on May 22, 2013, 3:12 PM
 */

#include "SearchCommanderAI.h"

SearchCommanderAI::SearchCommanderAI(BZRC* connection) : CommanderAI(connection)
{
}

void SearchCommanderAI::controlTeam()
{
    
}

/**
 * This method goes through the list of corners gotten from the corner detection
 * algorithm and ensures that all points are located in occupied pixels.
 */
void SearchCommanderAI::fixOffByOneErrors()
{
    
}

SearchCommanderAI::~SearchCommanderAI()
{
}

