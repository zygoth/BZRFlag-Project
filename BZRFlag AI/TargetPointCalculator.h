/* 
 * File:   TargetPointCalculator.h
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:35 PM
 */

#ifndef TARGETPOINTCALCULATOR_H
#define	TARGETPOINTCALCULATOR_H

#include "Point.h"
#include "GridFilter.h"

/**
 * This class uses matrix coordinates for everything.  Don't pass it cartesian
 * coordinates or you'll segfault.
 * 
 * @param tankX
 * @param tankY
 */
class TargetPointCalculator
{
public:
    
    TargetPointCalculator(int tankX, int tankY);
    Point getTarget(int tankX, int tankY, settledGrid_t settledGrid);
    
private:
    void basicPointSearch(int tankX, int tankY, settledGrid_t settledGrid, vector<Point>* nearbyPoints);
    void advancedPointSearch(int tankX, int tankY, settledGrid_t settledGrid, vector<Point>* nearbyPoints);
    bool isValidTarget(Point p, settledGrid_t settledGrid);
    Point previousTarget;
};

#endif	/* TARGETPOINTCALCULATOR_H */

