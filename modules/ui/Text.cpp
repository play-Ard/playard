#include "Text.h"

string Text::getValue()
    {
        return this->value;
    }

    unsigned short int Text::getFontSize()
    {
        return this->fontSize;
    }

    unsigned short int Text::getColor()
    {
        return this->color;
    }

    short int Text::getMgTop()
    {
        return this->mgTop;
    }

    short int Text::getMgLeft()
    {
        return this->mgLeft;
    }

    short int Text::getMgBottom()
    {
        return this->mgBottom;
    }

    short int Text::getMgRight()
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

    void Text::setFontSize(unsigned short int fontSize)
    {
        this->fontSize = fontSize;
    }

    void Text::setColor(unsigned short int color)
    {
        this->color = color;
    }

    void Text::setMgTop(short int mgTop)
    {
        this->mgTop = mgTop;
    }

    void Text::setMgLeft(short int mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void Text::setMgBottom(short int mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void Text::setMgRight(short int mgRight)
    {
        this->mgRight = mgRight;
    }

    void Text::setLayout(Layout *layout) {
      this->layout = layout;
    }