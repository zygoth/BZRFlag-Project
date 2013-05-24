/* 
 * File:   SearchTankAI.h
 * Author: zygoth
 *
 * Created on May 22, 2013, 3:26 PM
 */

#ifndef SEARCHTANKAI_H
#define	SEARCHTANKAI_H

#include "TankAI.h"
#include "PotentialFieldCalculator.h"
#include "PDController.h"
#include "TargetPointCalculator.h"
#include "GridFilter.h"

class SearchTankAI : TankAI
{
public:
    
    SearchTankAI(BZRC* connection, int tankNumber, TeamColor myColor);
    virtual void controlTank();
    virtual ~SearchTankAI();
    
private:
    
    PDController* controller;
    PotentialFieldCalculator* PFCalculator;
    TargetPointCalculator* targetGenerator;
    GridFilter* settledGrid;
};

#endif	/* SEARCHTANKAI_H */

