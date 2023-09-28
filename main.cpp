#include "Point.h"
#include "Point.cpp"
#include "PointCloud.cpp"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "PointCloudRecorder.cpp"
#include "Transform.h"
#include "Transform.cpp"
#include "DepthCamera.h"
#include "DepthCamera.cpp"
#include "ThreeDGridMap.cpp"
#include "ThreeDGridMap.h"
//temel main dosyasıdır cam,cam1,cam2,cam3 text dosyalarına transform uygulayıp outputresult(birleştirilmiş),outputcam,outputcam1,outputcam2,outputcam3 text dosyaları oluşturur//

int main(int argc, char const *argv[])
{
    DepthCamera recordercam("cam.txt");
    DepthCamera recordercam1("cam1.txt");
    DepthCamera recordercam2("cam2.txt");
    DepthCamera recordercam3("cam3.txt");
    PointCloud cam(recordercam.capture());
    PointCloud cam1(recordercam1.capture());
    PointCloud cam2(recordercam2.capture());
    PointCloud cam3(recordercam3.capture());

    double transmcam[3],transmcam1[3],transmcam2[3],transmcam3[3],rotationcam[3][3],rotationcam1[3][3],rotationcam2[3][3],rotationcam3[3][3];
    transmcam[0]=1.95704;
    transmcam[1]=1.93000;
    transmcam[2]=1.05707;

    transmcam1[0]= -1.91288;
    transmcam1[1]=1.94412;
    transmcam1[2]=1.05465;

    transmcam2[0]=1.96978;
    transmcam2[1]= -1.94622;
    transmcam2[2]=1.05264;

    transmcam3[0]= -1.87445;
    transmcam3[1]= -1.95027;
    transmcam3[2]= 1.06432;

    rotationcam[0][0]= -0.7076050;
    rotationcam[1][0]= 0.7066082;
    rotationcam[2][0]= 0.0000008;
    rotationcam[0][1]= 0.0065031;
    rotationcam[1][1]= 0.0065134;
    rotationcam[2][1]= -0.9999576;
    rotationcam[0][2]= -0.7065783;
    rotationcam[1][2]= -0.7075750;
    rotationcam[2][2]= -0.0092041;

    rotationcam1[0][0]= -0.6638364;
    rotationcam1[1][0]= -0.7478778;
    rotationcam1[2][0]= -0.0000002;
    rotationcam1[0][1]= -0.0068830;
    rotationcam1[1][1]= 0.0061099;
    rotationcam1[2][1]= -0.9999576;
    rotationcam1[0][2]= 0.7478462;
    rotationcam1[1][2]= -0.6638082;
    rotationcam1[2][2]= -0.0092036;

    rotationcam2[0][0]= 0.8762180;
    rotationcam2[1][0]= 0.4819149;
    rotationcam2[2][0]= 0.0000001;
    rotationcam2[0][1]= 0.0044351;
    rotationcam2[1][1]= -0.0080638;
    rotationcam2[2][1]= -0.9999577;
    rotationcam2[0][2]= -0.4818945;
    rotationcam2[1][2]= 0.8761809;
    rotationcam2[2][2]= -0.0092030;

    rotationcam3[0][0]= 0.3597052;
    rotationcam3[1][0]= -0.9330660;
    rotationcam3[2][0]= 0.0000003;
    rotationcam3[0][1]= -0.0085871;
    rotationcam3[1][1]= -0.0033108;
    rotationcam3[2][1]= -0.9999576;
    rotationcam3[0][2]= 0.9330265;
    rotationcam3[1][2]= 0.3596900;
    rotationcam3[2][2]= -0.0092033;


    Transform transcam(transmcam,rotationcam);
    Transform transcam1(transmcam1,rotationcam1);
    Transform transcam2(transmcam2,rotationcam2);
    Transform transcam3(transmcam3,rotationcam3);
    
    transcam.setTranslation(transmcam);
    transcam1.setTranslation(transmcam1);
    transcam2.setTranslation(transmcam2);
    transcam3.setTranslation(transmcam3);

    PointCloud camtrans=transcam.doTransform(cam);
    PointCloud camtrans1=(transcam1.doTransform(cam1));
    PointCloud camtrans2=(transcam2.doTransform(cam2));
    PointCloud camtrans3=(transcam3.doTransform(cam3));

    PointCloud result(camtrans.getPointNumber()+camtrans1.getPointNumber()+camtrans2.getPointNumber()+camtrans3.getPointNumber(),0);
    result=camtrans1+camtrans+camtrans2+camtrans3;
    

    

    PointCloudRecorder recordcam("Outputcam.txt");
    recordcam.save(camtrans);
    PointCloudRecorder recordcam1("Outputcam1.txt");
    recordcam1.save(camtrans1);
    PointCloudRecorder recordcam2("Outputcam2.txt");
    recordcam2.save(camtrans2);
    PointCloudRecorder recordcam3("Outputcam3.txt");
    recordcam3.save(camtrans3);
    PointCloudRecorder recordresult("Outputresult.txt");
    recordresult.save(result);

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
