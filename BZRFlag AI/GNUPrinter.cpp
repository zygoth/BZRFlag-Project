/* 
 * File:   GNUPrinter.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 2:44 PM
 */

#include "GNUPrinter.h"
#include <fstream>
#include <sstream>

GNUPrinter::GNUPrinter()
{
    
}

void GNUPrinter::insertLine(double x1, double y1, double x2, double y2, bool withArrow)
{
    char buffer[100];
    string arrowheadString = (withArrow ? "" : "nohead ");
    
    sprintf(buffer, "set arrow from %f, %f to %f, %f ", x1, y1, x2, y2);
    sprintf(buffer + strlen(buffer), arrowheadString.c_str());
    sprintf(buffer + strlen(buffer), "lt 3\n");
    
    content += buffer;
}

void GNUPrinter::insertSquare(double x, double y)
{
    Point newSquare(x, y);
    
    squares.push_back(newSquare);
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
       myfile << printSquares();
       myfile << printFooter();
       myfile.close();
       
       cout << "GNU Output sent to file." << endl;
}

string GNUPrinter::printHeader()
{
    string headerString;
    
    headerString = "set title \"My Title\"\nset xrange [-400.0: 400.0]\n";
    headerString += "set yrange [-400.0: 400.0]\nunset key\nset size square\n";
    
    return headerString;
}

string GNUPrinter::printSquares()
{
    string squaresString;
    const string color = "black";
    
    squaresString += "plot -400\n"; // this line is probably unnecessary
    squaresString += "set style line 1 lc rgb \'";
    squaresString += color;
    squaresString += "\' pt 5   # square\n";
    squaresString += "plot \'-\' w p ls 1\n";
    
    for(int i = 0; i < squares.size(); i++)
    {
        stringstream ss;
        ss << squares[i].x << " " << squares[i].y;
        squaresString += ss.str();
        squaresString += "\n";
    }
    
    squaresString += "e\n";
    
    return squaresString;
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

