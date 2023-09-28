#include "PointCloud.h"
/*!
 \return PointNumber
*/
int PointCloud::getPointNumber() const {
    return points.size();
}
/*!
 \param p an constant PointCloud& argument.
 \return The result PointCloud
*/
//PointCloud toplama islemi
PointCloud PointCloud::operator+(const PointCloud& p) {

    list<Point>::iterator iter;
    PointCloud temp;
    for (iter = this->points.begin(); iter != this->points.end(); iter++) {
        temp.addPoint(iter->getPointx(),iter->getPointy(),iter->getPointz());

    }
    
    list<Point>::const_iterator iter2;
    for (iter2= p.points.begin(); iter2 != p.points.end(); iter2++) {
        int b = 1;
        list<Point>::iterator iter3;
        for (iter3 = this->points.begin(); iter3 != this->points.end(); iter3++) {
            if (iter2->getPointx() == iter3->getPointx() && iter2->getPointy() == iter3->getPointy() && iter2->getPointz() == iter3->getPointz())b = 0;
        }
        if(b) temp.addPoint(iter2->getPointx(), iter2->getPointy(), iter2->getPointz());
    }
    
    return temp;
}

/*!
 \param p an constant PointCloud& argument.
 \return The result PointCloud
*/
void PointCloud::operator=(const PointCloud& p) {
    //Points eşitleme
    this->points = p.points;

}
/*!
 \param pnumber an integer argument.
 \param pNOF an double argument.
*/
//Constructor
PointCloud::PointCloud() {
}

//Destructor
PointCloud::~PointCloud() {
    points.clear();
}
/*!
 \param p an constant PointCloud& argument.
*/
//Copy Constructor
PointCloud::PointCloud(const PointCloud& p) {
    this->points = p.points;
}
/*!
 \param x an double argument.
 \param y an double argument.
 \param z an double argument.
*/
//Point Cloud icine yeni bir point ekleme islemi
void PointCloud::addPoint(double x, double y, double z) {

    //add islemi
    Point temp(x, y, z);
    points.push_back(temp);
}

/*!
 \param i an integer argument.
 \return pointer of point[i]
*/
//PoinCloud icindeki istenen pointi return eder.
Point* PointCloud::getPoint(int i) {
    list<Point>::iterator iter;
    int a = 0;
    for (iter = points.begin(); iter != points.end(); iter++) {
        if (a == i)break;
        else a++;
    }
    
    return &*iter;
}
