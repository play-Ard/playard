#include "Layout.h"

#ifndef TEXT_H
#define TEXT_H

class Text
{
private:
    string value;
    unsigned short int fontSize=1;
    unsigned short int color=1;
    short int mgTop;
    short int mgLeft;
    short int mgBottom;
    short int mgRight;
    Layout *layout;

public:
    string getValue();

    unsigned short int getFontSize();

    unsigned short int getColor();

    short int getMgTop();

    short int getMgLeft();

    short int getMgBottom();

    short int getMgRight();

    Layout getLayout();

    void setValue(string value);

    void setFontSize(unsigned short int fontSize);

    void setColor(unsigned short int color);

    void setMgTop(short int mgTop);

    void setMgLeft(short int mgLeft);

    void setMgBottom(short int mgBottom);

    void setMgRight(short int mgRight);

    void setLayout(Layout *layout);
};

#endif