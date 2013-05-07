/*
 * Vector.h
 *
 *  Created on: May 7, 2013
 *      Author: cj1of4
 */

#ifndef TANKVECTOR_H_
#define TANKVECTOR_H_

#include <stdio.h>
#include <math.h>

class TankVector {
    double x, y, angle, velocity;
public:
	TankVector(double, double);
	virtual ~TankVector();
        double getAngle();
        double getVelocity();
        double getXVector();
        double getYVector();
};

#endif /* TANKVECTOR_H_ */
