/*
 * PotentialFieldCalculator.cpp
 *
 *  Created on: May 6, 2013
 *      Author: zygoth
 */

#include "PotentialFieldCalculator.h"
#include <iostream>
#include <unistd.h>

#include "470bot.h"
using namespace std;

PotentialFieldCalculator::PotentialFieldCalculator() {
}

PotentialFieldCalculator::~PotentialFieldCalculator() {
}

TankVector* PotentialFieldCalculator::calculateVector(int x, int y, TeamColor team) {
    xVector = 0.0; 
    yVector = 0.0;
    TankVector* result;
    
    calculateObjectVector(x, y);
    calculateShotVector(x,y);
    calculateFriendlyTanks(x,y);
    calculateEnemyTanks(x,y);
    calculateTargetVector(x,y,team);
    
    result = new TankVector(xVector, yVector);
    
    return result;
}

void PotentialFieldCalculator::calculateObjectVector(int x, int y) {
    
}

void PotentialFieldCalculator::calculateShotVector(int, int) {
    
}
        
void PotentialFieldCalculator::calculateFriendlyTanks(int, int) {
    
}
        
void PotentialFieldCalculator::calculateEnemyTanks(int, int) {
    
}
        
void PotentialFieldCalculator::calculateTargetVector(int, int, TeamColor) {
    
}
        
