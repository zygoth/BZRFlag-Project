/* 
 * File:   BFSArraySearcher.cpp
 * Author: zygoth
 * 
 * Created on May 13, 2013, 4:22 PM
 */

#include "BFSArraySearcher.h"
#include <queue>
#include <tr1/unordered_set>

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
    frontier.push(startNode);
    visitedNodes.insert(startNode);
    
    while(!frontier.empty())
    {
        Node* currentNode = frontier.back();
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

            if (foundIterator != visitedNodes.end())// we haven't been here before
            {
                frontier.push(newNodes[i]);
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
    }
}

void BFSArraySearcher::extractPathFromLastNode(Node* endNode, vector<Point>& path)
{
    
}

BFSArraySearcher::~BFSArraySearcher()
{
}

