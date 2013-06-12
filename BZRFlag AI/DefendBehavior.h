/* 
 * File:   DefendBehavior.h
 * Author: zygoth
 *
 * Created on June 11, 2013, 12:15 PM
 */

#ifndef DEFENDBEHAVIOR_H
#define	DEFENDBEHAVIOR_H

#include "Behavior.h"
#include "PDController.h"

class DefendBehavior : public Behavior
{
public:
    DefendBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
    DefendBehavior(const DefendBehavior& orig);
    virtual void doMove();
    virtual ~DefendBehavior();
    
private:
    
    TankTargeter* currentTarget;
    PDController pdController;
    void selectTarget();
};

#endif	/* DEFENDBEHAVIOR_H */

