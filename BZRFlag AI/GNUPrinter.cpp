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

void GNUPrinter::insertLine(double x1, double y1, double x2, double y2, bool withArrow)
{
    char buffer[100];
    string arrowheadString = (withArrow ? "" : "nohead ");
    
    sprintf(buffer, "set arrow from %f, %f to %f, %f ", x1, y1, x2, y2);
    sprintf(buffer, arrowheadString.c_str());
    sprintf(buffer, "lt 3\n");
    
    content += buffer;
}

void GNUPrinter::insertPause(double seconds)
{
    char buffer[100];
    sprintf(buffer, "%f", seconds);
    
    content += "pause ";
    content += buffer;
    content += "\n";
}

void GNUPrinter::insertClearGraph()
{
    content += "clear\n";
}

void GNUPrinter::insertDrawObstacles(BZRC* connection)
{
    vector<obstacle_t> obstacles;
    connection->get_obstacles(&obstacles);
    
    char buff[100];
    for (int i = 0; i < (int) obstacles.size(); i++)
    {
        double x1;
        double x2;
        double y1;
        double y2;
        obstacle_t o = obstacles.at(i);
        for (int j = 0; j < 4; j++)
        {
            x1 = o.o_corner[j][0];
            y1 = o.o_corner[j][1];
            x2 = o.o_corner[(j + 1) % 4][0];
            y2 = o.o_corner[(j + 1) % 4][1];
            sprintf(buff, "set arrow from %f, %f to %f, %f nohead lt 3\n", x1, y1, x2, y2);
            content += buff;
        }
    }
}

void GNUPrinter::outputToFile(string fileName)
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

