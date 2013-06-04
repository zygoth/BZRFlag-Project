/* 
 * File:   SearchTools.cpp
 * Author: zygoth
 * 
 * Created on May 15, 2013, 2:26 PM
 */

#include "SearchTools.h"
#include "GNUPrinter.h"
#include <stack>

SearchTools::SearchTools()
{
}

flag_t SearchTools::getFlagOfColor(BZRC* connection, string color)
{
    vector<flag_t> flags;
    connection->get_flags(&flags);
    
    for(int i = 0; i < flags.size(); i++)
    {
        if(flags[i].color.compare(color) == 0)
        {
            return flags[i];
        }
    }
    
    throw "You passed in a nonexistent color to getFlagOfColor()\n";
}

bool SearchTools::isValidPoint(int matrixWidth, int matrixHeight, Point testedPoint)
{
    int pointX = testedPoint.x;
    int pointY = testedPoint.y;
    
    if(pointX < 0 || pointY < 0 || pointX >= matrixWidth || pointY >= matrixHeight)
    {
        return false;
    }
    
    return true;
}

void SearchTools::extractPathFromLastNode(Node* endNode, vector<Point>& path)
{
    stack<Node*> nodeStack;
    Node* currentNode = endNode;
    
    while(true)
    {
        if(currentNode == NULL)
        {
            break;
        }
        
        nodeStack.push(currentNode);
        currentNode = currentNode->previousNode;
    }
    
    while(!nodeStack.empty())
    {
        path.push_back(nodeStack.top()->position);
        nodeStack.pop();
    }
}

void SearchTools::addTankDataToOCCMatrix(grid_t* occGrid, BZRC* connection)
{
    const int TANK_SIZE = 7;
    bool* grid = occGrid->grid;
    vector<otank_t> otherTanks;
    
    connection->get_othertanks(&otherTanks);
    
    for(int tank = 0; tank < otherTanks.size(); tank++)
    {
        int tankX = otherTanks.at(tank).pos[0] - occGrid->x;
        int tankY = otherTanks.at(tank).pos[1] - occGrid->y;
        
        for(int i = (tankX - TANK_SIZE/2); i < (tankX + TANK_SIZE/2); i++)
        {
            for(int j = (tankY - TANK_SIZE/2); j < (tankY + TANK_SIZE/2); j++)
            {
                Point currentPosition(i, j);
                if(SearchTools::isValidPoint(occGrid->xdim, occGrid->ydim, currentPosition))
                {
                    *(grid + i + j * occGrid->xdim) = true;
                }
            }
        }
    }
}

void SearchTools::printPath(vector<Point>* path, string fileName)
{
    GNUPrinter printer;
    
    for (int i = 1; i < path->size(); i++)
    {
        printer.insertLine((*path)[i - 1].x, (*path)[i - 1].y,
                (*path)[i].x, (*path)[i].y, true);
    }
    printer.outputToFile(fileName);
}

double SearchTools::distance(Point p1, Point p2)
{
    return pow((pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)), 0.5);
}

double SearchTools::distance(int x1, int y1, int x2, int y2)
{
    return pow((pow(x1 - x2, 2) + pow(y1 - y2, 2)), 0.5);
}

SearchTools::~SearchTools()
{
}

