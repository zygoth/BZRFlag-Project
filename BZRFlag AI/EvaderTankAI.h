/* 
 * File:   EvaderTankAI.h
 * Author: zygoth
 *
 * Created on June 3, 2013, 3:37 PM
 */

#ifndef EVADERTANKAI_H
#define	EVADERTANKAI_H

#include "470bot.h"
#include "PotentialFieldCalculator.h"
#include "TankAI.h"
#include <time.h>

class EvaderTankAI : public TankAI
{
public:
    EvaderTankAI(BZRC* connection, int tankNumber, TeamColor myColor);
    void controlTank();
    virtual ~EvaderTankAI();
    
private:
    time_t movementTimer;
};

#endif	/* EVADERTANKAI_H */

