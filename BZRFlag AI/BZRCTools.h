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

class BZRCTools
{
public:
    BZRCTools();
    static base_t getBase(BZRC* connection, TeamColor color);
    virtual ~BZRCTools();
private:

};

#endif	/* BZRCTOOLS_H */

