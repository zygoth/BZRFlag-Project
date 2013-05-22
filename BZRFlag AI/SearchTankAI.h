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

class SearchTankAI : TankAI
{
public:
    
    SearchTankAI(BZRC* connection);
    virtual void controlTank();
    virtual ~SearchTankAI();
    
private:
    
    PDController controller;
    PotentialFieldCalculator* PFCalculator;
    //TargetPointGenerator targetGenerator;
    //GridFilter* settledGrid;
};

#endif	/* SEARCHTANKAI_H */

