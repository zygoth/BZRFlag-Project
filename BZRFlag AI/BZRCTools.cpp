/* 
 * File:   BZRCTools.cpp
 * Author: zygoth
 * 
 * Created on June 14, 2013, 3:07 PM
 */

#include "BZRCTools.h"

BZRCTools::BZRCTools()
{
}

base_t BZRCTools::getBase(BZRC* connection, TeamColor color)
{
    vector<base_t> bases;
    connection->get_bases(&bases);
    
    for(int i = 0; i < bases.size(); i++)
    {
        if(stringToTeamColor(bases[i].color) == color)
        {
            return bases[i];
        }
    }
    
    throw "You called getBase with a color that doesn't exist in game.";
}

BZRCTools::~BZRCTools()
{
}

