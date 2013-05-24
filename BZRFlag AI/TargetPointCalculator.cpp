/* 
 * File:   TargetPointCalculator.cpp
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:35 PM
 */

#include "TargetPointCalculator.h"
#include <iostream>
#include <unistd.h>

TargetPointCalculator::TargetPointCalculator(int x, int y){
    width = x;
    height = y;
    
}

Point TargetPointCalculator::getTarget(int tankX, int tankY, double** settledGrid)
{
    return Point(0,0);
}
