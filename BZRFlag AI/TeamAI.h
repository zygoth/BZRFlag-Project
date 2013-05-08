/*
 * TeamAI.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef TEAMAI_H_
#define TEAMAI_H_

#include "TankAI.h"
#include "470bot.h"

class TeamAI {
public:
	TeamAI(BZRC* connection);
        virtual void controlTeam();
	virtual ~TeamAI();
        
protected:
    BZRC* connection;
};

#endif /* TEAMAI_H_ */
