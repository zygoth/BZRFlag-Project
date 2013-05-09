/* 
 * File:   PotentialFieldPrinter.cpp
 * Author: zygoth
 * 
 * Created on May 9, 2013, 11:06 AM
 */

#include "PotentialFieldPrinter.h"

PotentialFieldPrinter::PotentialFieldPrinter()
{
}

string PotentialFieldPrinter::getGNUPlotFile(BZRC* connection)
{
    string returnedString;
    
    string headerString;
    string obstaclesString;
    string vectorsString;
    
    headerString = "set title \"My Title\"\nset xrange [-400.0: 400.0]\n";
    headerString += "set yrange [-400.0: 400.0]\nunset key\nset size square";
    
    
       
}

string PotentialFieldPrinter::printObstacleData(BZRC* connection)
{
    vector<obstacle_t> obstacles;
    connection->get_obstacles(&obstacles);
    
    char buff[100];
    string s;
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
            s += buff;
        }
    }
    return s;
}

PotentialFieldPrinter::~PotentialFieldPrinter()
{
}

