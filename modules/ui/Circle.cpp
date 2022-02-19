#include "Circle.h"

unsigned short int Circle::getColor()
    {
        return this->color;
    }

    unsigned short int Circle::getRadius()
    {
        return this->radius;
    }

    short int Circle::getMgTop()
    {
        return this->mgTop;
    }

    short int Circle::getMgLeft()
    {
        return this->mgLeft;
    }

    short int Circle::getMgBottom()
    {
        return this->mgBottom;
    }

    short int Circle::getMgRight()
    {
        return this->mgRight;
    }

    Layout Circle::getLayout() {
        return *this->layout;
    }

    void Circle::setColor(unsigned short int color)
    {
        this->color = color;
    }

    void Circle::setRadius(unsigned short int radius)
    {
        this->radius = radius;
    }

    void Circle::setMgTop(short int mgTop)
    {
        this->mgTop = mgTop;
    }

    void Circle::setMgLeft(short int mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void Circle::setMgBottom(short int mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void Circle::setMgRight(short int mgRight)
    {
        this->mgRight = mgRight;
    }

    void Circle::setLayout(Layout *layout) {
        this->layout = layout;
    }