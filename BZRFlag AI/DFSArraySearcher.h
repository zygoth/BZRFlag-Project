/* 
 * File:   DFSArraySearcher.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 4:22 PM
 */

#ifndef DFSARRAYSEARCHER_H
#define	DFSARRAYSEARCHER_H

#include "Point.h"
#include "470bot.h"
#include "Node.h"

using namespace std;

class DFSArraySearcher
{
public:
    DFSArraySearcher();
    void getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
            Point startPosition, Point targetPosition,
            vector<Point>& path);
    virtual ~DFSArraySearcher();
private:

};

#endif	/* DFSARRAYSEARCHER_H */

