/**
 * @file Transform.h
 * @Author Furkan Çetin
 * @date December, 2022
 * @brief Transform class applies algebric and geometric processes on the pointcloud object.
 * It has rotation matrix (3x3), transformation matrix (4x4), trans matrix (3x1), angles matrix (3x1)
 * Rotation matrix, angles and transform values combine and create transformation matrix and transforms the object
 */
#include "PointCloud.h"
#include "Point.h"

#ifndef Transform_H
#define Transform_H
//! Transform class
 /*! It has two transformer functions.This functions applies transformation on given the argument and returns with the same type argument.
 */
class Transform  : public PointCloud
{
private:
    double angles[3];
    double trans[3];
    double transMatrix[4][4];
    double rotationMatrix[3][3];
public:
    //! A constructor,takes trans array and angles array as parameters
    Transform(double[],double[]);
    //! A constructor,takes trans array and rotationmatrix array as parameters
    Transform(double[],double[][3]);
    //! A destructor, no parameters
    ~Transform();
    //! A function, returns angels array 
    double *getangels();
    //! A function, returns trans array 
    double *gettrans();
    //! A function, takes translation values as parameters
	/*! Creates trans matrix
	 */
    void settrans(double*);
    //! A function, takes angels values as parameters
	/*! Creates angels matrix
	 */
    void setangels(double*);
    //! A function, takes angels values as parameters
	/*! Creates rotation matrix
	 */
    void setRotation(double[]);
    //! A function, takes rotationmatrix values as parameters
	/*! Creates rotation matrix
	 */
    void setRotation(double[][3]);
    //! A function, takes translation values as parameters
	/*! Creates translation matrix
	 */
    void setTranslation(double[]);
    //! A function, takes point object as parameters
	/*! Applies transformation to the point
	 */
    Point doTransform(Point);
    //! A function, takes pointcloud object as parameters
	/*! Applies transformation to the pointcloud's all points
	 */
    PointCloud doTransform(PointCloud);
};

#endif // !TRANSFORM_H