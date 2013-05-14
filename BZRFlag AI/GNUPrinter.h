/* 
 * File:   GNUPrinter.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 2:44 PM
 */

#ifndef GNUPRINTER_H
#define	GNUPRINTER_H

#include <string>
#include "470bot.h"

using namespace std;

class GNUPrinter
{
public:
    
    GNUPrinter();
    void insertLine(double x1, double y1, double x2, double y2, bool withArrow);
    void insertPause(double seconds);
    void insertClearGraph();
    void insertDrawObstacles(BZRC* connection);
    void outputToFile(string fileName);
    virtual ~GNUPrinter();
    
private:
    string content;
    string printHeader();
    string printFooter();

};

#endif	/* GNUPRINTER_H */

