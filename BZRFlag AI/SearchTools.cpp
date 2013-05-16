/* 
 * File:   SearchTools.cpp
 * Author: zygoth
 * 
 * Created on May 15, 2013, 2:26 PM
 */

#include "SearchTools.h"
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

SearchTools::~SearchTools()
{
}
