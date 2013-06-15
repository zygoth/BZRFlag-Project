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
#include "Point.h"

class GoToBehavior : public Behavior
{
public:
    GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder,
                Point targetPoint);
    GoToBehavior(const Behavior& orig, UniformCostArraySearcher* pathFinder, Point targetPoint);
    virtual void doMove();
    virtual ~GoToBehavior();
    Point targetPoint;
    
private:
    
    Point intermediatePoint;
    PDController pdController;
    int searchCounter;
    
    // this is owned by the Commander and used by other TankAIs--don't delete it!
    UniformCostArraySearcher* pathFinder;
};

#endif	/* GOTOBEHAVIOR_H */

