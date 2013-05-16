/* 
 * File:   DepthNode.cpp
 * Author: zygoth
 * 
 * Created on May 15, 2013, 6:42 PM
 */

#include "DepthNode.h"

DepthNode::DepthNode(Point position, Node* previousNode, int depth) : Node(position, previousNode)
{
    this->depth = depth;
}

DepthNode::~DepthNode()
{
}

