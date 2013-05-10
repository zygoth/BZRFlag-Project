/*
 * PDController.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "PDController.h"
#include <cstdlib>


PDController::PDController() 
{
    maxTurnAng = PI/2;
    intervalTimer = time(&intervalTimer);
    previousAngle = 0;
}


double PDController::calculateAngularVelocity (double currentAngle, double targetAngle) 
{
    double turnAng = targetAngle - currentAngle;
    double resultVelocity = -1.0;

    if(turnAng > PI)
	turnAng = turnAng - (2 * PI);
    if(turnAng < -1*PI)
	turnAng = turnAng + (2 * PI);

    if(turnAng > 0)
	resultVelocity = 1.0;

    
    if(turnAng < maxTurnAng && turnAng > -1 * maxTurnAng)
	resultVelocity = (turnAng/maxTurnAng);
    
    return resultVelocity;
}

double PDController::calculateAngularVelocity2(double currentAngle, double targetAngle, double currentAngVel)
{
    const int slowDownZoneWidth = 15;
    
    clock_t nowTime = time(&nowTime);
    double elapsedSeconds = (double(nowTime - intervalTimer) / CLOCKS_PER_SEC);
    double realVelocity = differenceBetweenTwoAngles(previousAngle, currentAngle) * elapsedSeconds;
    double discrepancy = differenceBetweenTwoAngles(currentAngle, targetAngle);
    double returnedVelocity = 0;
    const double EPSILON = .05;
    
    if(abs(discrepancy) < EPSILON) // we are already at the target
    {
        returnedVelocity = 0;
    }
    
    else
        
    if(abs(discrepancy) < abs(slowDownZoneWidth * realVelocity)) // we'll hit the target soon
    {
        if(currentAngVel > 0)
        {
            returnedVelocity = realVelocity - .05;
        }
        else
        {
            returnedVelocity = realVelocity + .05;
        }
    }    
    else // we aren't even close to the target       
    {
        returnedVelocity = discrepancy / PI;
    }
    
    intervalTimer = time(&intervalTimer);
    previousAngle = currentAngle;
    
    return returnedVelocity;
}

/**
 * This function returns the smallest signed difference between two angles.
 * The answer is guaranteed to be between PI and -PI
 * 
 * @param target the target angle, in radians
 * @param source the source angle, in radians
 * @return the smallest signed difference between the two angles.
 */
double differenceBetweenTwoAngles(double source, double target)
{
    double difference;
    
    difference = target - source;
    if(difference > 3.1415)
    {
        difference -= 2*3.1415;
    }
    
    if(difference < -3.1415)
    {
        difference += 3.1415*2;
    }
    
    return difference;
}

PDController::~PDController() 
{
	// TODO Auto-generated destructor stub
}