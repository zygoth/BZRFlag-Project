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

class TargetPointCalculator
{
public:
    
    TargetPointCalculator(int tankX, int tankY);
    Point getTarget(int tankX, int tankY, settledGrid_t settledGrid);
    
private:
    void basicPointSearch(vector<Point>* nearbyPoints);
    // NOTE: this point is in Matrix coordinates, not cartesian coordinates
    Point previousTarget;
};

#endif	/* TARGETPOINTCALCULATOR_H */

