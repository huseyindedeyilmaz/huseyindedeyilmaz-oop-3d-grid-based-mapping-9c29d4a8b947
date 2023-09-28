#include "Transform.h"
#include <math.h>
/*!
 \param trans a double array containing trans values.
 \param rotationmatrix a double array containing rotationmatrix values.
*/ 
Transform::Transform(double trans[3], double rotationmatrix[3][3]){
    this->trans[0]=trans[0];
    this->trans[1]=trans[1];
    this->trans[2]=trans[2];
    rotationMatrix[0][0] = rotationmatrix[0][0];
	rotationMatrix[0][1] = rotationmatrix[0][1];
	rotationMatrix[0][2] = rotationmatrix[0][2];
	rotationMatrix[1][0] = rotationmatrix[1][0];
    rotationMatrix[1][1] = rotationmatrix[1][1];
	rotationMatrix[1][2] = rotationmatrix[1][2];
	rotationMatrix[2][0] = rotationmatrix[2][0];
	rotationMatrix[2][1] = rotationmatrix[2][1];
	rotationMatrix[2][2] = rotationmatrix[2][2];
}
/*!
 \return The angels array
*/ 
double *Transform::getangels(){
    return this->angles;
}
/*!
 \return The trans array
*/ 
double *Transform::gettrans(){
    return this->trans;
}
/*!
 \param trans a double array containing trans values.
*/
void Transform::settrans(double *trans){
    this->trans[0]=trans[0];
    this->trans[1]=trans[1];
    this->trans[2]=trans[2];

}
/*!
 \param angels a double array containing angels values.
*/
void Transform::setangels(double *angels){
    this->angles[0]=angels[0];
    this->angles[1]=angels[1];
    this->angles[2]=angels[2];

}
/*!
 \param angels a double array containing angels values.
 \param trans a double array containing trans values.
*/
Transform::Transform(double angels[3],double trans[3]){
    this->angles[0]=angels[0];
    this->angles[1]=angels[1];
    this->angles[2]=angels[2];
    this->trans[0]=trans[0];
    this->trans[1]=trans[1];
    this->trans[2]=trans[2];
}

Transform::~Transform(){
}
/*!
 \param ang a double array containing angels values.
*/ 
void Transform::setRotation(double ang[3]){
    //ang[0]=gama ang[1]=beta ang[2]=alfa//

    rotationMatrix[0][0] = cos(ang[2]) * cos(ang[1]);
	rotationMatrix[0][1] = (cos(ang[2]) * sin(ang[1]) * sin(ang[0])) - (sin(ang[2]) * cos(ang[0]));
	rotationMatrix[0][2] = (cos(ang[2]) * sin(ang[1])) * cos(ang[0]) + (sin(ang[2]) * sin(ang[0]));
	rotationMatrix[1][0] = sin(ang[2]) * cos(ang[1]);
	rotationMatrix[1][1] = (sin(ang[2]) * sin(ang[1]) * sin(ang[0])) + (cos(ang[2]) * cos(ang[0]));
	rotationMatrix[1][2] = (sin(ang[2]) * sin(ang[1]) * cos(ang[0])) - (cos(ang[2]) * sin(ang[0]));
	rotationMatrix[2][0] = -sin(ang[1]);
	rotationMatrix[2][1] = cos(ang[1]) * sin(ang[0]);
	rotationMatrix[2][2] = cos(ang[1]) * cos(ang[0]);


}
/*!
 \param rotationmatrix a double array containing rotationmatrix values.
*/ 
void Transform::setRotation(double rotationmatrix[3][3]){

    rotationMatrix[0][0] = rotationmatrix[0][0];
	rotationMatrix[0][1] = rotationmatrix[0][1];
	rotationMatrix[0][2] = rotationmatrix[0][2];
	rotationMatrix[1][0] = rotationmatrix[1][0];
    rotationMatrix[1][1] = rotationmatrix[1][1];
	rotationMatrix[1][2] = rotationmatrix[1][2];
	rotationMatrix[2][0] = rotationmatrix[2][0];
	rotationMatrix[2][1] = rotationmatrix[2][1];
	rotationMatrix[2][2] = rotationmatrix[2][2];
}
/*!
 \param tr a double array containing trans values.
*/
void Transform::setTranslation(double tr[3]){
    transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transMatrix[i][j]=this->rotationMatrix[i][j];
        }
        
    }
    
    transMatrix[0][3]=tr[0];
    transMatrix[1][3]=tr[1];
    transMatrix[2][3]=tr[2];
    transMatrix[3][3] = 1; 
}
/*!
 \param point a point object.
 \return the transformed point
*/
Point Transform::doTransform(Point p){
    
    double realp[4];
    realp[0]=p.getPointx();
    realp[1]=p.getPointy();
    realp[2]=p.getPointz();
    realp[3]=1;
    
    double tempp[4];
 tempp[0]=0;
tempp[1]=0;
tempp[2]=0;
tempp[3]=0;
    for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			tempp[i] += transMatrix[i][j] * realp[j];
    }}
    Point temp(tempp[0],tempp[1],tempp[2]);
    return temp;
}
/*!
 \param pc a pointcloud object.
 \return the transformed pointcloud
*/
PointCloud Transform::doTransform(PointCloud pc){

    PointCloud temp1(pc.getPointNumber(),0);  
    
   for (int i = 0; i < temp1.getPointNumber(); i++)
   {
    Point p(pc.getPoint(i)->getPointx(),pc.getPoint(i)->getPointy(),pc.getPoint(i)->getPointz());
    p=this->doTransform(p);
    temp1.addPoint(p.getPointx(),p.getPointy(),p.getPointz());

   }
   
    return temp1;
}