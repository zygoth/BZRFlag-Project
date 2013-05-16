/* 
 * File:   DFSArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 4:22 PM
 */

#include "DFSArraySearcher.h"
#include "SearchTools.h"
#include "GNUPrinter.h"
#include <queue>
#include <tr1/unordered_set>
#include <stack>

using namespace std;
using std::tr1::unordered_set;

DFSArraySearcher::DFSArraySearcher()
{
}

void DFSArraySearcher::getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
                                     Point startPosition, Point targetPosition,
                                     vector<Point>& path)
{
    Node* goalNode;
    stack<Node*> frontier;
    unordered_set<Node*, Hash_Node, Equal_Node> visitedNodes;    
    Node* startNode = new Node(startPosition, NULL);
    GNUPrinter outputPrinter;
    int nodeCounter = 0;
    
    frontier.push(startNode);
    visitedNodes.insert(startNode);
    outputPrinter.insertSquare(startPosition.x, startPosition.y);
    outputPrinter.insertSquare(targetPosition.x, targetPosition.y);
    
    
    while(!frontier.empty())
    {
        Node* currentNode = frontier.top();
        frontier.pop();
        nodeCounter++;
        if(nodeCounter != 1)
        {
            outputPrinter.insertLine(currentNode->position.x, currentNode->position.y,
                    currentNode->previousNode->position.x, 
                    currentNode->previousNode->position.y,
                    true);
        }
        
        if(nodeCounter % 500 == 0)
        {
            outputPrinter.insertPause(.01);
        }
        
        
        if(currentNode->position.Compare(targetPosition) == 0) // check if we're done
        {
            goalNode = currentNode;
            break;
        }
        
        // If no, then add on all adjacent nodes that have not been explored already
        
        Node* newNodes[8];
        
        Point p(currentNode->position.x + 1, currentNode->position.y);
        newNodes[6] = new Node(p, currentNode);
        p.x = currentNode->position.x;
        p.y = currentNode->position.y - 1;
        newNodes[4] = new Node(p, currentNode);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y;
        newNodes[7] = new Node(p, currentNode);
        p.x = currentNode->position.x;
        p.y = currentNode->position.y + 1;
        newNodes[5] = new Node(p, currentNode);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y + 1;
        newNodes[3] = new Node(p, currentNode);
        p.x = currentNode->position.x + 1;
        p.y = currentNode->position.y + 1;
        newNodes[2] = new Node(p, currentNode);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y - 1;
        newNodes[1] = new Node(p, currentNode);
        p.x = currentNode->position.x + 1;
        p.y = currentNode->position.y - 1;
        newNodes[0] = new Node(p, currentNode);

        for (int i = 0; i < 8; i++)
        {
            unordered_set<Node*>::iterator foundIterator = visitedNodes.find(newNodes[i]);
            
            if (foundIterator == visitedNodes.end() && 
                    SearchTools::isValidPoint(gridWidth, gridHeight, newNodes[i]->position) &&
                    *( occgrid + newNodes[i]->position.x + newNodes[i]->position.y * gridWidth) == false)
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
    
    outputPrinter.outputToFile("DFSOUTPUT.gnu");
}

DFSArraySearcher::~DFSArraySearcher()
{
}

