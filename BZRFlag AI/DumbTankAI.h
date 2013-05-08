/*
 * DumbTankAI.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef DUMBTANKAI_H_
#define DUMBTANKAI_H_

#include "TankAI.h"
#include <time.h>
#include "470bot.h"

class DumbTankAI : public TankAI
{
public:
	DumbTankAI(BZRC* connection, int tankNumber);
        void controlTank();
	virtual ~DumbTankAI();
        
private:
    BZRC* server;
    clock_t shotTimer;
    clock_t movementTimer;
    bool isTurning;
    int tankNumber;
};

#endif /* DUMBTANKAI_H_ */
