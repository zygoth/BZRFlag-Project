/* 
 * File:   PotentialFieldPrinter.h
 * Author: zygoth
 *
 * Created on May 9, 2013, 11:06 AM
 */

#ifndef POTENTIALFIELDPRINTER_H
#define	POTENTIALFIELDPRINTER_H

#include "PotentialFieldCalculator.h"

class PotentialFieldPrinter
{
public:
    PotentialFieldPrinter();
    string getGNUPlotFile(BZRC* connection);
    virtual ~PotentialFieldPrinter();
private:
    string printObstacleData(BZRC* connection);

};

#endif	/* POTENTIALFIELDPRINTER_H */

