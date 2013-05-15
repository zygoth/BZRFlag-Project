/* 
 * File:   BFSArraySearcher.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 4:22 PM
 */

#ifndef BFSARRAYSEARCHER_H
#define	BFSARRAYSEARCHER_H

#include "Point.h"
#include "470bot.h"
#include "Node.h"

using namespace std;

class BFSArraySearcher
{
public:
    BFSArraySearcher();
    void getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
                       Point startPosition, Point targetPosition,
                       vector<Point>& path);
    virtual ~BFSArraySearcher();
};

#endif	/* BFSARRAYSEARCHER_H */

