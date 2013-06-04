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
#include "TankTargeter.h"
#include "PDController.h"

class ShooterTankAI : public TankAI
{
public:
	ShooterTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
        void controlTank();
	virtual ~ShooterTankAI();
        
private:
    vector<TankTargeter>* enemies;
    PDController pdController;
    int SHOTSPEED;
    int SHOTRANGE;
};

#endif	/* SHOOTERTANKAI_H */

