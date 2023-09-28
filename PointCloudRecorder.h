#include "PointCloud.h"
#include "Point.h"
#include<fstream>
/**
* @file   PointCloudRecorder.h
* @Author Yunus Aktaş
* @date   December, 2022
* @brief  Saves PointCloud object's points's cordinates
*/
#ifndef PointCloudRecorder_H
#define PointCloudRecorder_H
//! PointCloudRecorder class
/*!
   It is used to save pointcloud's points's cordinates to file.
*/
class PointCloudRecorder : public PointCloud
{
private:
    string fileName;
public:
    //! A function. Sets the name of file. 
    void setfileName(string);
    //! A constructor. Sets the name of file. 
    PointCloudRecorder(string fileName );
    //! A destructor. 
    ~PointCloudRecorder();
    //! A function. Returns the name of file. 
    string getfileName() const;
    //! A function. Saves PointCloud object's points's cordinates. 
    bool save(PointCloud&);
};


#endif // !PointCloudRecorder_H