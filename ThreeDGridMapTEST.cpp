// Hayati Erdem Özkümüş
#include "ThreeDGridMap.cpp"

int main() {    
    // Set the parameters for the 3D grid map
    float gridSize = 0.1; // Size of each cube in the grid (in meters)
    int depth = 100; // Depth of the grid (number of cubes in each dimension)
    Point referencePoint(-3, -3, -3); // Reference point for the coordinate system (in meters)
    
    // Create the 3D grid map
    ThreeDGridMap gridMap(gridSize, depth, referencePoint);

    // Read the points from the output.txt file and insert them into the 3D grid map
    std::ifstream file("Outputresult.txt");
    std::string line;

    if (!file.is_open()) {
        // If the file cannot be opened, return false
        return false;
    }

    while (std::getline(file, line)) {
        // Parse the line
        std::stringstream ss(line);
        std::string item;
        std::getline(ss, item, ' ');
        if (item == "X") {
            // The line represents the header, skip it
            continue;
        }

        // The line represents a point, parse the values
        float x, y, z;
        ss >> x;
        ss >> y;
        ss >> z;

        // Create a point with the parsed values and insert it into the 3D grid map
        Point point(x, y, z);
        gridMap.insertPoint(point);
    }

    // Close the file and return true
    file.close();
        
    // Save the 3D grid map to the map.txt file
    if (!gridMap.saveMap("gridMap.txt")) {
        std::cerr << "Error: Could not save the 3D grid map to the map.txt file." << std::endl;
        return 1;
    }

    // Load the 3D grid map from the map.txt file
    if (!gridMap.loadMap("gridMap.txt")) {
        std::cerr << "Error: Could not load the 3D grid map from the map.txt file." << std::endl;
        return 1;
    }

    return 0;
}