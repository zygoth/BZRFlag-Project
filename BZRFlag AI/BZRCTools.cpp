/* 
 * File:   BZRCTools.cpp
 * Author: zygoth
 * 
 * Created on June 14, 2013, 3:07 PM
 */

#include "BZRCTools.h"
#include "SearchTools.h"
#include "UniformCostArraySearcher.h"
#include "PotentialFieldCalculator.h"
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

bool BZRCTools::hitCheck(tank_t me, shot_t bullet, int range, UniformCostArraySearcher* path)
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
        
    int xMovement, yMovement;
    for(int i = 0; i < 300; i++)
    {
        xMovement = shotX + i*bullet.velocity[0];
        yMovement = shotY + i*bullet.velocity[1];
        if(yMovement >= 0 && yMovement < path->width &&
           xMovement >= 0 && xMovement < path->width)
        {
            if(path->objectGrid[yMovement*path->width + xMovement] == 1)
                return false;
        }
            
        if(SearchTools::distance(xMovement,
                                 yMovement,
                                 tankX + i*me.velocity[0],
                                 tankY + i*me.velocity[1]) <= 5)
            return true;
    }
    return false;
}

bool BZRCTools::shouldShoot(BZRC* connection, vector<TankTargeter>* enemies, tank_t me)
{    
    for(int i = 0; i < enemies->size(); i++)
    {
        // It's too far away, forget it
        if(SearchTools::distance((*enemies)[i].getCurrentPoint(), Point(me.pos[0], me.pos[1])) > 350)
        {
            continue;
        }
        
        
        TankTargeter* targetedEnemy = &(*enemies)[i];
        
        Point targetLocation = targetedEnemy->getCurrentPoint();
        double distanceToEnemy = SearchTools::distance(me.pos[0], me.pos[1], targetLocation.x, targetLocation.y);
        double timeForShotToHit = distanceToEnemy / 100;
        Point futureLocation = targetedEnemy->getTargetPoint(timeForShotToHit);
        double targetAngle = atan2((futureLocation.y - me.pos[1]) , (futureLocation.x - me.pos[0]));
        
        // original value: .785
        double envelope = 1 / pow(distanceToEnemy, .5);
        
        if(abs(PotentialFieldCalculator::getAngleBetween(me.angle, targetAngle)) < envelope)
        {
            return true;
        }
    }
    
    return false;
}

bool BZRCTools::simpleShouldShoot(BZRC* connection, vector<TankTargeter>* enemies, tank_t me)
{
    for(int i = 0; i < enemies->size(); i++)
    {
        // It's too far away, forget it
        if(SearchTools::distance((*enemies)[i].getCurrentPoint(), Point(me.pos[0], me.pos[1])) > 150)
        {
            continue;
        }        
        
        TankTargeter* targetedEnemy = &(*enemies)[i];
        
        Point targetLocation = targetedEnemy->getCurrentPoint();
        double distanceToEnemy = SearchTools::distance(me.pos[0], me.pos[1], targetLocation.x, targetLocation.y);
        
        double targetAngle = atan2((targetLocation.y - me.pos[1]) , (targetLocation.x - me.pos[0]));
        
        // original value: .785
        double envelope = 1 / pow(distanceToEnemy, .5);
        
        if(abs(PotentialFieldCalculator::getAngleBetween(me.angle, targetAngle)) < envelope)
        {
            return true;
        }
    }
    
    return false;
}

bool BZRCTools::objectBetween(int x1, int y1, int x2, int y2, UniformCostArraySearcher*)
{
    
}