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
#include "UniformCostArraySearcher.h"


class BehaviorTankAI : public TankAI
{
public:
	BehaviorTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder);
        void setToDefend(Point p);
        void setToCapture();
        void setToEvade();
        void controlTank();
	virtual ~BehaviorTankAI();
        
        
        
private:
    
    enum Priority
    {
        CAPTURE, DEFEND, EVADE
    };
    
    Priority currentPriority;
    vector<TankTargeter>* enemies;
    PDController pdController;
    int SHOTSPEED;
    int SHOTRANGE;
    Point pointToDefend;
};



#endif	/* BEHAVIORTANKAI_H */

