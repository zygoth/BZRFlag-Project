/* 
 * File:   EvadeBehavior.h
 * Author: zygoth
 *
 * Created on June 11, 2013, 12:08 PM
 */

#ifndef EVADEBEHAVIOR_H
#define	EVADEBEHAVIOR_H

#include "Behavior.h"
#include "PDController.h"

class EvadeBehavior : public Behavior
{
public:
    EvadeBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
    EvadeBehavior(const EvadeBehavior& orig);
    virtual void doMove();
    virtual ~EvadeBehavior();
private:
    int action;
    double targetAngle;
    PDController pdController;
    
};

#endif	/* EVADEBEHAVIOR_H */

