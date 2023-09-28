#include "Point.h"
/*!
 \param x an double argument.
 \param y an double argument.
 \param z an double argument.
*/
Point::Point(double x, double y , double z) :x(x), y(y), z(z) {

}

Point::~Point() {

}
/*!
 \param x an double argument.
 \param y an double argument.
 \param z an double argument.
*/
void Point::setPoint(double x, double y, double z) {
   
   
        this->x = x;
        this->y = y;
        this->z = z;
    
}
/*!
 \param p an Point argument.
*/
void Point::operator=(Point p){
    this->x=p.x;
    this->y=p.y;
    this->z=p.z;
}
/*!
	\return x cordinate of point
*/
double Point::getPointx() const {
    return this->x;

}
/*!
	\return y cordinate of point
*/
double Point::getPointy() const {
    return this->y;

}
/*!
	\return z cordinate of point
*/
double Point::getPointz() const {
    return this->z;

}
/*!
	\param point a constant Point& argument
	\return boolean if the point's cordinates are the same
*/
bool Point::operator==(const Point& point) {
    if (this->x == point.x && this->y == point.y & this->z == point.z) return true;
    else return false;
}


/*!
	\param point a constant Point& argument
	\return calculated distance between two points
*/
double Point::distance(const Point& point) const {
    return sqrt(pow((this->x - point.x), 2) + pow((this->y - point.y), 2) + pow((this->z - point.z), 2));

}

