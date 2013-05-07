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
	DumbTeamAI();
        void controlTeam();
	virtual ~DumbTeamAI();
};

#endif /* DUMBTEAMAI_H_ */
