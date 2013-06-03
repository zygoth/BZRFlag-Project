/* 
 * File:   TankTargeter.h
 * Author: cj1of4
 *
 * Created on June 3, 2013, 4:48 PM
 */

#ifndef TANKTARGETER_H
#define	TANKTARGETER_H

#include "Eigen/Core"
#include "470bot.h"
#include "Point.h"

using namespace Eigen;

class TankTargeter
{
    
public:
    TankTargeter(BZRC* connection, int tankNumber);
    virtual ~TankTargeter();
    Point getTargetValue();
    
private:
    BZRC* socket;
    int tankIndex;
    MatrixXf targetValues;
    MatrixXf targetChanges;
    
};

#endif	/* TANKTARGETER_H */

