/* 
 * File:   GridFilter.h
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:22 PM
 */

#ifndef GRIDFILTER_H
#define	GRIDFILTER_H

typedef struct settleGrid_t {
	double** grid;
	int width, height;
} settleGrid_t;


class GridFilter {
    settleGrid_t* settledGrid;
    int nodesSettled;
public:
    GridFilter(int x, int y);
    void addInput(bool* occgrid, int xpos, int ypos, int xSize, int ySize);
    bool isSettled();
    settleGrid_t* getGrid();
};


#endif	/* GRIDFILTER_H */

