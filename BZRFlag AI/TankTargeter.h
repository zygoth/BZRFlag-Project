/* 
 * File:   TankTargeter.h
 * Author: cj1of4
 *
 * Created on June 3, 2013, 4:48 PM
 */

#ifndef TANKTARGETER_H
#define	TANKTARGETER_H

#include "Eigen/Core"
#include "Eigen/Dense"
#include "470bot.h"
#include "Point.h"
#include <ctime>
#include <boost/timer.hpp>

using namespace Eigen;

class TankTargeter
{
    
public:
    TankTargeter(BZRC* connection, int tankNumber);
    virtual ~TankTargeter();
    void update();
    Point getTargetPoint(double time);
    Point getCurrentPoint();
    static void test();
    
private:
    //boost::timer timer;
    //clock_t timer;
    timespec previousTime;
    double timeStamp, timeInterval, c;
    BZRC* socket;
    int tankIndex;
    MatrixXf targetValues;
    MatrixXf targetChanges;
    
    MatrixXf transitionMatrix;
    MatrixXf noiseMatrix;
    MatrixXf observationMatrix;
    Matrix2f covarianceMatrix;
    MatrixXf observationT;
    MatrixXf transitionT;
    
};

#endif	/* TANKTARGETER_H */

