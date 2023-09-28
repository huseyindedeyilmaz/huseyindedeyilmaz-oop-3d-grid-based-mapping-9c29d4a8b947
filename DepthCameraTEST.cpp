#include <iostream>
#include <string>
#include "DepthCamera.cpp"

int main()
{
    // Test the DepthCamera class with the "cam.txt" file
    DepthCamera camera1("cam.txt");
    PointCloud cloud1 = camera1.capture();
    std::cout << "Number of points in PointCloud object (cam.txt): " << cloud1.getPointNumber() << std::endl;

    // Test the DepthCamera class with the "cam1.txt" file
    DepthCamera camera2("cam1.txt");
    PointCloud cloud2 = camera2.capture();
    std::cout << "Number of points in PointCloud object (cam1.txt): " << cloud2.getPointNumber() << std::endl;

    // Test the DepthCamera class with the "cam2.txt" file
    DepthCamera camera3("cam2.txt");
    PointCloud cloud3 = camera3.capture();
    std::cout << "Number of points in PointCloud object (cam2.txt): " << cloud3.getPointNumber() << std::endl;

    // Test the DepthCamera class with the "cam3.txt" file
    DepthCamera camera4("cam3.txt");
    PointCloud cloud4 = camera4.capture();
    std::cout << "Number of points in PointCloud object (cam3.txt): " << cloud4.getPointNumber() << std::endl;

    return 0;
}
