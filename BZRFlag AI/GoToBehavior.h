/* 
 * File:   GoToBehavior.h
 * Author: zygoth
 *
 * Created on June 12, 2013, 2:29 PM
 */

#ifndef GOTOBEHAVIOR_H
#define	GOTOBEHAVIOR_H

#include "Behavior.h"
#include "PDController.h"
#include "UniformCostArraySearcher.h"

class GoToBehavior : public Behavior
{
public:
    GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder);
    GoToBehavior(const GoToBehavior& orig, UniformCostArraySearcher* pathFinder);
    virtual void doMove();
    virtual ~GoToBehavior();
    
private:
    PDController pdController;
    UniformCostArraySearcher* pathFinder;
};

#endif	/* GOTOBEHAVIOR_H */

