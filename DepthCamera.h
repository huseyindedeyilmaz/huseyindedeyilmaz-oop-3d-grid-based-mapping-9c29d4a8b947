#include "PointCloud.h"
#include<fstream>
/**
 * @file DepthCamera.h
 * @Author Furkan Yıldız
 * @date December 2022
 * @brief Definitions of DepthCamera class
 * Reads coordinates files
 *
*/
#ifndef DepthCamera_H
#define DepthCamera_H
//! DepthCamera class
/*!Scans files containing points x, y and z coordinates.Pushes them into a pointcloud's points
*/
class DepthCamera  : public PointCloud
{
private:
    string fileName;
public:
    //! A function, returns file's name.
    string getfileName()const;
    //! A function, sets file's name.
    void setfileName(string);
    //! A constructor.
    DepthCamera(string);
    //! A destructor, no arguments.
    ~DepthCamera();
    //! A function, reads files.
    PointCloud capture();
};



#endif // !DepthCamera_H