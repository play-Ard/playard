#include "Layout.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    unsigned short int color;
    unsigned short int radius;
    short int mgTop;
    short int mgLeft;
    short int mgBottom;
    short int mgRight;
    Layout *layout;

public:
    unsigned short int getColor();

    unsigned short int getRadius();

    short int getMgTop();

    short int getMgLeft();

    short int getMgBottom();

    short int getMgRight();

    Layout getLayout();

    void setColor(unsigned short int color);

    void setRadius(unsigned short int radius);

    void setMgTop(short int mgTop);

    void setMgLeft(short int mgLeft);

    void setMgBottom(short int mgBottom);

    void setMgRight(short int mgRight);

    void setLayout(Layout *layout);
};

#endif