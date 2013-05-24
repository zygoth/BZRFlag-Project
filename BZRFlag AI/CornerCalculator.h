/* 
 * File:   CornerCalculator.h
 * Author: zygoth
 *
 * Created on May 22, 2013, 3:57 PM
 */

#ifndef CORNERCALCULATOR_H
#define	CORNERCALCULATOR_H

#include "Point.h"
#include <vector>

using namespace std;

class CornerCalculator
{
public:
    CornerCalculator();
    static void calculateCorners(double** settledGrid, vector<Point>* cornerList);
    virtual ~CornerCalculator();
private:

};

#endif	/* CORNERCALCULATOR_H */

