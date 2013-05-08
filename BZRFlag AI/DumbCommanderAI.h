/*
 * DumbTeamAI.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef DUMBTEAMAI_H_
#define DUMBTEAMAI_H_

#include "CommanderAI.h"

class DumbCommanderAI : public CommanderAI
{
public:
	DumbCommanderAI(BZRC* connection);
        void controlTeam();
	virtual ~DumbCommanderAI();

private:
    vector<TankAI*> tankAIs;
};

#endif /* DUMBTEAMAI_H_ */
