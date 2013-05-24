/* 
 * File:   TargetPointCalculator.h
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:35 PM
 */

#ifndef TARGETPOINTCALCULATOR_H
#define	TARGETPOINTCALCULATOR_H

#include "Point.h"

class TargetPointCalculator{
    int width, height;
public:
    TargetPointCalculator(int x, int y);
    Point getTarget(int tankX, int tankY, double** settledGrid);
};

#endif	/* TARGETPOINTCALCULATOR_H */

