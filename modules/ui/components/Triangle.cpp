#include "Triangle.h"

Point Triangle::getPoint1() {
    return *Triangle::point1;
}

Point Triangle::getPoint2() {
    return *Triangle::point2;
}

Point Triangle::getPoint3() {
    return *Triangle::point3;
}

Layout Triangle::getLayout() {
    return *Triangle::layout;
}

void Triangle::setPoint1(Point* point) {
    Triangle::point1 = point;
}

void Triangle::setPoint2(Point* point) {
    Triangle::point2 = point;
}

void Triangle::setPoint3(Point* point) {
    Triangle::point3 = point;
}

void Triangle::setLayout(Layout* layout) {
    Triangle::layout = layout;
}

void Triangle::setPoints(Point* point1, Point* point2, Point* point3) {
    Triangle::point1 = point1;
    Triangle::point2 = point2;
    Triangle::point3 = point3;
}