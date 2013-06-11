/* 
 * File:   CaptureBehavior.h
 * Author: zygoth
 *
 * Created on June 11, 2013, 12:19 PM
 */

#ifndef CAPTUREBEHAVIOR_H
#define	CAPTUREBEHAVIOR_H

#include "Behavior.h"

class CaptureBehavior : public Behavior
{
public:
    CaptureBehavior(BZRC* server, int tankNumber, TeamColor myColor,
                vector<TankTargeter>* enemies);
    CaptureBehavior(const CaptureBehavior& orig);
    virtual void doMove();
    virtual ~CaptureBehavior();
private:

};

#endif	/* CAPTUREBEHAVIOR_H */

