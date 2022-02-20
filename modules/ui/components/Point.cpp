#include "Point.h"

Point::Point(uint16_t X, uint16_t Y) {
    Point::X = X;
    Point::Y = Y;
}

uint16_t Point::getX() {
    return Point::X;
}

uint16_t Point::getY() {
    return Point::Y;
}

void Point::setX(uint16_t X) {
    Point::X = X;
}

void Point::setY(uint16_t Y) {
    Point::Y = Y;
}