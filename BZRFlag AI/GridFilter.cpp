/* 
 * File:   GridFilter.cpp
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:22 PM
 */

#include "GridFilter.h"
#include <iostream>
#include <unistd.h>

/**
 * Initializes the settledGrid.
 * 
 * @param width the width of the grid
 * @param height the height of the grid
 */
GridFilter::GridFilter(int width, int height)
{
    // settledGrid = new doubl[width][height]
    settledGrid.grid = (double**) malloc(sizeof(double) * width * height);
    
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            settledGrid.grid[i][j] = .5;
        }
    }
    
    settledGrid.height = height;
    settledGrid.width = width;
    nodesNotSettled = width * height;    
}

void GridFilter::addInput(grid_t occGrid)
{
    int startX = cartesianToMatrixCoordinates(occGrid.x, occGrid.xdim);
    int startY = cartesianToMatrixCoordinates(occGrid.y, occGrid.ydim);
    int sensorData = 0;
    
    for(int i = startX; i < startX + occGrid.xdim; i++)
    {
        for(int j = startY; i < startY + occGrid.ydim; j++)
        {
            // If the point is already settled, don't do the calculations
            if(settledGrid[i][j] == 1 || settledGrid[i][j] == 0)
            {
                continue;
            }
            
            sensorData = occGrid.grid[i - occGrid.xdim/2][j - occGrid.ydim/2];
            
            // Formula for updating the probability
            //settledGrid.grid[i][j] = ()
                    
            
        }
    }
}

bool GridFilter::isSettled()
{
    return false;
}

settledGrid_t GridFilter::getGrid()
{
    return settledGrid;
}

GridFilter::~GridFilter()
{
    free(settledGrid.grid);
}

int GridFilter::cartesianToMatrixCoordinates(int value, int maximumValue)
{
    return (value + maximumValue / 2);
}