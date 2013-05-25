/* 
 * File:   CornerCalculator.h
 * Author: zygoth
 *
 * Created on May 22, 2013, 3:57 PM
 */

#ifndef CORNERCALCULATOR_H
#define	CORNERCALCULATOR_H

#include "Point.h"
#include "GridFilter.h"
#include <vector>

using namespace std;

class CornerCalculator
{
public:
    CornerCalculator();
    static void calculateCorners(settledGrid_t settledGrid, vector<Point>* cornerList);
    virtual ~CornerCalculator();
    
private:

};

#endif	/* CORNERCALCULATOR_H */

