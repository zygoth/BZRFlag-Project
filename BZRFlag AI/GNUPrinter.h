/* 
 * File:   GNUPrinter.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 2:44 PM
 */

#ifndef GNUPRINTER_H
#define	GNUPRINTER_H

#include <string>

using namespace std;

class GNUPrinter
{
public:
    
    GNUPrinter();
    string insertLine(double x1, double y1, double x2, double y2, bool withArrow);
    string insertPause(double seconds);
    string insertClearGraph();
    string outputToFile(string fileName);
    virtual ~GNUPrinter();
    
private:
    string content;
    string printHeader();
    string printFooter();

};

#endif	/* GNUPRINTER_H */

