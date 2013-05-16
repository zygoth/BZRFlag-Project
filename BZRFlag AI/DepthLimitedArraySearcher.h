/* 
 * File:   DepthLimitedArraySearcher.h
 * Author: zygoth
 *
 * Created on May 15, 2013, 6:53 PM
 */

#ifndef DEPTHLIMITEDARRAYSEARCHER_H
#define	DEPTHLIMITEDARRAYSEARCHER_H

#include "GNUPrinter.h"
#include "Point.h"
#include <vector>

using namespace std;

class DepthLimitedArraySearcher
{
public:
    DepthLimitedArraySearcher();
    void getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
            Point startPosition, Point targetPosition,
            vector<Point>& path, int depth, GNUPrinter& outputPrinter);
    virtual ~DepthLimitedArraySearcher();
private:

};

#endif	/* DEPTHLIMITEDARRAYSEARCHER_H */

