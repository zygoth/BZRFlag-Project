/* 
 * File:   SearchTools.h
 * Author: zygoth
 *
 * Created on May 15, 2013, 2:26 PM
 */

#ifndef SEARCHTOOLS_H
#define	SEARCHTOOLS_H

#include "470bot.h"
#include "Point.h"
#include "Node.h"
#include <string>

using namespace std;

class SearchTools
{
public:
    SearchTools();
    static flag_t getFlagOfColor(BZRC* connection, string color);
    static bool isValidPoint(int matrixWidth, int matrixHeight, Point testedPoint);
    static void extractPathFromLastNode(Node* endNode, vector<Point>& path);
    static void addTankDataToOCCMatrix(grid_t* occGrid, BZRC* connection);
    virtual ~SearchTools();
private:

};

#endif	/* SEARCHTOOLS_H */

