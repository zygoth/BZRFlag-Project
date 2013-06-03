/* 
 * File:   StraightLineCommanderAI.h
 * Author: zygoth
 *
 * Created on June 3, 2013, 2:39 PM
 */

#ifndef STRAIGHTLINECOMMANDERAI_H
#define	STRAIGHTLINECOMMANDERAI_H

#include "CommanderAI.h"
#include "470bot.h"

class StraightLineCommanderAI : public CommanderAI
{
public:
    StraightLineCommanderAI(BZRC* connection);
    void controlTeam();
    virtual ~StraightLineCommanderAI();
private:
    vector<TankAI*> tankAIs;

};

#endif	/* STRAIGHTLINECOMMANDERAI_H */

