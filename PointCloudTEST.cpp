// Hüseyin Dede Yılmaz
#include <fstream>
#include <iostream>
#include "PointCloud.cpp"
#include "Point.cpp"

int main()
{
    // Open the file
    std::ifstream file("cam.txt");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    // Read the number of points
    int numPoints;
    file >> numPoints;

    // Skip the first line
    std::string line;
    std::getline(file, line);

    // Create a PointCloud object
    PointCloud cloud;

    // Read the points from the file and add them to the PointCloud object
    for (int i = 0; i < numPoints; i++)
    {
        double x, y, z, r, g, b;
        file >> x >> y >> z >> r >> g >> b;
        cloud.addPoint(x, y, z);
    }

    // Close the file
    file.close();

    // Print the number of points in the PointCloud object
    std::cout << "Number of points in PointCloud object: " << cloud.getPointNumber() << std::endl;

    // Set the number of points in the PointCloud object to 10
    bool result = cloud.setPointNumber(10);
    if (result)
    {
        std::cout << "Number of points successfully set to 10." << std::endl;
    }

    // Create a second PointCloud object and add some points to it
    PointCloud cloud2;
    cloud2.addPoint(10, 20, 30);
    cloud2.addPoint(40, 50, 60);

    // Add the two PointCloud objects together
    PointCloud sum = cloud + cloud2;

    // Print the number of points in the resulting PointCloud object
    std::cout << "Number of points in sum: " << sum.getPointNumber() << std::endl;

    // Assign the second PointCloud object to the first
    cloud = cloud2;

    // Print the number of points in the first PointCloud object
    // Print the number of points in the first PointCloud object after assignment
    std::cout << "Number of points in first PointCloud object after assignment: " << cloud.getPointNumber() << std::endl;

    return 0;
}