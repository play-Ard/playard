#ifndef CIRCLE_H
#define CIRCLE_H

#include "Layout.h"
#include <cstdint>


class Circle
{
private:
    int16_t color;
    uint16_t radius;
    uint16_t mgTop;
    uint16_t mgLeft;
    uint16_t mgBottom;
    uint16_t mgRight;
    Layout *layout;

public:
    int16_t getColor();

    uint16_t getRadius();

    uint16_t getMgTop();

    uint16_t getMgLeft();

    uint16_t getMgBottom();

    uint16_t getMgRight();

    Layout getLayout();

    void setColor(int16_t color);

    void setRadius(uint16_t radius);

    void setMgTop(uint16_t mgTop);

    void setMgLeft(uint16_t mgLeft);

    void setMgBottom(uint16_t mgBottom);

    void setMgRight(uint16_t mgRight);

    void setLayout(Layout *layout);
};

#endif