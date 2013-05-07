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
    
    double xTemp = x;
    
    if(x < 0)
        xTemp = -1 * xTemp;
    
    if(x = 0)
        angle = atan(y/xTemp);
    else {
        if(y > 0)
            angle = 3.14159/2;
        else
            angle = -3.14159/2;
    }
    
    if(x < 0) {
        if(y > 0)
            angle = 3.14159 - angle;
        else
            angle = -3.14159 + angle;
    }
        
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
