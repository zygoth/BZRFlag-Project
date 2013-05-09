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
    
    string printHeader();
    string printObstacleData(BZRC* connection);
    string printVectorData(BZRC* connection);
    string printFooter();
};

#endif	/* POTENTIALFIELDPRINTER_H */

