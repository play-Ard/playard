#include "Layout.h"

unsigned short int Layout::getW()
{
    return Layout::width;
}

unsigned short int Layout::getH()
{
    return Layout::height;
}

short int Layout::getMgTop()
{
    return Layout::mgTop;
}

short int Layout::getMgLeft()
{
    return Layout::mgLeft;
}

short int Layout::getMgBottom()
{
    return Layout::mgBottom;
}

short int Layout::getMgRight()
{
    return Layout::mgRight;
}

void Layout::setW(unsigned short int width)
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