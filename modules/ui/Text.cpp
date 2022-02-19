#include "Text.h"

string Text::getValue()
    {
        return this->value;
    }

    int8_t Text::getFontSize()
    {
        return this->fontSize;
    }

    uint16_t Text::getColor()
    {
        return this->color;
    }

    uint16_t Text::getMgTop()
    {
        return this->mgTop;
    }

    uint16_t Text::getMgLeft()
    {
        return this->mgLeft;
    }

    uint16_t Text::getMgBottom()
    {
        return this->mgBottom;
    }

    uint16_t Text::getMgRight()
    {
        return this->mgRight;
    }

    Layout Text::getLayout() {
      return *this->layout;
    }

    void Text::setValue(string value)
    {
        this->value = value;
    }

    void Text::setFontSize(int8_t fontSize)
    {
        this->fontSize = fontSize;
    }

    void Text::setColor(uint16_t color)
    {
        this->color = color;
    }

    void Text::setMgTop(uint16_t mgTop)
    {
        this->mgTop = mgTop;
    }

    void Text::setMgLeft(uint16_t mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void Text::setMgBottom(uint16_t mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void Text::setMgRight(uint16_t mgRight)
    {
        this->mgRight = mgRight;
    }

    void Text::setLayout(Layout *layout) {
      this->layout = layout;
    }