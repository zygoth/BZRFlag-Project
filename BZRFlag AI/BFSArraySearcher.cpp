/* 
 * File:   BFSArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 4:22 PM
 */

#include "BFSArraySearcher.h"
#include <queue>

using namespace std;

BFSArraySearcher::BFSArraySearcher()
{
}

void BFSArraySearcher::getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
                                     Point startPosition, Point targetPosition,
                                     vector<Point> path)
{
    queue<Point> frontier;
    
    frontier.push(startPosition);
    
    while(!frontier.empty())
    {
        
    }
}

BFSArraySearcher::~BFSArraySearcher()
{
}

