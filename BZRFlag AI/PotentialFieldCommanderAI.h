/* 
 * File:   PotentialFieldTeam.h
 * Author: zygoth
 *
 * Created on May 8, 2013, 11:15 AM
 */

#ifndef POTENTIALFIELDTEAMAI_H
#define	POTENTIALFIELDTEAMAI_H

#include "CommanderAI.h"
using namespace std;

class PotentialFieldCommanderAI : public CommanderAI
{
public:
    PotentialFieldCommanderAI(BZRC* connection);
    void controlTeam();
    virtual ~PotentialFieldCommanderAI();
    
private:
    vector<TankAI*> tankAIs;
};

#endif	/* POTENTIALFIELDTEAM_H */

