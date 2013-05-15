/* 
 * File:   BFSArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 4:22 PM
 */

#include "BFSArraySearcher.h"
#include "SearchTools.h"
#include "GNUPrinter.h"
#include <queue>
#include <tr1/unordered_set>
#include <stack>

using namespace std;
using std::tr1::unordered_set;


BFSArraySearcher::BFSArraySearcher()
{
}

void BFSArraySearcher::getPathToGoal(bool* occgrid, int gridWidth, int gridHeight,
                                     Point startPosition, Point targetPosition,
                                     vector<Point>& path)
{
    Node* goalNode;
    queue<Node*> frontier;
    unordered_set<Node*, Hash_Node, Equal_Node> visitedNodes;    
    Node* startNode = new Node(startPosition, NULL);
    GNUPrinter outputPrinter;
    
    frontier.push(startNode);
    visitedNodes.insert(startNode);
    outputPrinter.insertSquare(startPosition.x, startPosition.y);
    
    
    while(!frontier.empty())
    {
        Node* currentNode = frontier.front();
        frontier.pop();
        
        if(currentNode->position.Compare(targetPosition) == 0) // check if we're done
        {
            goalNode = currentNode;
            break;
        }
        
        // If no, then add on all adjacent nodes that have not been explored already
        
        Node* newNodes[4];
        
        Point p(currentNode->position.x + 1, currentNode->position.y);
        newNodes[0] = new Node(p, currentNode);
        p.x = currentNode->position.x;
        p.y = currentNode->position.y - 1;
        newNodes[1] = new Node(p, currentNode);
        p.x = currentNode->position.x - 1;
        p.y = currentNode->position.y;
        newNodes[2] = new Node(p, currentNode);
        p.x = currentNode->position.x;
        p.y = currentNode->position.y + 1;
        newNodes[3] = new Node(p, currentNode);

        for (int i = 0; i < 4; i++)
        {
            unordered_set<Node*>::iterator foundIterator = visitedNodes.find(newNodes[i]);
            
            if (foundIterator == visitedNodes.end() && 
                    SearchTools::isValidPoint(gridWidth, gridHeight, newNodes[i]->position) &&
                    *( occgrid + newNodes[i]->position.x + newNodes[i]->position.y * gridWidth) == false)
            { //A[i][j] = *(A[i]+j) = * ( *(A+i)+j)
                frontier.push(newNodes[i]);
                visitedNodes.insert(newNodes[i]);
                outputPrinter.insertLine(currentNode->position.x, currentNode->position.y,
                                         newNodes[i]->position.x, newNodes[i]->position.y,
                                         true);
            }
            else
            {
                delete newNodes[i];
            }
        }
    }
    
    extractPathFromLastNode(goalNode, path);
    
    //Now clean up the nodes by deleting everything in visitedNodes
    
    unordered_set<Node*>::iterator it = visitedNodes.begin();
    
    while(it != visitedNodes.end())
    {        
        delete *it;
        it++;
    }
    
    outputPrinter.outputToFile("BFSOUTPUT.gnu");
}

void BFSArraySearcher::extractPathFromLastNode(Node* endNode, vector<Point>& path)
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
        path.pop_back();
    }
}

BFSArraySearcher::~BFSArraySearcher()
{
}

