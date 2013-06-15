/* 
 * File:   EvadeBehavior.h
 * Author: zygoth
 *
 * Created on June 11, 2013, 12:08 PM
 */

#ifndef EVADEBEHAVIOR_H
#define	EVADEBEHAVIOR_H

#include "Behavior.h"
#include "PDController.h"
#include "UniformCostArraySearcher.h"

class EvadeBehavior : public Behavior
{
public:
    EvadeBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder);
    EvadeBehavior(const Behavior& orig, UniformCostArraySearcher* pathFinder);
    virtual void doMove();
    virtual ~EvadeBehavior();
private:
    int action;
    double targetAngle, targetSpeed;
    PDController pdController;
    UniformCostArraySearcher* path;
    
};

#endif	/* EVADEBEHAVIOR_H */

