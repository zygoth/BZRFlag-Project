/* 
 * File:   UniformCostArraySearcher.h
 * Author: zygoth
 *
 * Created on May 13, 2013, 4:23 PM
 */

#ifndef UNIFORMCOSTARRAYSEARCHER_H
#define	UNIFORMCOSTARRAYSEARCHER_H

#include "470bot.h"
#include <queue>
#include "Point.h"
#include "GNUPrinter.h"
#include "GridFilter.h"

typedef struct node_uc {
	node_uc* parent;
        double cost;
        double pathCost;
        bool nextTo;
        int x, y, childrenNum;
        node_uc* children[8];
} node_uc;

struct uc_compare {
    bool operator() (const node_uc* a, const node_uc* b) const {
        return a->cost > b->cost;
    }
};

class UniformCostArraySearcher
{
public:

    // commands used for the final
    UniformCostArraySearcher(bool* world, int cols, int rows);
    bool search(Point startPosition, Point targetPosition,
                Point* nextTarget, int distance);
    
    
    UniformCostArraySearcher();
    UniformCostArraySearcher(const UniformCostArraySearcher& orig);
    virtual ~UniformCostArraySearcher();
    bool search(bool* occgrid, int gridWidth, int gridHeight,
                       Point startPosition, Point targetPosition,
                       vector<Point>& path, bool cost, bool penalty);
    bool search(settledGrid_t map, Point startPosition, Point targetPosition, 
                Point* nextTarget);
private:
    node_uc* newNode(double,int,int,node_uc*);
    bool isNextToObject(int,int);
    void addchildren(node_uc*);
    void addChild(node_uc*, node_uc*);
    double getPenalty(node_uc*, int, int);
    double getDistance(int, int);
    void clearNode(node_uc* node);
    
    GNUPrinter* printer;
    bool* grid;
    bool* objectGrid;
    bool aStar, penaltyMode;
    int targetX, targetY;
    int width, height, printCounter;
    node_uc* tree;
    //priority_queue <node_uc*> pathOptions;
    priority_queue <node_uc*, vector<node_uc*>, uc_compare> pathOptions;
};

#endif	/* UNIFORMCOSTARRAYSEARCHER_H */

