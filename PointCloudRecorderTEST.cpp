// Yunus Aktaş
#include "PointCloudRecorder.cpp"

#include <iostream>


int main()
{
    // Create a PointCloudRecorder object with the file "recorder.txt"
    PointCloudRecorder recorder("recorder.txt");

    // Create a PointCloud object manually
    PointCloud cloud;
    cloud.addPoint(1, 2, 3);
    cloud.addPoint(4, 5, 6);

    // Save the PointCloud object to the file "recorder.txt"
    if (recorder.save(cloud)) {
        std::cout << "PointCloud saved to file successfully" << std::endl;
    } else {
        std::cout << "Error saving PointCloud to file" << std::endl;
    }

    return 0;
}