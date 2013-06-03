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
GridFilter::GridFilter(int width, int height, double truePositiveProbability)
{
    // settledGrid = new doubl[width][height]
    settledGrid.grid = (double**) malloc(sizeof(double*) * width);
    
    for(int i = 0; i < width; i++)
    {
        settledGrid.grid[i] = (double*) malloc(sizeof(double) * height);
    }
    
    
    
    settledGrid.height = height;
    settledGrid.width = width;
    
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            settledGrid.grid[i][j] = .1;
        }
    }    

    nodesNotSettled = width * height;    
    this->truePositiveProbability = truePositiveProbability;
    EPSILON = .005;
}

void GridFilter::addInput(grid_t occGrid)
{
    int startX = cartesianToMatrixCoordinates(occGrid.x, settledGrid.width);
    int startY = cartesianToMatrixCoordinates(occGrid.y, settledGrid.height);
    int sensorData = 0;
    
    int i;
    int j;
    int jMax;
    
    for(i = startX; i < startX + occGrid.xdim; i++)
    {
        jMax = startY + occGrid.ydim;
        
        for(j = startY; j < jMax; j++)
        {
            // If the point is already settled, don't do the calculations
            if(settledGrid.grid[i][j] == 1 || settledGrid.grid[i][j] == 0)
            {
                continue;
            }
            
            // segfault due to truncation???
            sensorData = (int) occGrid.grid[(i - startX) + (j - startY) * occGrid.xdim];
            
            // Formula for updating the probability
            //settledGrid.grid[i][j] = (1 - truePositiveProbability) * settledGrid.grid[i][j] +
            //        truePositiveProbability * sensorData;
            settledGrid.grid[i][j] = (.5) * settledGrid.grid[i][j] +
            .5 * sensorData;
                    
            // It's close to 1
            if(1 - settledGrid.grid[i][j] < EPSILON)
            {
                settledGrid.grid[i][j] = 1;
                nodesNotSettled--;
            }
            else
            // It's close to 0
            if(settledGrid.grid[i][j] < EPSILON)
            {
                settledGrid.grid[i][j] = 0;
                nodesNotSettled--;
            }
        }
    }
}

bool GridFilter::isSettled()
{
    return (nodesNotSettled == 0);
}

settledGrid_t GridFilter::getGrid()
{
    return settledGrid;
}

int GridFilter::cartesianToMatrixCoordinates(int value, int maximumValue)
{
    return (value + maximumValue / 2);
}

GridFilter::~GridFilter()
{
    free(settledGrid.grid);
}

void GridFilter::testGridFilter()
{
    GridFilter filter(5, 5, .9);
    
    grid_t testGrid;
    testGrid.grid = new bool[3*3];
    testGrid.grid[0] = true;
    testGrid.grid[1] = false;
    
    testGrid.xdim = 3;
    testGrid.ydim = 3;
    testGrid.x = 0;
    testGrid.y = 0;
    
    filter.addInput(testGrid);
    
    if(filter.getGrid().grid[2][2] <= .5)
    {
        cout << "GridFilter FAIL:  the probability was not updated correctly." << endl;
    }
    
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    filter.addInput(testGrid);
    
    if(filter.getGrid().grid[2][2] != 1)
    {
        cout << "GridFilter FAIL:  nodes should be settled by now." << endl;
    }
    
    if(filter.getGrid().grid[2][3] != 0)
    {
        cout << "GridFilter FAIL:  nodes should be settled by now." << endl;
        cout << "Was: " << filter.getGrid().grid[2][3] << endl;
    }
}