/* 
 * File:   BZRCTools.h
 * Author: zygoth
 *
 * Created on June 14, 2013, 3:07 PM
 */

#ifndef BZRCTOOLS_H
#define	BZRCTOOLS_H

#include "470bot.h"
#include "PotentialFieldCalculator.h"
#include "UniformCostArraySearcher.h"
#include "Point.h"
#include "TankTargeter.h"

class BZRCTools
{
public:
    BZRCTools();
    static base_t getBase(BZRC* connection, TeamColor color);
    static Point getBaseCenter(BZRC* connection, TeamColor color);
    static bool hitCheck(tank_t me, shot_t bullet, int, UniformCostArraySearcher*);
    static bool objectBetween(int x1, int y1, int x2, int y2, UniformCostArraySearcher*);
    static bool shouldShoot(BZRC* connection, vector<TankTargeter>* enemies, tank_t me);
    static bool simpleShouldShoot(BZRC* connection, vector<TankTargeter>* enemies, tank_t me);
    virtual ~BZRCTools();
private:

};

#endif	/* BZRCTOOLS_H */

