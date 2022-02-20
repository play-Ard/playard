#include "Rectangle.h"


    int16_t Rectangle::getColor()
    {
        return this->color;
    }

    uint16_t Rectangle::getWidth()
    {
        return this->width;
    }

    uint16_t Rectangle::getHeight()
    {
        return this->height;
    }

    uint16_t Rectangle::getMgTop()
    {
        return this->mgTop;
    }

    uint16_t Rectangle::getMgLeft()
    {
        return this->mgLeft;
    }

    uint16_t Rectangle::getMgBottom()
    {
        return this->mgBottom;
    }

    uint16_t Rectangle::getMgRight()
    {
        return this->mgRight;
    }

    uint16_t Rectangle::getRadius()
    {
        return this->radius;
    }

    Layout Rectangle::getLayout() {
      return *this->layout;
    }

    void Rectangle::setW(uint16_t width)
    {
      this->width = width;
    }

    void Rectangle::setH(uint16_t height)
    {
      this->height = height;
    }

    void Rectangle::setMgTop(uint16_t mgTop)
    {
      this->mgTop = mgTop;
    }

    void Rectangle::setMgLeft(uint16_t mgLeft)
    {
      this->mgLeft = mgLeft;
    }

    void Rectangle::setMgBottom(uint16_t mgBottom)
    {
      this->mgBottom = mgBottom;
    }

    void Rectangle::setMgRight(uint16_t mgRight)
    {
      this->mgRight = mgRight;
    }

    void Rectangle::setR(uint16_t radius)
    {
      this->radius = radius;
    }

    void Rectangle::setLayout(Layout *layout) {
      this->layout = layout;
    }