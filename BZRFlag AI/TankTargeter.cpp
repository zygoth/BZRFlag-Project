/* 
 * File:   TankTargeter.cpp
 * Author: cj1of4
 *
 * Created on June 3, 2013, 4:48 PM
 */

#include "TankTargeter.h"
#include "BZRFlagGame.h"

TankTargeter::TankTargeter(BZRC* connection, int tankNumber)
{
    socket = connection;
    tankIndex = tankNumber;
    
    double x, y;
    // set x,y to be the value of the flag
    
    targetValues =  MatrixXf::Zero(6,1);
    targetValues(0,0) = x;
    targetValues(3,0) = y;
    
    targetChanges =  MatrixXf::Zero(6,6);
    targetChanges(0,0) = 25;
    targetChanges(1,1) = 0.1;
    targetChanges(2,2) = 0.1;
    targetChanges(3,3) = 25;
    targetChanges(4,4) = .01;
    targetChanges(5,5) = .01;
    
    cout << targetValues << endl;
}

TankTargeter::~TankTargeter(){}

Point TankTargeter::getTargetPoint(double time)
{
    return Point(0,0);
}

Point TankTargeter::getCurrentPoint()
{
    
}

void TankTargeter::update()
{
    
}

void TankTargeter::test()
{
    BZRC connection("localhost", 12345, false);
    TankTargeter* temp = new TankTargeter(&connection, 0);
    
    delete temp;
}
