/* 
 * File:   Point.h
 * Author: zygoth
 *
 * Created on May 14, 2013, 3:16 PM
 */

#ifndef POINT_H
#define	POINT_H

class Point
{
public:
    int x;
    int y;
    
    Point();
    Point(int x, int y);
    int Compare(const Point& other);
    virtual ~Point();
};

#endif	/* POINT_H */

