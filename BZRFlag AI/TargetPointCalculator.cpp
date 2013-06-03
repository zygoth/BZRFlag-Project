/* 
 * File:   TargetPointCalculator.cpp
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:35 PM
 */

#include "TargetPointCalculator.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "SearchTools.h"

/**
 * tankX and tankY should be in matrix coordinates, not cartesian coordinates.
 * @param tankX
 * @param tankY
 */
TargetPointCalculator::TargetPointCalculator(int tankX, int tankY) : previousTarget(tankX, tankY)
{
    
}

Point TargetPointCalculator::getTarget(int tankX, int tankY, settledGrid_t settledGrid)
{
    double targetProbability = settledGrid.grid[previousTarget.x]
                                               [previousTarget.y];
    
    if(targetProbability != 1 && targetProbability != 0) 
    {  // we still haven't settled it, so don't calculate a different target
        return previousTarget;
    }
    
    //  Do the basic Search, then if that fails do the more complex one
    vector<Point> targets;
    
    basicPointSearch(tankX, tankY, settledGrid, &targets);
    
    if(!targets.empty())
    {
        Point test = targets[rand() % targets.size()];
        cout << "Basic search: " << test.x << ", " << test.y << endl;
        previousTarget = test;
        return test;
    }
    
    advancedPointSearch(tankX, tankY, settledGrid, &targets);
    
    if(!targets.empty())
    {
        Point test = targets[rand() % targets.size()];
        cout << "Advanced search: " << test.x << ", " << test.y << endl;
        previousTarget = test;
        return test;
    }
    else
    {
        return previousTarget;
    }
}

/**
 * Checks 8 different Points near the tank to look for unsettled ones.
 * 
 * @param tankX
 * @param tankY
 * @param settledGrid
 * @param nearbyPoints
 */
void TargetPointCalculator::basicPointSearch(int tankX, int tankY,
                            settledGrid_t settledGrid, vector<Point>* targetPoints)
{
    const int NUMPOINTS = 8;
    const int DISTANCE1 = 50;
    
    Point testedPoints[NUMPOINTS];
    
    testedPoints[0].x = tankX - DISTANCE1;
    testedPoints[0].y = tankY;
    
    testedPoints[1].x = tankX;
    testedPoints[1].y = tankY + DISTANCE1;
    
    testedPoints[2].x = tankX + DISTANCE1;
    testedPoints[2].y = tankY;
    
    testedPoints[3].x = tankX;
    testedPoints[3].y = tankY - DISTANCE1;
    
    
    testedPoints[4].x = tankX - 100;
    testedPoints[4].y = tankY;
    
    testedPoints[5].x = tankX;
    testedPoints[5].y = tankY + 100;
    
    testedPoints[6].x = tankX + 100;
    testedPoints[6].y = tankY;
    
    testedPoints[7].x = tankX;
    testedPoints[7].y = tankY - 100;
    
    
    for(int i = 0; i < NUMPOINTS; i++)
    {        
        if(isValidTarget(testedPoints[i], settledGrid))
        {
             targetPoints->push_back(testedPoints[i]);
             return;
        }
    }
}

void TargetPointCalculator::advancedPointSearch(int tankX, int tankY, 
                        settledGrid_t settledGrid, vector<Point>* nearbyPoints)
{
    const int GRANULARITY = 60;
    int noise = rand() % GRANULARITY;
    Point currentPoint(0,0);
    
    for(int i = GRANULARITY - noise; i < settledGrid.width; i+= GRANULARITY)
    {
        for(int j = GRANULARITY - noise; j < settledGrid.height; j+= GRANULARITY)
        {
            currentPoint.x = i;
            currentPoint.y = j;
            
            if(isValidTarget(currentPoint, settledGrid))
            {
                nearbyPoints->push_back(currentPoint);
                return;
            }
        }
    }
    
}

/**
 * Returns true if the point exists on the grid and is not already settled.
 * 
 * @param p
 * @param settledGrid
 * @return 
 */
bool TargetPointCalculator::isValidTarget(Point p, settledGrid_t settledGrid)
{
    double settledValue;
    
    if (!SearchTools::isValidPoint(settledGrid.width, settledGrid.height, p))
    {
        return false;
    }

    settledValue = settledGrid.grid[p.x][p.y];

    if (settledValue == 1 || settledValue == 0)
    {
        return false;
    }
    
    return true;
}
