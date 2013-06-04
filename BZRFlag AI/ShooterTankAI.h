/* 
 * File:   ShooterTankAI.h
 * Author: zygoth
 *
 * Created on June 4, 2013, 12:01 PM
 */

#ifndef SHOOTERTANKAI_H
#define	SHOOTERTANKAI_H

#include "TankAI.h"
#include <time.h>
#include "470bot.h"

class ShooterTankAI : public TankAI
{
public:
	ShooterTankAI(BZRC* server, int tankNumber, TeamColor myColor);
        void controlTank();
	virtual ~ShooterTankAI();
        
private:
    
};

#endif	/* SHOOTERTANKAI_H */

