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
public:
    GridFilter(int width, int height);
    void addInput(bool* occgrid, int xpos, int ypos);
    bool isSettled();
};


#endif	/* GRIDFILTER_H */

