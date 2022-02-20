#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Layout.h"
#include <stdint.h>

class Rectangle
{
private:
    int16_t color;
    uint16_t width;
    uint16_t height;
    uint16_t mgTop;
    uint16_t mgLeft;
    uint16_t mgBottom;
    uint16_t mgRight;
    uint16_t radius;
    Layout *layout;

public:
    int16_t getColor();

    uint16_t getWidth();

    uint16_t getHeight();

    uint16_t getMgTop();

    uint16_t getMgLeft();

    uint16_t getMgBottom();

    uint16_t getMgRight();

    uint16_t getRadius();

    Layout getLayout();

    void setW(uint16_t width);

    void setH(uint16_t height);

    void setMgTop(uint16_t mgTop);

    void setMgLeft(uint16_t mgLeft);

    void setMgBottom(uint16_t mgBottom);

    void setMgRight(uint16_t mgRight);

    void setR(uint16_t radius);

    void setLayout(Layout *layout);
};

#endif