#include "Layout.h"
#include <string>
#include <cstdint>

#ifndef TEXT_H
#define TEXT_H

class Text
{
private:
    string value;
    int8_t fontSize=1;
    uint16_t color=1;
    uint16_t mgTop;
    uint16_t mgLeft;
    uint16_t mgBottom;
    uint16_t mgRight;
    Layout *layout;

public:
    string getValue();

    int8_t getFontSize();

    uint16_t getColor();

    uint16_t getMgTop();

    uint16_t getMgLeft();

    uint16_t getMgBottom();

    uint16_t getMgRight();

    Layout getLayout();

    void setValue(string value);

    void setFontSize(int8_t fontSize);

    void setColor(uint16_t color);

    void setMgTop(uint16_t mgTop);

    void setMgLeft(uint16_t mgLeft);

    void setMgBottom(uint16_t mgBottom);

    void setMgRight(uint16_t mgRight);

    void setLayout(Layout *layout);
};

#endif