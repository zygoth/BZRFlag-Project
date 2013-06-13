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

enum Behavior_t
{
    GOTOBEHAVIOR, DEFENDBEHAVIOR, EVADEBEHAVIOR
};

class Behavior
{
public:    
    Behavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
    Behavior(const Behavior& other);
    tank_t getMyTank();
    virtual void doMove();
    virtual Behavior_t getType();
    virtual ~Behavior();
    
protected: 
    BZRC* connection;
    int tankNumber;
    TeamColor myColor;
    vector<TankTargeter>* enemies;
    int SHOTSPEED;
    int SHOTRANGE;
    Behavior_t myType;
};

#endif	/* BEHAVIOR_H */

