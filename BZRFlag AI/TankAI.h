/*
 * TankAI.h
 *
 *  Created on: May 4, 2013
 *      Author: Ben
 */

#ifndef TANKAI_H_
#define TANKAI_H_

#include "PotentialFieldCalculator.h"

class TankAI 
{
public:

    virtual void controlTank();
    virtual ~TankAI();
        
protected:
    
    TankAI(BZRC* connection);
    TankAI(BZRC* connection, int TankNumber, TeamColor myColor, TeamColor targetColor);
    BZRC* connection;
    int tankNumber;
    TeamColor myColor;
    TeamColor targetColor;
};

#endif /* TANKAI_H_ */
