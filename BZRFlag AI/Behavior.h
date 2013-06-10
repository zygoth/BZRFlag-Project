/* 
 * File:   Behavior.h
 * Author: zygoth
 *
 * Created on June 10, 2013, 2:22 PM
 */

#ifndef BEHAVIOR_H
#define	BEHAVIOR_H

#include "470bot.h"
#include "PotentialFieldCalculator.h"
#include "TankTargeter.h"

class Behavior
{
public:    
    Behavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
    virtual void getNextMove(double* newSpeed, double* newAngularVelocity);
    virtual ~Behavior();
    
protected: 
    BZRC* connection;
    int tankNumber;
    TeamColor myColor;
    vector<TankTargeter>* enemies;
    int SHOTSPEED;
    int SHOTRANGE;

};

#endif	/* BEHAVIOR_H */

