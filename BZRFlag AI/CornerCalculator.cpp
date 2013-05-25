/* 
 * File:   CornerCalculator.cpp
 * Author: zygoth
 * 
 * Created on May 22, 2013, 3:57 PM
 */

#include "CornerCalculator.h"
#include "f9.h"

CornerCalculator::CornerCalculator()
{
    
}

void CornerCalculator::calculateCorners(settledGrid_t settledGrid, vector<Point>* cornerList)
{
    vector<F9_CORNER> corners;
    F9 cornerDetector;
    
    // Convert the settledGrid to a format the cornerDetector can use
    
    unsigned char* imageData;
    imageData = (unsigned char*) malloc(settledGrid.height * settledGrid.width * sizeof(char));
    
    for(int i = 0; i < settledGrid.width; i++)
    {
        for(int j = 0; j < settledGrid.height; j++)
        {
            if(settledGrid.grid[i][j] >= .5)
            {
                *(imageData + i + (j * settledGrid.width)) = 255;
            }
            else
            {
                *(imageData + i + (j * settledGrid.width)) = 0;
            }
        }
    }
    
    // Get the corners and convert them to Points
    
    cornerDetector.detectCorners(imageData, settledGrid.width, settledGrid.height,
                                 settledGrid.width * sizeof(unsigned char), 5, false);
    
    
    // Clean up
    
    free(imageData);
}

CornerCalculator::~CornerCalculator()
{
    
}

