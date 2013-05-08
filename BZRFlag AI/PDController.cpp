/*
 * PDController.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "PDController.h"

PDController::PDController() {
    pi = 3.14159;
    maxTurnAng = pi/2;
}

PDController::~PDController() {
	// TODO Auto-generated destructor stub
}

double PDController::calculateAngularVelocity (double currentAngle, double targetAngle) 
{
    double turnAng = targetAngle - currentAngle;
    double result = -1.0;

    if(turnAng > pi)
	turnAng = turnAng - (2 * pi);
    if(turnAng < -1*pi)
	turnAng = turnAng + (2 * pi);

    if(turnAng > 0)
	result = 1.0;

    if(turnAng < maxTurnAng && turnAng > -1 * maxTurnAng)
	result = (turnAng/maxTurnAng);

    return result;
}