#include "PointCloud.h"

/*!
 \param key an integer argument.
 \return true if key set as pointnumber,else false
*/
//PointNumber d�zenleme islemi
bool PointCloud::setPointNumber(int key) {
    //negatif deger girme durumu
    if (key >= 0) {
        this->PointNumber = key;
        return true;
    }
    else
        return false;
}
/*!
 \return PointNumber
*/
int PointCloud::getPointNumber() const {
    return this->PointNumber;
}
/*!
 \param p an constant PointCloud& argument.
 \return The result PointCloud
*/
//PointCloud toplama islemi
PointCloud PointCloud::operator+(const PointCloud& p) {
    //d�nd�r�lecek nesne olusturma
    int a = NOF + p.NOF;
    PointCloud temp(a);
    
    //toplama islemleri
    for (int i = 0; i < NOF; i++)
    {
       
       temp.addPoint(points[i].getPointx(), points[i].getPointy(), points[i].getPointz());

    }
    for (int i = 0; i < p.NOF; i++)
    {
        //ayn� pointe sahip olma durumu
        int b = 1;
        for (int j = 0; j < p.NOF; j++) {
            if (p.points[j] == points[i]) {
                b = 0;

            }
        }

        if (b)temp.addPoint(p.points[i].getPointx(), p.points[i].getPointy(), p.points[i].getPointz());
    }
    
    return temp;
}

/*!
 \param p an constant PointCloud& argument.
 \return The result PointCloud
*/
void PointCloud::operator=(const PointCloud& p) {
    //PointNumber esitleme
    this->PointNumber = p.PointNumber;
    //Point array esitleme
    for (int i = 0; i < PointNumber; i++)
    {
        this->points[i].setPoint(p.points[i].getPointx(), p.points[i].getPointy(), p.points[i].getPointz());
    }
}
/*!
 \param pnumber an integer argument.
 \param pNOF an double argument.
*/
//Constructor
PointCloud::PointCloud(int pnumber,int pNOF ){
    PointNumber = pnumber;
    NOF = pNOF;
    points = new Point[PointNumber];

}

//Destructor
PointCloud::~PointCloud() {
    delete[] points;
}
/*!
 \param p an constant PointCloud& argument.
*/
//Copy Constructor
PointCloud::PointCloud(const PointCloud& p) {
    PointNumber = p.PointNumber;
    NOF = p.NOF;
    points = new Point[PointNumber];
    for (int i = 0; i < NOF; i++) {
        points[i] = p.points[i];
    }
}
/*!
 \param x an double argument.
 \param y an double argument.
 \param z an double argument.
*/
//Point Cloud icine yeni bir point ekleme islemi
void PointCloud::addPoint(double x, double y, double z) {
   //Arryin overloading olma durumu
    if (NOF == PointNumber) {
        //boyutu eski arryin iki kat� olan yeni bir array tan�mlama
        PointNumber *= 2;
        Point* p = new Point[PointNumber];
        //yeni arraya eski arryin bilgilerini atama
        for (int i = 0; i < PointNumber / 2; i++) {
            p[i] = points[i];
        }
        //yeni points p oluyor
        points = p;
    }
    //add islemi
    points[NOF].setPoint(x, y, z);
    
    NOF++;
}

/*!
 \param i an integer argument.
 \return pointer of point[i]
*/
//PoinCloud icindeki istenen pointi print eder.
Point* PointCloud::getPoint(int i) {
    Point* p = &points[i];
    return p;
}