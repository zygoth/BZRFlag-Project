/* 
 * File:   PotentialFieldTeam.h
 * Author: zygoth
 *
 * Created on May 8, 2013, 11:15 AM
 */

#ifndef POTENTIALFIELDTEAMAI_H
#define	POTENTIALFIELDTEAMAI_H

#include "TeamAI.h"
using namespace std;

class PotentialFieldTeamAI : public TeamAI
{
public:
    PotentialFieldTeamAI(BZRC* connection);
    void controlTeam();
    virtual ~PotentialFieldTeamAI();
    
private:
    vector<TankAI*> tankAIs;
};

#endif	/* POTENTIALFIELDTEAM_H */

