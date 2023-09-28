#include "DepthCamera.h"
/*!
 \return the name of the file
*/ 
std::string DepthCamera::getfileName() const{
    return this->fileName;
}
/*!
 \param fileName a string argument.
*/ 
void DepthCamera::setfileName(string fileName){
    this->fileName=fileName;
}
/*!
 \param fileName a string argument.
*/ 
DepthCamera::DepthCamera(string fileName){
    this->fileName=fileName;
}

DepthCamera::~DepthCamera(){

}
/*!
 \return the pointcloud object scanned from file
*/ 
PointCloud DepthCamera::capture(){
    ifstream inputfile;
    inputfile.open(this->getfileName());
    string comment;
    int capasity,r,g,b;  
    double x_,y_,z_;  
    if (!inputfile.is_open()){                 
        cout<<"Error while creating the file";    
    }
    else{
        getline(inputfile,comment);
        inputfile>>capasity;
        PointCloud temp(capasity,0);
        for (int i = 0; i < capasity; i++)
        {
            inputfile>>x_>>y_>>z_>>r>>g>>b;
            temp.addPoint(x_,y_,z_);
        }
        inputfile.close(); 
        return temp;           
    }
}