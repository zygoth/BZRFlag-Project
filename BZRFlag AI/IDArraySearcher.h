/* 
 * File:   IDArraySearcher.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 4:23 PM
 */

#ifndef IDARRAYSEARCHER_H
#define	IDARRAYSEARCHER_H

#include "Point.h"
#include <vector>

using namespace std;

class IDArraySearcher
{
public:
    IDArraySearcher();
    void getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
            Point startPosition, Point targetPosition,
            vector<Point>& path);
    virtual ~IDArraySearcher();
private:

};

#endif	/* IDARRAYSEARCHER_H */

