/*
 * DumbTeamAI.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef DUMBTEAMAI_H_
#define DUMBTEAMAI_H_

#include "TeamAI.h"

class DumbTeamAI : public TeamAI
{
public:
	DumbTeamAI(BZRC* connection);
        void controlTeam();
	virtual ~DumbTeamAI();

private:
    vector<TankAI*> tankAIs;
};

#endif /* DUMBTEAMAI_H_ */
