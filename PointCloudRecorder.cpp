#include "PointCloudRecorder.h"
/*!
 \param fileName a string argument.
*/ 
void PointCloudRecorder::setfileName(std::string fileName){
    this->fileName=fileName;
}
/*!
 \param fileName a string argument.
*/
PointCloudRecorder::PointCloudRecorder(std::string fileName){
    this->fileName=fileName;
}

PointCloudRecorder::~PointCloudRecorder(){

}
/*!
 \return The name of the file 
*/
std::string PointCloudRecorder::getfileName() const{
    return this->fileName;
}
/*!
 \param pc a PointCloud argument.
 \return false if file cannot be opened
 \return true if file opened and pointcloud saved
*/
bool PointCloudRecorder::save( PointCloud &pc){
    
    ofstream writeFile;
    writeFile.open(this->getfileName());
    if (!writeFile.is_open()) {
        // If the file cannot be opened, return false
        return false;
    }
       writeFile << "// X Y Z" << endl;
       writeFile << pc.getPointNumber() << endl;
    
    
    for (int i = 0; i < pc.getPointNumber(); i++)
    {
        Point pa = *pc.getPoint(i);
        writeFile << pa.getPointx() << " " << pa.getPointy() << " " << pa.getPointz() << endl;
        
    }
   
    writeFile.close();
    return true;
    
}