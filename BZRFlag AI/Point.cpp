/* 
 * File:   Point.cpp
 * Author: zygoth
 *
 * Created on May 14, 2013, 3:50 PM
 */

#include "Point.h"
#include <cstdlib>

using namespace std;

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 Comparator function
 */
int Point::Compare(const Point& other)
{
    if(x != other.x)
    {
        return x - other.x;
    }
    else
    {
        return y - other.y;
    }
}

Point::~Point()
{

}

