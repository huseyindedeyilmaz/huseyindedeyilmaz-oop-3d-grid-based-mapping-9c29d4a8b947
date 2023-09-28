#pragma once
#include "Point.h"
#include <list>
#include <iterator>
/**
 * @file PointCloud.h
 * @Author Hüseyin Dede Yılmaz
 * @date December, 2022
 * @brief Definitions of PointCloud class
*/
#ifndef PointCloud_H
#define PointCloud_H
//! PointCloud class
/*!
	Contains definitions of PointCloud class
*/
class PointCloud : public Point
{
private:
    list<Point> points;
public:
    //! A function,adds point to pointcloud
	/*! Adds the point(with giving cordinates) into pointcloud
	*/
    void addPoint(double, double, double);
    //! A function, returns pointNumber
    int getPointNumber() const;
    //! An overload + operator
	/*! Returns a single point cloud with the points that two point clouds have
	*/
    PointCloud operator+(const PointCloud&);
    //! An overload = operator
	/*! Assigns the pointcloud to the other pointcloud
	*/
    void operator=(const PointCloud&);
    //! A constructor. Takes pointnumber and number of element,default =20,=0.
    PointCloud();
    //! A copy constructor. Takes a pointcloud and copies it to another pointcloud.
    PointCloud(const PointCloud& );
    //! A destructor,Deletes points of pointcloud.
    ~PointCloud();
    //! A function, returns pointer points of pointcloud
    Point* getPoint(int);
};


#endif