#include <iostream>
#include <cmath>  // needed for sqrt

#include "point.h"

using namespace std;

Point::Point() {
  x = 0.0;
  y = 0.0;
}

Point::Point(float xVal, float yVal) {
  x = xVal;
  y = yVal;
}

Point::~Point() { }

float Point::getX() {
  return x;
}

float Point::getY() {
  return y;
}

float Point::distance(Point p2) {
  float dx, dy;
  dx = x - p2.getX();
  dy = y - p2.getY();
  return sqrt(dx*dx + dy*dy);
}

void Point::setX(float xVal) {
  x = xVal;
}

void Point::setY(float yVal) {
  y = yVal;
}

/**
 * operator< returns true if this Point is less than a second Point, p2.
 *
 * This implementation compares Points lexicographically by their x and
 * then y coordinates.  In other words, if p1.x < p2.x, then we define
 * p1 < p2, and x-coordinate ties are broken by comparing the y-coordinates.
 */
bool Point::operator<(Point p2) {
  if (x == p2.x) {
    return y < p2.y;
  }
  return x < p2.x;
}


// An alternative operator< function that returns if this point is closer
// to (0,0) than p2 is to (0,0).  Uncomment this function (and comment out
// the above operator<) to see how this sorts points.
// bool Point::operator<(Point p2) {
//   return distance(Point(0,0)) < p2.distance(Point(0,0));
// }


/* All of the other comparison operators are defined in terms of 
 * operator<.  Therefore, if you redefine operator< above, all of the
 * other comparison operators (<= > >= ==) will automatically be consistent
 * with your redefined operator<.
 */

bool Point::operator>(Point p2) {
  return (p2 < *this);
}

bool Point::operator<=(Point p2) {
  return !(*this > p2);
}

bool Point::operator>=(Point p2) {
  return !(*this < p2);
}

bool Point::operator==(Point p2) {
  return !(*this < p2) && !(*this > p2);
}

bool Point::operator!=(Point p2) {
  return (*this < p2) || (*this > p2);
}


/**
 * operator<< allows a Point to be printed by an output stream, such as
 * cout.  The & syntax here is not the same as the address-of operator.
 * Here the & causes the ostream to be passed by reference instead of 
 * by value, so that printing the Point can directly affect an existing
 * output stream, not just a copy of the output stream.
 */
ostream& operator<<(ostream& out, Point p) {
  out << "(" << p.getX() << ", " << p.getY() << ")";
  return out;
}

