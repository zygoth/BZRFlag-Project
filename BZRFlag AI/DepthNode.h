/* 
 * File:   DepthNode.h
 * Author: zygoth
 *
 * Created on May 15, 2013, 6:42 PM
 */

#ifndef DEPTHNODE_H
#define	DEPTHNODE_H

#include "Node.h"

class DepthNode : public Node
{
public:
    DepthNode(Point position, Node* previousNode, int depth);
    virtual ~DepthNode();
    int depth;
private:

};

#endif	/* DEPTHNODE_H */

