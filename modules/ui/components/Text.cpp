#include "Text.h"

std::string Text::getValue()
{
    return Text::value;
}

int8_t Text::getFontSize()
{
    return Text::fontSize;
}

uint16_t Text::getColor()
{
    return Text::color;
}

uint16_t Text::getMgTop()
{
    return Text::mgTop;
}

uint16_t Text::getMgLeft()
{
    return Text::mgLeft;
}

uint16_t Text::getMgBottom()
{
    return Text::mgBottom;
}

uint16_t Text::getMgRight()
{
    return Text::mgRight;
}

Layout Text::getLayout()
{
    return *Text::layout;
}

void Text::setValue(std::string value)
{
    Text::value = value;
}

void Text::setFontSize(int8_t fontSize)
{
    Text::fontSize = fontSize;
}

void Text::setColor(uint16_t color)
{
    Text::color = color;
}

void Text::setMgTop(uint16_t mgTop)
{
    Text::mgTop = mgTop;
}

void Text::setMgLeft(uint16_t mgLeft)
{
    Text::mgLeft = mgLeft;
}

void Text::setMgBottom(uint16_t mgBottom)
{
    Text::mgBottom = mgBottom;
}

void Text::setMgRight(uint16_t mgRight)
{
    Text::mgRight = mgRight;
}

void Text::setLayout(Layout *layout)
{
    Text::layout = layout;
}