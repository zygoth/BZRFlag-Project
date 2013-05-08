/* 
 * File:   PotentialFieldTankAI.h
 * Author: zygoth
 *
 * Created on May 8, 2013, 11:17 AM
 */

#ifndef POTENTIALFIELDTANKAI_H
#define	POTENTIALFIELDTANKAI_H

#include "TankAI.h"
#include "470bot.h"
#include "PDController.h"

class PotentialFieldTankAI : public TankAI
{
public:
    PotentialFieldTankAI(BZRC* connection, int tankNumber, TeamColor myColor, TeamColor targetColor);
    void controlTank();
    virtual ~PotentialFieldTankAI();
private:
    PotentialFieldCalculator* fieldCalculator;
    PDController* pdController;
};

#endif	/* POTENTIALFIELDTANKAI_H */

