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
public:
    TargetPointCalculator();
    Point getTarget(int tankX, int tankY, settleGrid_t* settledGrid);
};

#endif	/* TARGETPOINTCALCULATOR_H */

