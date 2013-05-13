/* 
 * File:   GNUPrinter.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 2:44 PM
 */

#include "GNUPrinter.h"
#include <fstream>

GNUPrinter::GNUPrinter()
{
    
}

string GNUPrinter::insertLine(double x1, double y1, double x2, double y2, bool withArrow)
{
    char buffer[100];
    string arrowheadString = (withArrow ? "" : "nohead ");
    
    sprintf(buffer, "set arrow from %f, %f to %f, %f ", x1, y1, x2, y2);
    sprintf(buffer, arrowheadString.c_str());
    sprintf(buffer, "lt 3\n");
    
    content += buffer;
}

string GNUPrinter::insertPause(double seconds)
{
    char buffer[100];
    sprintf(buffer, "%f", seconds);
    
    content += "pause ";
    content += buffer;
    content += "\n";
}

string GNUPrinter::insertClearGraph()
{
    content += "clear\n";
}

string GNUPrinter::outputToFile(string fileName)
{
       ofstream myfile;
       myfile.open(fileName.c_str());
       myfile << printHeader();
       myfile << content.c_str();
       myfile << printFooter();
       myfile.close();
}

string GNUPrinter::printHeader()
{
    string headerString;
    
    headerString = "set title \"My Title\"\nset xrange [-400.0: 400.0]\n";
    headerString += "set yrange [-400.0: 400.0]\nunset key\nset size square\n";
    
    return headerString;
}

string GNUPrinter::printFooter()
{
    string footerString;
    
    //footerString += "plot -400\n";  // needed so it will render
    footerString += "exit";
    
    return footerString;
}

GNUPrinter::~GNUPrinter()
{
}

