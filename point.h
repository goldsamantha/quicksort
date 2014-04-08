#ifndef POINT_H_ 
#define POINT_H_

#include <iostream>

class Point {
  private:
    float x, y;

  public:                                 
    Point();
    Point(float xVal, float yVal);

    virtual ~Point();

    float getX();
    float getY();
    float distance(Point p2);   // The distance between this Point and p2.

    void setX(float xVal);
    void setY(float yVal);

    bool operator<(Point p2);   // Comparison operators for Points.
    bool operator<=(Point p2);
    bool operator>(Point p2);
    bool operator>=(Point p2);
    bool operator==(Point p2);
    bool operator!=(Point p2);
};

// Output operator for a Point.  Notice that this function is not
// a member of the Point class.  The & syntax causes the ostream to be
// passed by reference instead of passed by value.
std::ostream& operator<<(std::ostream& out, Point p);

#endif
