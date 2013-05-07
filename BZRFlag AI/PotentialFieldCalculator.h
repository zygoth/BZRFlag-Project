/*
 * PotentialFieldCalculator.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef POTENTIALFIELDCALCULATOR_H_
#define POTENTIALFIELDCALCULATOR_H_

#include "TankVector.h"

enum TeamColor{
    RED, GREEN, BLUE, PURPLE
};

class PotentialFieldCalculator {
        double xVector, yVector;
        void calculateObjectVector(int, int);
        void calculateShotVector(int, int);
        void calculateFriendlyTanks(int, int);
        void calculateEnemyTanks(int, int);
        void calculateTargetVector(int, int, TeamColor);
public:
	PotentialFieldCalculator();
	virtual ~PotentialFieldCalculator();
        TankVector* calculateVector(int, int, TeamColor);
};

#endif /* POTENTIALFIELDCALCULATOR_H_ */

