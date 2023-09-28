#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
/**
 * @file Point.h
 * @Author Hüseyin Dede Yılmaz
 * @date December 2022
 * @brief Definitions of point class
 */
using namespace std;
#ifndef Point_H
#define Point_H
//! Point class
 /*!
	 Contains definitions of point class
 */
class Point
{
private:
    double x, y, z;
public:
     //! A function, sets x,y,z cordinates.
    void setPoint(double, double, double);
    //! A function, returns x cordinates.
    double getPointx() const;
     //! A function, returns y cordinates.
    double getPointy() const;
     //! A function, returns z cordinates.
    double getPointz() const;
    //! A function, calculates distance.
	/*! Calculates the distance between two points and returns the distance.
	*/
    double distance(const Point&) const;
    //! An overload == operator
	/*! Checks if two points are same, Returns True if so, else False.
	*/
    bool operator==(const Point&);
    //! A constructor. Takes the x, y, z values of the point,default =0.
    Point(double=0, double=0, double=0);
    //! An overload = operator
	/*! Assigns the coordinates of the point to the other point
	*/
    void operator=(Point);
    //! A destructor
    ~Point();
};
#endif // !Point_H