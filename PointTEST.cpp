// Hüseyin Dede Yılmaz
#include <fstream>
#include <iostream>
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

    // Skip the first line
    std::string line;
    std::getline(file, line);

    // Read the number of points
    int numPoints;
    file >> numPoints;

    // Read the points
    Point points[numPoints];
    for (int i = 0; i < numPoints; i++)
    {
        double x, y, z, r, g, b;
        file >> x >> y >> z >> r >> g >> b;

        // Set the point's coordinates
        points[i].setPoint(x, y, z);
    }

    // Close the file
    file.close();

    // Print the points
    for (int i = 0; i < numPoints; i++)
    {
        std::cout << "Point " << i << ": (" << points[i].getPointx() << ", "
            << points[i].getPointy() << ", " << points[i].getPointz() << ")" << std::endl;
    }

    return 0;
}