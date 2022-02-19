#ifndef LAYOUT_H
#define LAYOUT_H
#include <cstdint>

class Layout
{
private:
    uint16_t width;
    uint16_t height;
    uint16_t mgTop;
    uint16_t mgLeft;
    uint16_t mgBottom;
    uint16_t mgRight;
public:
    uint16_t getW();

    uint16_t getH();

    uint16_t getMgTop();

    uint16_t getMgLeft();

    uint16_t getMgBottom();

    uint16_t getMgRight();

    void setW(uint16_t width);

    void setH(uint16_t height);

    void setMgTop(uint16_t mgTop);

    void setMgLeft(uint16_t mgLeft);

    void setMgBottom(uint16_t mgBottom);

    void setMgRight(uint16_t mgRight);
};

#endif