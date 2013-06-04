/* 
 * File:   ShooterCommanderAI.h
 * Author: zygoth
 *
 * Created on June 4, 2013, 12:02 PM
 */

#ifndef SHOOTERCOMMANDERAI_H
#define	SHOOTERCOMMANDERAI_H

#include "CommanderAI.h"
#include "TankTargeter.h"

class ShooterCommanderAI : public CommanderAI
{
public:
	ShooterCommanderAI(BZRC* connection);
        void controlTeam();
	virtual ~ShooterCommanderAI();

private:
    vector<TankAI*> tankAIs;
    vector<TankTargeter> tankTargeters;
};

#endif	/* SHOOTERCOMMANDERAI_H */

