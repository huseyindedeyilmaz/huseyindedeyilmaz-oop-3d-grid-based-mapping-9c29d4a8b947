#include "ThreeDGridMap.h"
#include <fstream>

/*!
 \param size The size of each cell in the grid map.
 \param dep The depth of the grid map (i.e. the number of cells in each dimension).
 \param ref The reference point for the grid map.
*/
ThreeDGridMap::ThreeDGridMap(float size, int dep, Point& ref) : PointCloud() {
    // Initialize the 3D grid map with the given parameters
    gridSize = size;
    depth = dep;
    referencePoint = ref;

    // Dynamically create the map array
    map = new bool**[depth];
    // For each element of the map array
    for (int i = 0; i < depth; i++) {
        // For each element of the map[i] array
        map[i] = new bool*[depth];
        for (int j = 0; j < depth; j++) {
            // For each element of the map[i][j] array
            map[i][j] = new bool[depth];
            // Set all elements of the map[i][j] array to false
            std::fill(map[i][j], map[i][j] + depth, false);
        }
    }
}



ThreeDGridMap::~ThreeDGridMap() {
    // For each element of the map array
    for (int i = 0; i < depth; i++) {
        // For each element of the map[i] array
        for (int j = 0; j < depth; j++) {
            // Free the dynamically allocated memory for the map[i][j] array
            delete[] map[i][j];
        }
        // Free the dynamically allocated memory for the map[i] array
        delete[] map[i];
    }
    // Free the dynamically allocated memory for the map array
    delete[] map;
}

/*!
 \param cloud The point cloud to be inserted. It is a point cloud derived from the PointCloud class.
*/
void ThreeDGridMap::insertPointCloud(PointCloud& cloud) {
    // Iterate through all the points in the point cloud derived from the PointCloud class
    for (int i = 0; i < cloud.getPointNumber(); i++) {
        // Insert each point into the map array
        insertPoint(*cloud.getPoint(i));
    }
}


/*!
 \param point The point to be inserted. It is an object of the Point class.
*/
void ThreeDGridMap::insertPoint(Point& point) {
    // Calculate the relative position of the point to the reference point
    float x = (float)(point.getPointx() - referencePoint.getPointx());
    float y = (float)(point.getPointy() - referencePoint.getPointy());
    float z = (float)(point.getPointz() - referencePoint.getPointz());
    
    // Check if the point's x, y, and z values are within the bounds of the map
    if (x >= 0 && x < depth && y >= 0 && y < depth && z >= 0 && z < depth)
        // If the point is within the bounds, set the value of the corresponding cube in the map to true
        map[(int)(x / gridSize)][(int)(y / gridSize)][(int)(z / gridSize)] = true;
    else 
        // If the point is outside the bounds, ignore it and print a warning message
        std::cout << "Warning: Ignoring point with out-of-bounds coordinates: (" << x << ", " << y << ", " << z << ")" << std::endl;
}

/*!
 \param x The x coordinate of the cube.
 \param y The y coordinate of the cube.
 \param z The z coordinate of the cube.
 \return The value of the specified cube.
*/
bool ThreeDGridMap::getGrid(int x, int y, int z) const {
    // Return the value of the requested cube
    return map[x][y][z];
}

/*!
 \param filename The name of the file to be loaded.
 \return True if the map is successfully loaded, false otherwise.
*/
bool ThreeDGridMap::loadMap(string filename) {
    // Open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        // If the file cannot be opened, return false
        return false;
    }

    // Read the information from the file
    file >> gridSize;
    file >> depth;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                file >> map[i][j][k];
            }
        }
    }

    // Close the file and return true
    file.close();
    return true;
}

/*!
 \param filename The name of the file to be saved.
 \return True if the map is successfully saved, false otherwise.
*/
bool ThreeDGridMap::saveMap(string filename) {
    // Open the file
    std::ofstream file(filename);
    if (!file.is_open()) {
        // If the file cannot be opened, return false
        return false;
    }

    // Write the information to the file
    file << gridSize << std::endl;
    file << depth << std::endl;
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < depth; j++) {
            for (int k = 0; k < depth; k++) {
                file << map[i][j][k] << " ";
            }
            file << std::endl;
        }
        file << std::endl;
    }

    // Close the file and return true
    file.close();
    return true;
}
