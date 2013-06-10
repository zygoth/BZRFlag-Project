/* 
 * File:   BehaviorTankAI.h
 * Author: zygoth
 *
 * Created on June 10, 2013, 2:02 PM
 */

#ifndef BEHAVIORTANKAI_H
#define	BEHAVIORTANKAI_H

#include "TankAI.h"
#include <time.h>
#include "470bot.h"
#include "TankTargeter.h"
#include "PDController.h"

class BehaviorTankAI : public TankAI
{
public:
	BehaviorTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
        void controlTank();
	virtual ~BehaviorTankAI();
        
private:
    vector<TankTargeter>* enemies;
    PDController pdController;
    int SHOTSPEED;
    int SHOTRANGE;
};

#endif	/* BEHAVIORTANKAI_H */

