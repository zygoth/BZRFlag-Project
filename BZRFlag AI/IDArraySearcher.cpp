/* 
 * File:   IDArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 4:23 PM
 */

#include "IDArraySearcher.h"
#include "DepthLimitedArraySearcher.h"
#include "GNUPrinter.h"

IDArraySearcher::IDArraySearcher()
{
    
}

void IDArraySearcher::getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
        Point startPosition, Point targetPosition,
        vector<Point>& path)
{
    DepthLimitedArraySearcher* searcher = new DepthLimitedArraySearcher();
    GNUPrinter* printer = new GNUPrinter();
    
    int currentDepth = 1;
    
    searcher->getPathToGoal(occgrid, gridWidth, gridHeight, startPosition, targetPosition,
                           path, currentDepth, printer);
    
    while(path.back().Compare(startPosition) == 0)// we haven't found the goal yet
    {            
        if(currentDepth % 10 == 0 && currentDepth < 101)
        {
            delete printer;
            printer = new GNUPrinter();
        }
        
        path.clear();
        currentDepth++;
        searcher->getPathToGoal(occgrid, gridWidth, gridHeight, startPosition, targetPosition,
                           path, currentDepth, printer);
        
        if(currentDepth % 10 == 0 && currentDepth < 101)
        {
            char buffer[100];
            sprintf(buffer, "IDOUTPUT%i", currentDepth /10);
            printer->outputToFile(buffer);
        }
    }
    
    printer->insertSquare(targetPosition.x, targetPosition.y);
    //printer.outputToFile("IDOUTPUT");
}

IDArraySearcher::~IDArraySearcher()
{
    
}

