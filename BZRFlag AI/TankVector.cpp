/*
 * TankVector.cpp
 *
 *  Created on: May 7, 2013
 *      Author: cj1of4
 */

#include "TankVector.h"

TankVector::TankVector(double over, double up) {
    x = over;
    y = up;
    

    
    angle = atan2(y, x);
    
    velocity = pow(pow(x,2) + pow(y,2), .5);
    if(velocity > 1.0)
        velocity = 1.0;
}

TankVector::~TankVector() {

}

double TankVector::getAngle() {
    return angle;
}

double TankVector::getVelocity() {
    return velocity;     
}

double TankVector::getXVector() {
    return x;
}

double TankVector::getYVector() {
    return y;
}
