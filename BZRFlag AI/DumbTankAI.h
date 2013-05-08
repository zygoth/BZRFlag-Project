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
    BZRC* connection;
    clock_t startClock;
    int tankNumber;
};

#endif /* DUMBTANKAI_H_ */
