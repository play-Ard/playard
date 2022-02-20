#include "Rectangle.h"

int16_t Rectangle::getColor()
{
  return Rectangle::color;
}

uint16_t Rectangle::getWidth()
{
  return Rectangle::width;
}

uint16_t Rectangle::getHeight()
{
  return Rectangle::height;
}

uint16_t Rectangle::getMgTop()
{
  return Rectangle::mgTop;
}

uint16_t Rectangle::getMgLeft()
{
  return Rectangle::mgLeft;
}

uint16_t Rectangle::getMgBottom()
{
  return Rectangle::mgBottom;
}

uint16_t Rectangle::getMgRight()
{
  return Rectangle::mgRight;
}

uint16_t Rectangle::getRadius()
{
  return Rectangle::radius;
}

Layout Rectangle::getLayout()
{
  return *Rectangle::layout;
}

void Rectangle::setW(uint16_t width)
{
  Rectangle::width = width;
}

void Rectangle::setH(uint16_t height)
{
  Rectangle::height = height;
}

void Rectangle::setMgTop(uint16_t mgTop)
{
  Rectangle::mgTop = mgTop;
}

void Rectangle::setMgLeft(uint16_t mgLeft)
{
  Rectangle::mgLeft = mgLeft;
}

void Rectangle::setMgBottom(uint16_t mgBottom)
{
  Rectangle::mgBottom = mgBottom;
}

void Rectangle::setMgRight(uint16_t mgRight)
{
  Rectangle::mgRight = mgRight;
}

void Rectangle::setR(uint16_t radius)
{
  Rectangle::radius = radius;
}

void Rectangle::setLayout(Layout *layout)
{
  Rectangle::layout = layout;
}