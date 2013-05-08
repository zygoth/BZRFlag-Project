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
#include "PotentialFieldCalculator.h"

class CommanderAI {
public:
	CommanderAI(BZRC* connection);
        virtual void controlTeam();        
	virtual ~CommanderAI();
        
protected:
    TeamColor pickRandomTarget();
    TeamColor myColor;
    BZRC* connection;
    
private:
    TeamColor determineMyColor();
};

#endif /* TEAMAI_H_ */
