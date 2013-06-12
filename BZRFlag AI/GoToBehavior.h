/* 
 * File:   GoToBehavior.h
 * Author: zygoth
 *
 * Created on June 12, 2013, 2:29 PM
 */

#ifndef GOTOBEHAVIOR_H
#define	GOTOBEHAVIOR_H

#include "Behavior.h"

class GoToBehavior : public Behavior
{
public:
    GoToBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
    GoToBehavior(const GoToBehavior& orig);
    virtual void doMove();
    virtual ~GoToBehavior();
private:

};

#endif	/* GOTOBEHAVIOR_H */

