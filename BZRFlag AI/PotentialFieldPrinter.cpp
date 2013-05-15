/* 
 * File:   PotentialFieldPrinter.cpp
 * Author: zygoth
 * 
 * Created on May 9, 2013, 11:06 AM
 */

#include "PotentialFieldPrinter.h"
#include "PotentialFieldCalculator.h"
#include <fstream>
#include <sstream>
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
       myfile << printTanksData(connection);
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
    const int SCREEN_WIDTH = 50;
    const int SCREEN_HEIGHT = 50;
    const int BOTTOM_LEFT_CORNER_X = -400;
    const int BOTTOM_LEFT_CORNER_Y = -25;
    const int GRANULARITY = 10;
    char buff[100];
    string* vectorData = new string();
    PotentialFieldCalculator calculator(connection);
    TankVector* tempVector;
    
    for(int i = BOTTOM_LEFT_CORNER_X; i < BOTTOM_LEFT_CORNER_X + SCREEN_WIDTH; i+= GRANULARITY)
    {        
        for(int j = BOTTOM_LEFT_CORNER_Y; j < BOTTOM_LEFT_CORNER_Y + SCREEN_HEIGHT; j+= GRANULARITY)
        {
            tempVector = calculator.calculateVector(i, j, BLUE, 0);
            
            sprintf(buff, "set arrow from %d, %d to %f, %f lt 3\n", 
                    i, 
                    j, 
                    i + tempVector->getXVector(),
                    j + tempVector->getYVector());
            (*vectorData) += buff;
            
            if(j == BOTTOM_LEFT_CORNER_Y)
            {
                cout << "Percent Done: ";
                cout << ((((double)(i - BOTTOM_LEFT_CORNER_X)*SCREEN_WIDTH) / (SCREEN_WIDTH*SCREEN_HEIGHT))*100) << endl;
                cout.flush();
            }
            
            delete tempVector;
        }
    }
    
    return vectorData;
}

string PotentialFieldPrinter::printTanksData(BZRC* connection)
{
    string tankString;
    vector<tank_t> myTanks;
    connection->get_mytanks(&myTanks);
    
    tankString += "plot -400\n"; // this line is probably unnecessary
    tankString += "set style line 1 lc rgb 'black' pt 5   # square\n";
    tankString += "plot \'-\' w p ls 1\n";
    
    for(int i = 0; i < myTanks.size(); i++)
    {
        stringstream ss;
        ss << myTanks[i].pos[0] << " " << myTanks[i].pos[1];
        tankString += ss.str();
        tankString += "\n";
    }
    
    tankString += "e\n";
    
    return tankString;
}

string PotentialFieldPrinter::printFooter()
{
    string footerString;
    
    //footerString += "plot -400\n";  // needed so it will render
    footerString += "exit";
    
    return footerString;
}

PotentialFieldPrinter::~PotentialFieldPrinter()
{
}

