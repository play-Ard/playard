#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include "Layout.h"

class Triangle
{
private:
    Point* point1;
    Point* point2;
    Point* point3;
    Layout* layout;

public:
    Point getPoint1();

    Point getPoint2();

    Point getPoint3();

    Layout getLayout();

    void setPoint1(Point* point);

    void setPoint2(Point* point);

    void setPoint3(Point* point);

    void setLayout(Layout* layout);

    void setPoints(Point* point1, Point* point2, Point* point3);
};

#endif
