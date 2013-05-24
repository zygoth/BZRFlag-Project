/* 
 * File:   TargetPointCalculator.cpp
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:35 PM
 */

#include "TargetPointCalculator.h"
#include <iostream>
#include <unistd.h>

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
    
    //  Do the basic Search
}

void TargetPointCalculator::basicPointSearch(vector<Point>* nearbyPoints)
{
    
}
