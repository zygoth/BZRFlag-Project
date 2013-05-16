/* 
 * File:   DepthLimitedArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 15, 2013, 6:53 PM
 */

#include "DepthLimitedArraySearcher.h"
#include "SearchTools.h"
#include "DepthNode.h"
#include "GNUPrinter.h"
#include <queue>
#include <tr1/unordered_set>
#include <stack>

using namespace std;
using std::tr1::unordered_set;

DepthLimitedArraySearcher::DepthLimitedArraySearcher()
{
    
}

/**
 * Returns the path from the startPosition to the targetPosition.
 * Will not find the goal state if it is farther away than *depth* from the start.
 * Puts just the start point into *path* if the goal point is not found.
 * 
 * @param occgrid
 * @param gridWidth
 * @param gridHeight
 * @param startPosition
 * @param targetPosition
 * @param path
 * @param depth
 */
void DepthLimitedArraySearcher::getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
            Point startPosition, Point targetPosition,
            vector<Point>& path, int depth, GNUPrinter* outputPrinter)
{
    stack<DepthNode*> frontier;
    unordered_set<Node*, Hash_Node, Equal_Node> visitedNodes;    
    DepthNode* startNode = new DepthNode(startPosition, NULL, 0);
    Node* goalNode = startNode;
    //GNUPrinter outputPrinter;
    int nodeCounter = 0;
    
    frontier.push(startNode);
    visitedNodes.insert(startNode);
    outputPrinter->insertSquare(startPosition.x, startPosition.y);
    outputPrinter->insertSquare(targetPosition.x, targetPosition.y);
    
    
    while(!frontier.empty())
    {
        DepthNode* currentNode = frontier.top();
        frontier.pop();
        nodeCounter++;
        if(nodeCounter != 1)
        {
            outputPrinter->insertLine(currentNode->previousNode->position.x, 
                    currentNode->previousNode->position.y,
                    currentNode->position.x, currentNode->position.y,
                    true);
        }
        
        if(nodeCounter % 5 == 0)
        {
            outputPrinter->insertPause(.01);
        }
        
        
        if(currentNode->position.Compare(targetPosition) == 0) // check if we're done
        {
            goalNode = currentNode;
            break;
        }
        
        // If no, then add on all adjacent nodes that have not been explored already
        
        DepthNode* newNodes[8];
        
        Point p(currentNode->position.x + 1, currentNode->position.y);
        newNodes[6] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x;
        p.y = currentNode->position.y - 1;
        newNodes[4] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y;
        newNodes[7] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x;
        p.y = currentNode->position.y + 1;
        newNodes[5] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y + 1;
        newNodes[3] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x + 1;
        p.y = currentNode->position.y + 1;
        newNodes[2] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y - 1;
        newNodes[1] = new DepthNode(p, currentNode, currentNode->depth + 1);
        p.x = currentNode->position.x + 1;
        p.y = currentNode->position.y - 1;
        newNodes[0] = new DepthNode(p, currentNode, currentNode->depth + 1);

        for (int i = 0; i < 8; i++)
        {
            unordered_set<Node*>::iterator foundIterator = visitedNodes.find(newNodes[i]);
            
            if (foundIterator == visitedNodes.end() && // not visited before
                    SearchTools::isValidPoint(gridWidth, gridHeight, newNodes[i]->position) && // is inside the array
                    *( occgrid + newNodes[i]->position.x + newNodes[i]->position.y * gridWidth) == false && // is unoccupied
                    newNodes[i]->depth <= depth) // is within the depth limit
            { //A[i][j] = *(A[i]+j) = * ( *(A+i)+j)
                frontier.push(newNodes[i]);
                visitedNodes.insert(newNodes[i]);           
            }
            else
            {
                delete newNodes[i];
            }
        }
    }
    
    SearchTools::extractPathFromLastNode(goalNode, path);
    
    //Now clean up the nodes by deleting everything in visitedNodes
    
    unordered_set<Node*>::iterator it = visitedNodes.begin();
    
    while(it != visitedNodes.end())
    {        
        delete *it;
        it++;
    }
    
    //outputPrinter->outputToFile("IDOUTPUT");
}

DepthLimitedArraySearcher::~DepthLimitedArraySearcher()
{
    
}

