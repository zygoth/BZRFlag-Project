/* 
 * File:   Node.h
 * Author: zygoth
 *
 * Created on May 14, 2013, 4:20 PM
 */

#ifndef NODE_H
#define	NODE_H

#include "Point.h"
using namespace std;

class Node
{
public:
    Node(Point position, Node* previousNode);
    int Compare(const Node& other);
    virtual ~Node();
    
    Point position;
    Node* previousNode;
    
private:

};

struct Equal_Node 
{
     // equality function object class for Node

     bool operator() (const Node* node1, const Node* node2) const 
     { 
         if(node1->position.x == node2->position.x && node1->position.y == node2->position.y)
         {
             return true;
         }
         
         return false;
     }
};

struct Hash_Node
{
    // hash function object class for Node

    int operator() (const Node * t) const
    {
        return (13 * t->position.x + 71213 * t->position.y);
    }
};



#endif	/* NODE_H */

