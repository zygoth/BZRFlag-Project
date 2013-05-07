/*
 * PotentialFieldCalculator.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef POTENTIALFIELDCALCULATOR_H_
#define POTENTIALFIELDCALCULATOR_H_

#include "TankVector.h"

class PotentialFieldCalculator {
        
public:
	PotentialFieldCalculator();
	virtual ~PotentialFieldCalculator();
        TankVector* calculateVector(int, int);
};

#endif /* POTENTIALFIELDCALCULATOR_H_ */

