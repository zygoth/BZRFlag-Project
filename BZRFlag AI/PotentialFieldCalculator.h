/*
 * PotentialFieldCalculator.h
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#ifndef POTENTIALFIELDCALCULATOR_H_
#define POTENTIALFIELDCALCULATOR_H_

#include "TankVector.h"
#include "470bot.h"


enum TeamColor{
    RED, GREEN, BLUE, PURPLE
};

TeamColor stringToTeamColor(string colorString);


class PotentialFieldCalculator {
        BZRC* socket;
        double xVector, yVector;
        void calculateObjectVector(int, int);
        void calculateShotVector(int, int);
        void calculateFriendlyTanks(int, int);
        void calculateEnemyTanks(int, int);
        void calculateTargetVector(int, int, TeamColor, int);
        void avoidObjects(tank_t, grid_t);
public:
	PotentialFieldCalculator(BZRC*);
	virtual ~PotentialFieldCalculator();
        TankVector* calculateVector(int, int, TeamColor, int);
        TankVector* calculateSearcherVector(int x, int y, int index);
};

#endif /* POTENTIALFIELDCALCULATOR_H_ */

