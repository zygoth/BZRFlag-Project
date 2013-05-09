/* 
 * File:   PotentialFieldPrinter.cpp
 * Author: zygoth
 * 
 * Created on May 9, 2013, 11:06 AM
 */

#include "PotentialFieldPrinter.h"
#include "PotentialFieldCalculator.h"
#include <fstream>
using namespace std;

PotentialFieldPrinter::PotentialFieldPrinter()
{
}

string PotentialFieldPrinter::getGNUPlotFile(BZRC* connection)
{
    string returnedString;
    
    string headerString;
    string obstaclesString;
    string* vectorsString; 
    string footerString;
    
    headerString = printHeader();
    obstaclesString = printObstacleData(connection);
    vectorsString = printVectorData(connection);
    footerString = printFooter();
    

    returnedString += headerString;
    returnedString += obstaclesString;
    returnedString += *vectorsString;
    returnedString += footerString;
    
    return returnedString;
}


void PotentialFieldPrinter::GNUOutputToFile(BZRC* connection, char * filename) 
{
       ofstream myfile;
       myfile.open(filename);
       myfile << printHeader();
       myfile << printObstacleData(connection);
       myfile << *printVectorData(connection);
       myfile << printFooter();
       myfile.close();
}


string PotentialFieldPrinter::printHeader()
{
    string headerString;
    
    headerString = "set title \"My Title\"\nset xrange [-400.0: 400.0]\n";
    headerString += "set yrange [-400.0: 400.0]\nunset key\nset size square\n";
    
    return headerString;
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

string* PotentialFieldPrinter::printVectorData(BZRC* connection)
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 800;
    const int GRANULARITY = 25;
    char buff[100];
    string* vectorData = new string();
    PotentialFieldCalculator calculator(connection);
    TankVector* tempVector;
    
    for(int i = -SCREEN_WIDTH/2; i < SCREEN_WIDTH/2; i+= GRANULARITY)
    {        for(int j = -SCREEN_HEIGHT/2; j < SCREEN_HEIGHT/2; j+= GRANULARITY)
        {
            tempVector = calculator.calculateVector(i, j, BLUE, 0);
            
            sprintf(buff, "set arrow from %d, %d to %f, %f lt 3\n", 
                    i, 
                    j, 
                    i + tempVector->getXVector(),
                    j + tempVector->getYVector());
            (*vectorData) += buff;
            
            delete tempVector;
        }
    }
    
    return vectorData;
}

string PotentialFieldPrinter::printFooter()
{
    string footerString;
    
    footerString += "plot 20\n";  // needed so it will render
    footerString += "exit";
    
    return footerString;
}

PotentialFieldPrinter::~PotentialFieldPrinter()
{
}

