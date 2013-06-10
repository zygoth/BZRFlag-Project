/* 
 * File:   BehaviorCommanderAI.h
 * Author: zygoth
 *
 * Created on June 10, 2013, 1:59 PM
 */

#ifndef BEHAVIORCOMMANDERAI_H
#define	BEHAVIORCOMMANDERAI_H

#include "CommanderAI.h"
#include "TankTargeter.h"

class BehaviorCommanderAI : public CommanderAI
{
public:
	BehaviorCommanderAI(BZRC* connection);
        void controlTeam();
	virtual ~BehaviorCommanderAI();

private:
    vector<TankAI*> tankAIs;
    vector<TankTargeter> tankTargeters;
};

#endif	/* BEHAVIORCOMMANDERAI_H */

