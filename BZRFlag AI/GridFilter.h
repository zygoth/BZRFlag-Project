/* 
 * File:   GridFilter.h
 * Author: cj1of4
 *
 * Created on May 22, 2013, 3:22 PM
 */

#ifndef GRIDFILTER_H
#define	GRIDFILTER_H

class GridFilter {
    double** settledGrid;
    int nodesSettled;
    int width, height;
public:
    GridFilter(int x, int y);
    void addInput(bool* occgrid, int xpos, int ypos, int xSize, int ySize);
    bool isSettled();
    int getWidth();
    int getHeight();
};


#endif	/* GRIDFILTER_H */

