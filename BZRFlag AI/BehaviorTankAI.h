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
#include "Behavior.h"
#include <ctime>
#include <boost/timer.hpp>



class BehaviorTankAI : public TankAI
{
public:
	BehaviorTankAI(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies, UniformCostArraySearcher* pathFinder);
        void setToDefend(Point p);
        void setToCapture();
        void setToEvade();
        tank_t getMyTank();
        void controlTank();
	virtual ~BehaviorTankAI();
        
        
        
private:
    
    enum Priority
    {
        CAPTURE, DEFEND, EVADE
    };
    
    UniformCostArraySearcher* pathFinder;
    Behavior* currentBehavior;
    Priority currentPriority;
    Priority lastPriority;
    vector<TankTargeter>* enemies;
    PDController pdController;
    int SHOTSPEED;
    int SHOTRANGE;
    Point pointToDefend;
    timespec previousTime;
    int shotCounter;
    
    void doCapture();
    void doDefend();
    void doEvade();
};



#endif	/* BEHAVIORTANKAI_H */

