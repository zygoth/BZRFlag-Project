/*
 * PotentialFieldCalculator.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "PotentialFieldCalculator.h"

PotentialFieldCalculator::PotentialFieldCalculator() {
}

PotentialFieldCalculator::~PotentialFieldCalculator() {
}

TankVector* PotentialFieldCalculator::calculateVector(int x, int y) {
    return new TankVector((double)x, (double)y);
}

