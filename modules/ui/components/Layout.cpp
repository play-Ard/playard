#include "Layout.h"

uint16_t Layout::getW()
{
    return Layout::width;
}

uint16_t Layout::getH()
{
    return Layout::height;
}

uint16_t Layout::getMgTop()
{
    return Layout::mgTop;
}

uint16_t Layout::getMgLeft()
{
    return Layout::mgLeft;
}

uint16_t Layout::getMgBottom()
{
    return Layout::mgBottom;
}

uint16_t Layout::getMgRight()
{
    return Layout::mgRight;
}

void Layout::setW(uint16_t width)
{
    Layout::width = width;
}

void Layout::setH(unsigned short int height)
{
    Layout::height = height;
}

void Layout::setMgTop(short int mgTop)
{
    Layout::mgTop = mgTop;
}

void Layout::setMgLeft(short int mgLeft)
{
    Layout::mgLeft = mgLeft;
}

void Layout::setMgBottom(short int mgBottom)
{
    Layout::mgBottom = mgBottom;
}

void Layout::setMgRight(short int mgRight)
{
    Layout::mgRight = mgRight;
}