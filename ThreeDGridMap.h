#pragma once

/**
 * @file ThreeDGridMap.h
 * @author Hayati Erdem Özkümüş (ozkherdem@gmail.com)
 * @date December 24, 2022
 * @brief A class representing a 3D grid map.
 *
 *  This class stores a 3D grid map and provides methods for inserting points
 *  and point clouds into the map, as well as saving and loading the map to
 *  and from a file.
 *
 *  The 3D grid map is represented as a 3D array of booleans, where each element
 *  in the array represents the presence or absence of a point at that grid location.
 *  The map is initialized with a specified grid size and depth, and the reference
 *  point for the coordinate system is also specified.
 *
 *  The class provides methods for inserting individual points and point clouds
 *  into the map, as well as for loading and saving the map to and from a file.
 */
#include "Point.h"
#include "PointCloud.h"

#ifndef THREEDGRIDMAP_H
#define THREEDGRIDMAP_H
//! ThreeDGridMap class
/*!
	Contains definitions of PointCloud class
*/
class ThreeDGridMap : public PointCloud {
private:
    /** The 3D grid map */
    bool*** map;
    /** The size of each grid cell */
    float gridSize;
    /** The depth of the map (number of grid cells along the Z-axis) */
    int depth;
    /** The reference point for the coordinate system */
    Point referencePoint;

public:
    /**
     *  Constructor
     *
     *  @param gridSize The size of each grid cell
     *  @param depth The depth of the map (number of grid cells along the Z-axis)
     *  @param referencePoint The reference point for the coordinate system
     */
    ThreeDGridMap(float gridSize, int depth, Point& referencePoint);

    /**
     *  Destructor
     */
    ~ThreeDGridMap();

    /**
     *  Insert a point cloud into the map
     *
     *  This method iterates over the points in the point cloud and inserts
     *  each point into the map by calling the `insertPoint` method.
     *
     *  @param cloud The point cloud to insert
     */
    void insertPointCloud(PointCloud& cloud);

    /**
     *  Insert a single point into the map
     *
     *  This method determines the grid location of the point based on its
     *  coordinates and the size of the grid cells, and then sets the
     *  corresponding element in the map to `true`.
     *
     *  @param point The point to insert
     */
    void insertPoint(Point& point);

    /**
     *  Get the value of a grid cell
     *
     *  This method returns the value of the specified grid cell in the map.
     *
     *  @param x The X-coordinate of the grid cell
     *  @param y The Y-coordinate of the grid cell
     *  @param z The Z-coordinate of the grid cell
     *  @return The value of the grid cell (`true` if a point is present, `false` otherwise)
     */
    bool getGrid(int x, int y, int z) const;
    /**
     *  Load the map from a file
     *
     *  This method loads the map from a file with the specified filename.
     *  The file should contain the map data in a format that can be parsed
     *  by the method.
     *
     *  @param filename The name of the file to load the map from
     *  @return `true` if the map was successfully loaded, `false` otherwise
     */
    bool loadMap(string filename);

    /**
     *  Save the map to a file
     *
     *  This method saves the map to a file with the specified filename.
     *  The map data is saved in a format that can be parsed by the
     *  `loadMap` method.
     *
     *  @param filename The name of the file to save the map to
     *  @return `true` if the map was successfully saved, `false` otherwise
     */
    bool saveMap(string filename);
};

#endif //THREEDGRIDMAP_H