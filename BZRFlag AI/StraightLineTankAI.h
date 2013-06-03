/* 
 * File:   StraightLineTankAI.h
 * Author: zygoth
 *
 * Created on June 3, 2013, 2:36 PM
 */

#ifndef STRAIGHTLINETANKAI_H
#define	STRAIGHTLINETANKAI_H

#include "470bot.h"
#include "PotentialFieldCalculator.h"
#include "TankAI.h"
#include <time.h>

class StraightLineTankAI : public TankAI
{
public:
    StraightLineTankAI(BZRC* connection, int tankNumber, TeamColor myColor);
    void controlTank();
    virtual ~StraightLineTankAI();
private:
    time_t movementTimer;
    bool isTurning;

};

#endif	/* STRAIGHTLINETANKAI_H */

