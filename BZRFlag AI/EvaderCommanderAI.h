/* 
 * File:   EvaderCommanderAI.h
 * Author: zygoth
 *
 * Created on June 3, 2013, 3:37 PM
 */

#ifndef EVADERCOMMANDERAI_H
#define	EVADERCOMMANDERAI_H

#include "CommanderAI.h"
#include "470bot.h"

class EvaderCommanderAI : public CommanderAI
{
public:
    EvaderCommanderAI(BZRC* connection);
    void controlTeam();
    virtual ~EvaderCommanderAI();
private:
    vector<TankAI*> tankAIs;

};

#endif	/* EVADERCOMMANDERAI_H */

