/* 
 * File:   GridFilter.cpp
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:22 PM
 */

#include "GridFilter.h"
#include <iostream>
#include <unistd.h>

GridFilter::GridFilter(int x, int y)
{
    // settledGrid = new doubl[width][height]
    nodesSettled = x * y;
    
    width = x;
    height = y;
}

void GridFilter::addInput(bool* occgrid, int xpos, int ypos, int xSize, int ySize)
{
    
}

bool GridFilter::isSettled()
{
    return false;
}

int GridFilter::getWidth()
{
    return width;
}

int GridFilter::getHeight()
{
    return height;
}

