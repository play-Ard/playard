#include "Circle.h"

int16_t Circle::getColor()
{
    return Circle::color;
}

uint16_t Circle::getRadius()
{
    return Circle::radius;
}

uint16_t Circle::getMgTop()
{
    return Circle::mgTop;
}

uint16_t Circle::getMgLeft()
{
    return Circle::mgLeft;
}

uint16_t Circle::getMgBottom()
{
    return Circle::mgBottom;
}

uint16_t Circle::getMgRight()
{
    return Circle::mgRight;
}

Layout Circle::getLayout()
{
    return *Circle::layout;
}

void Circle::setColor(uint16_t color)
{
    Circle::color = color;
}

void Circle::setRadius(uint16_t radius)
{
    Circle::radius = radius;
}

void Circle::setMgTop(uint16_t mgTop)
{
    Circle::mgTop = mgTop;
}

void Circle::setMgLeft(uint16_t mgLeft)
{
    Circle::mgLeft = mgLeft;
}

void Circle::setMgBottom(uint16_t mgBottom)
{
    Circle::mgBottom = mgBottom;
}

void Circle::setMgRight(uint16_t mgRight)
{
    Circle::mgRight = mgRight;
}

void Circle::setLayout(Layout *layout)
{
    Circle::layout = layout;
}