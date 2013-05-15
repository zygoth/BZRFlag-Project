/* 
 * File:   Node.cpp
 * Author: zygoth
 * 
 * Created on May 14, 2013, 4:20 PM
 */

#include "Node.h"

Node::Node(Point position, Node* previousNode) : position(position), previousNode(previousNode)
{
    
}

int Node::Compare(const Node& other)
{
    return position.Compare(other.position);
}

Node::~Node()
{
}

