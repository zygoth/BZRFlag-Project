/* 
 * File:   GridFilter.h
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:22 PM
 */

#ifndef GRIDFILTER_H
#define	GRIDFILTER_H

#include "470bot.h"

typedef struct settledGrid_t {
	double** grid;
	int width, height;
} settledGrid_t;


class GridFilter 
{    
public:
    
    GridFilter(int x, int y, double truePositiveProbability);
    virtual ~GridFilter();
    void addInput(grid_t occGrid);
    bool isSettled();
    settledGrid_t getGrid();
    static int cartesianToMatrixCoordinates(int value, int maximumValue);
    
private:
    
    settledGrid_t settledGrid;
    int nodesNotSettled;
    double truePositiveProbability;
};


#endif	/* GRIDFILTER_H */

