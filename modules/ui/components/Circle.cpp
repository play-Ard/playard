#include "Circle.h"

    int16_t Circle::getColor()
    {
        return this->color;
    }

    uint16_t Circle::getRadius()
    {
        return this->radius;
    }

    uint16_t Circle::getMgTop()
    {
        return this->mgTop;
    }

    uint16_t Circle::getMgLeft()
    {
        return this->mgLeft;
    }

    uint16_t Circle::getMgBottom()
    {
        return this->mgBottom;
    }

    uint16_t Circle::getMgRight()
    {
        return this->mgRight;
    }

    Layout Circle::getLayout() {
        return *this->layout;
    }

    void Circle::setColor(uint16_t color)
    {
        this->color = color;
    }

    void Circle::setRadius(uint16_t radius)
    {
        this->radius = radius;
    }

    void Circle::setMgTop(uint16_t mgTop)
    {
        this->mgTop = mgTop;
    }

    void Circle::setMgLeft(uint16_t mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void Circle::setMgBottom(uint16_t mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void Circle::setMgRight(uint16_t mgRight)
    {
        this->mgRight = mgRight;
    }

    void Circle::setLayout(Layout *layout) {
        this->layout = layout;
    }