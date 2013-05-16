/* 
 * File:   GNUPrinter.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 2:44 PM
 */

#ifndef GNUPRINTER_H
#define	GNUPRINTER_H

#include <string>
#include "Point.h"
#include "470bot.h"

using namespace std;

class GNUPrinter
{
public:
    
    GNUPrinter();
    void insertLine(double x1, double y1, double x2, double y2, bool withArrow);
    void insertSquare(double x, double y);
    void insertPause(double seconds);
    void insertClearGraph();
    void insertDrawObstacles(BZRC* connection);
    void outputToFile(string fileName);
    virtual ~GNUPrinter();
    
private:
    string content;
    vector<Point> squares;
    string printHeader();
    string printArrowsHeader();
    string printSquares();
    string printFooter();

};

#endif	/* GNUPRINTER_H */

