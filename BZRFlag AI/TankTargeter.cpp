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
    
    c = 0.0;
    timeInterval = -1.0;
    
    timer = time(&timer);
    
    double x, y;
    vector<otank_t> badTanks;
    socket->get_othertanks(&badTanks);
    otank_t tank = badTanks.at(tankIndex);
    
    vector<base_t> bases;
    socket->get_bases(&bases);
    
    for(int i = 0; i < bases.size(); i++)
    {
        if(bases.at(i).color.compare(tank.color) == 0)
        {
            x = bases.at(i).base_corner[0][0]
              - bases.at(i).base_corner[2][0];
            y = bases.at(i).base_corner[0][1]
              - bases.at(i).base_corner[2][1];
            
            x = bases.at(i).base_corner[2][0]
              + x/2;
            y = bases.at(i).base_corner[2][1]
              + y/2;
            
        }
    }
    
    targetValues = MatrixXf::Zero(6,1);
    targetValues(0,0) = x;
    targetValues(3,0) = y;
    
    targetChanges = MatrixXf::Zero(6,6);
    targetChanges(0,0) = 25;
    targetChanges(1,1) = 0.1;
    targetChanges(2,2) = 0.1;
    targetChanges(3,3) = 25;
    targetChanges(4,4) = .01;
    targetChanges(5,5) = .01;
    
    transitionMatrix = MatrixXf::Identity(6,6);
    transitionMatrix(2,1) = -1 * c;
    transitionMatrix(5,4) = -1 * c;
    
    noiseMatrix = MatrixXf::Zero(6,6);
    noiseMatrix(0,0) = 0.1;
    noiseMatrix(1,1) = 0.1;
    noiseMatrix(2,2) = 100;
    noiseMatrix(3,3) = 0.1;
    noiseMatrix(4,4) = 0.1;
    noiseMatrix(5,5) = 100;
    
    observationMatrix = MatrixXf::Zero(2,6);
    observationMatrix(0,0) = 1;
    observationMatrix(1,3) = 1;
    
    covarianceMatrix = Matrix2f::Zero();
    covarianceMatrix(0,0) = 25;
    covarianceMatrix(1,1) = 25;
    
    observationT = observationMatrix.transpose();
    
    cout << observationT << endl;
    
    badTanks.clear();
    bases.clear();
}

TankTargeter::~TankTargeter(){}

Point TankTargeter::getTargetPoint(double time)
{
    MatrixXf temp = MatrixXf::Identity(6,6);
    temp(2,1) = -1 * c;
    temp(5,4) = -1 * c;
    
    temp(0,1) = time;
    temp(1,2) = time;
    temp(3,4) = time;
    temp(4,5) = time;
    double squaredTime = pow(time,2);
    temp(0,2) = squaredTime/2;
    temp(3,5) = squaredTime/2;

    MatrixXf futureValues = temp * targetValues;
    
    return Point(futureValues(0,0),futureValues(3,0));
}

Point TankTargeter::getCurrentPoint()
{
    return Point(targetValues(0,0), targetValues(3,0));
}

void TankTargeter::update()
{
    if(timeInterval < 0)
    {
        timeInterval = 0.1;
        timeStamp = double(timer);
        return;
    }
    
    time_t nowTime = time(&nowTime);
    double intervalCheck = ((double(nowTime) - timeStamp) / CLOCKS_PER_SEC) * 1000000;
    timeStamp = double(timer);
    
    if(timeInterval != intervalCheck)
    {
        timeInterval = intervalCheck;
        
        transitionMatrix(0,1) = timeInterval;
        transitionMatrix(1,2) = timeInterval;
        transitionMatrix(3,4) = timeInterval;
        transitionMatrix(4,5) = timeInterval;
        double squaredInterval = pow(timeInterval,2);
        transitionMatrix(0,2) = squaredInterval/2;
        transitionMatrix(3,5) = squaredInterval/2;
        
        transitionT = transitionMatrix.transpose();
    }
    
    MatrixXf temp = transitionMatrix * 
                    targetChanges * noiseMatrix;
    
    MatrixXf inverseMatrix = (observationMatrix * temp * 
                                observationT + covarianceMatrix);
        
    MatrixXf nextStep = temp * observationT * inverseMatrix.inverse();
    
    MatrixXf zMatrix;
    zMatrix = MatrixXf::Zero(2,1);
    
    vector<tank_t> myTanks;
    socket->get_mytanks(&myTanks);
    
    zMatrix(0,0) = myTanks.at(tankIndex).pos[0];
    zMatrix(1,0) = myTanks.at(tankIndex).pos[1];
    
    targetValues = (transitionMatrix * targetValues) + (nextStep *
            (zMatrix - (observationMatrix * transitionMatrix * targetValues)));
    
    targetChanges = (MatrixXf::Identity(6,6) - nextStep * observationMatrix) * temp;
    
    
}

void TankTargeter::test()
{
    BZRC connection("localhost", 60618, false);
    TankTargeter* temp = new TankTargeter(&connection, 0);
    
    delete temp;
}
