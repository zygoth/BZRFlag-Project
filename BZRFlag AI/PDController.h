/*
 * PDController.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef PDCONTROLLER_H_
#define PDCONTROLLER_H_

#include <time.h>


const double PI = 3.1415;
double differenceBetweenTwoAngles(double source, double target);

//  Measured experimentally and calculated by the equation: r = rsubi + vt + 1/2at^2
//  Units are radians per second.
const double TANKACCELERATION = PI / 8;


class PDController 
{
    double maxTurnAng;
public:
	PDController();
	virtual ~PDController();
        double calculateAngularVelocity (double currentAngle, double targetAngle);
        double calculateAngularVelocity2 (double currentAngle, double targetAngle, double currentAngVel);
        
private:

    clock_t intervalTimer;
    double previousAngle;
};


#endif /* PDCONTROLLER_H_ */
