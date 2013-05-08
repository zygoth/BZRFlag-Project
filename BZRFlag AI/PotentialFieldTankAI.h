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

class PotentialFieldTankAI : public TankAI
{
public:
    PotentialFieldTankAI(BZRC* connection, int tankNumber);
    void controlTank();
    virtual ~PotentialFieldTankAI();
private:

};

#endif	/* POTENTIALFIELDTANKAI_H */

