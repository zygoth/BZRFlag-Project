/* 
 * File:   GridFilter.cpp
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:22 PM
 */

#include "GridFilter.h"
#include <iostream>
#include <unistd.h>

GridFilter::GridFilter(int width, int height)
{
    // settledGrid = new doubl[width][height]
    nodesSettled = width * height;
}

void GridFilter::addInput(bool* occgrid, int xpos, int ypos)
{
    
}

bool GridFilter::isSettled()
{
    return false;
}
