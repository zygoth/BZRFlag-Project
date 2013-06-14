/* 
 * File:   BZRCTools.cpp
 * Author: zygoth
 * 
 * Created on June 14, 2013, 3:07 PM
 */

#include "BZRCTools.h"
#include "SearchTools.h"
#include <cmath>

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

Point BZRCTools::getBaseCenter(BZRC* connection, TeamColor color)
{
    int baseX;
    int baseY;
    
    base_t base = getBase(connection, color);
    
    baseX = base.base_corner[0][0]
                  - base.base_corner[2][0];
            baseY = base.base_corner[0][1]
                  - base.base_corner[2][1];
            
            baseX = base.base_corner[2][0]
                    + baseX/2;
            baseY = base.base_corner[2][1]
                    + baseY/2;
            
            return Point(baseX, baseY);
}

BZRCTools::~BZRCTools()
{
}

bool BZRCTools::hitCheck(tank_t me, shot_t bullet, int range)
{
    int shotX = bullet.pos[0];
    int shotY = bullet.pos[1];
    int tankX = me.pos[0];
    int tankY = me.pos[1];
    
    if(SearchTools::distance(tankX, tankY, shotX, shotY) >= range)
        return false;
    
    if((tankX - shotX) * bullet.velocity[0] < 0)
        return false;
    if((tankY - shotY) * bullet.velocity[1] < 0)
        return false;
        
    for(int i = 0; i < 300; i++)
    {
        if(SearchTools::distance(shotX + i*bullet.velocity[0],
                                 shotY + i*bullet.velocity[1],
                                 tankX + i*me.velocity[0],
                                 tankY + i*me.velocity[1]) <= 5)
            return true;
    }
    return false;
}