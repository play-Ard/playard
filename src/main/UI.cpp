#include "UI.h"

// -----------------------------------------------------------------------------------
// ------------------------ LAYOUT BEGIN ---------------------------------------------
// -----------------------------------------------------------------------------------

std::string Layout::getID()
{
    return Layout::ID;
}

uint16_t Layout::getW()
{
    return Layout::width;
}

uint16_t Layout::getH()
{
    return Layout::height;
}

uint16_t Layout::getY()
{
    return Layout::yPosition;
}

uint16_t Layout::getX()
{
    return Layout::xPosition;
}

bool Layout::getVisibility()
{
    return Layout::visibility;
}

std::string Layout::getParentID()
{
    return Layout::parentID;
}

void Layout::setID(std::string ID)
{
    Layout::ID = ID;
}

void Layout::setW(uint16_t width)
{
    Layout::width = width;
}

void Layout::setH(uint16_t height)
{
    Layout::height = height;
}

void Layout::setY(uint16_t yPosition)
{
    Layout::yPosition = yPosition;
}

void Layout::setX(uint16_t xPosition)
{
    Layout::xPosition = xPosition;
}

void Layout::setVisibility(bool visibility)
{
    Layout::visibility = visibility;
}

void Layout::setParentID(std::string ID)
{
    Layout::parentID = ID;
}

uint16_t Layout::getMgTop()
{
    return Layout::yPosition - (Layout::height / 2);
}

uint16_t Layout::getMgLeft()
{
    return Layout::xPosition - (Layout::width / 2);
}

// ---------------------------------------------------------------------------------
// ------------------------ LAYOUT END ---------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ POINT BEGIN --------------------------------------------
// ---------------------------------------------------------------------------------

Point::Point(uint16_t X, uint16_t Y)
{
    Point::X = X;
    Point::Y = Y;
}

std::string Point::getID()
{
    return Point::ID;
}

uint8_t Point::getColor()
{
    return Point::color;
}

uint16_t Point::getX()
{
    return Point::X;
}

uint16_t Point::getY()
{
    return Point::Y;
}

bool Point::getVisibility()
{
    return Point::visibility;
}

std::string Point::getParentID()
{
    return Point::parentID;
}

void Point::setID(std::string ID)
{
    Point::ID = ID;
}

void Point::setColor(uint8_t color)
{
    Point::color = color;
}

void Point::setX(uint16_t X)
{
    Point::X = X;
}

void Point::setY(uint16_t Y)
{
    Point::Y = Y;
}

void Point::setVisibility(bool visibility)
{
    Point::visibility = visibility;
}

void Point::setParentID(std::string ID)
{
    Point::parentID = ID;
}

// ---------------------------------------------------------------------------------
// ------------------------ POINT END ----------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ RECTANGLE BEGIN ----------------------------------------
// ---------------------------------------------------------------------------------

std::string Rectangle::getID()
{
    return Rectangle::ID;
}

int16_t Rectangle::getColor()
{
    return Rectangle::color;
}

uint16_t Rectangle::getW()
{
    return Rectangle::width;
}

uint16_t Rectangle::getH()
{
    return Rectangle::height;
}

uint16_t Rectangle::getY()
{
    return Rectangle::yPosition;
}

uint16_t Rectangle::getX()
{
    return Rectangle::xPosition;
}

uint16_t Rectangle::getBorderRadius()
{
    return Rectangle::borderRadius;
}

bool Rectangle::getVisibility()
{
    return Rectangle::visibility;
}

bool Rectangle::getFill()
{
    return Rectangle::fill;
}

std::string Rectangle::getParentID()
{
    return Rectangle::parentID;
}

void Rectangle::setID(std::string ID)
{
    Rectangle::ID = ID;
}

void Rectangle::setColor(uint8_t color)
{
    Rectangle::color = color;
}

void Rectangle::setW(uint16_t width)
{
    Rectangle::width = width;
}

void Rectangle::setH(uint16_t height)
{
    Rectangle::height = height;
}

void Rectangle::setY(uint16_t yPosition)
{
    Rectangle::yPosition = yPosition;
}

void Rectangle::setX(uint16_t xPosition)
{
    Rectangle::xPosition = xPosition;
}

void Rectangle::setBorderRadius(uint16_t radius)
{
    Rectangle::borderRadius = radius;
}

void Rectangle::setVisibility(bool visibility)
{
    Rectangle::visibility = visibility;
}

void Rectangle::setFill(bool fill)
{
    Rectangle::fill = fill;
}

void Rectangle::setParentID(std::string ID)
{
    Rectangle::parentID = ID;
}

uint16_t Rectangle::getMgTop()
{
    return Rectangle::yPosition - (Rectangle::height / 2);
}

uint16_t Rectangle::getMgLeft()
{
    return Rectangle::xPosition - (Rectangle::width / 2);
}

// ---------------------------------------------------------------------------------
// ------------------------ RECTANGLE END ------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ RECTANGLE BEGIN ----------------------------------------
// ---------------------------------------------------------------------------------

std::string Triangle::getID()
{
    return Triangle::ID;
}

uint8_t Triangle::getColor()
{
    return Triangle::color;
}

Point* Triangle::getPoint1()
{
    return Triangle::point1;
}

Point* Triangle::getPoint2()
{
    return Triangle::point2;
}

Point* Triangle::getPoint3()
{
    return Triangle::point3;
}

bool Triangle::getVisibility()
{
    return Triangle::visibility;
}

bool Triangle::getFill()
{
    return Triangle::fill;
}

std::string Triangle::getParentID()
{
    return Triangle::parentID;
}

void Triangle::setID(std::string ID)
{
    Triangle::ID = ID;
}

void Triangle::setColor(uint8_t color)
{
    Triangle::color = color;
}

void Triangle::setPoint1(Point *point)
{
    Triangle::point1 = point;
}

void Triangle::setPoint2(Point *point)
{
    Triangle::point2 = point;
}

void Triangle::setPoint3(Point *point)
{
    Triangle::point3 = point;
}

void Triangle::setPoints(Point *point1, Point *point2, Point *point3)
{
    Triangle::point1 = point1;
    Triangle::point2 = point2;
    Triangle::point3 = point3;
}

void Triangle::setVisibility(bool visibility)
{
    Triangle::visibility = visibility;
}

void Triangle::setFill(bool fill)
{
    Triangle::fill = fill;
}

void Triangle::setParentID(std::string ID)
{
    Triangle::parentID = ID;
}

// ---------------------------------------------------------------------------------
// ------------------------ TRIANGLE END -------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ CIRCLE BEGIN -------------------------------------------
// ---------------------------------------------------------------------------------

std::string Circle::getID()
{
    return Circle::ID;
}

uint16_t Circle::getColor()
{
    return Circle::color;
}

uint16_t Circle::getRadius()
{
    return Circle::radius;
}

uint16_t Circle::getY()
{
    return Circle::yPosition;
}

uint16_t Circle::getX()
{
    return Circle::xPosition;
}

bool Circle::getVisibility()
{
    return Circle::visibility;
}

bool Circle::getFill()
{
    return Circle::fill;
}

std::string Circle::getParentID()
{
    return Circle::parentID;
}

void Circle::setID(std::string ID)
{
    Circle::ID = ID;
}

void Circle::setColor(uint16_t color)
{
    Circle::color = color;
}

void Circle::setRadius(uint16_t radius)
{
    Circle::radius = radius;
}

void Circle::setY(uint16_t yPosition)
{
    Circle::yPosition = yPosition;
}

void Circle::setX(uint16_t xPosition)
{
    Circle::xPosition = xPosition;
}

void Circle::setVisibility(bool visibility)
{
    Circle::visibility = visibility;
}

void Circle::setFill(bool fill)
{
    Circle::fill = fill;
}

void Circle::setParentID(std::string ID)
{
    Circle::parentID = ID;
}

// ---------------------------------------------------------------------------------
// ------------------------ CIRCLE END ---------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ TEXT BEGIN ---------------------------------------------
// ---------------------------------------------------------------------------------

std::string Text::getID()
{
    return Text::ID;
}

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

uint16_t Text::getBgColor()
{
    return Text::bgColor;
}

uint16_t Text::getY()
{
    return Text::yPosition;
}

uint16_t Text::getX()
{
    return Text::xPosition;
}

uint8_t Text::getHeight()
{
    return Text::height;
}

uint8_t Text::getWidth()
{
    return Text::width;
}

bool Text::getVisibility()
{
    return Text::visibility;
}

int8_t Text::getHAlignment()
{
    return Text::hAlignment;
}

int8_t Text::getVAlignment()
{
    return Text::vAlignment;
}

std::string Text::getParentID()
{
    return Text::parentID;
}

void Text::setID(std::string ID)
{
    Text::ID = ID;
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

void Text::setBgColor(uint16_t color)
{
    Text::bgColor = color;
}

void Text::setY(uint16_t yPosition)
{
    Text::yPosition = yPosition;
}

void Text::setX(uint16_t xPosition)
{
    Text::xPosition = xPosition;
}

void Text::setHeight(uint8_t height)
{
    Text::height = height;
}

void Text::setWidth(uint8_t width)
{
    Text::width = width;
}

void Text::setVisibility(bool visibility)
{
    Text::visibility = visibility;
}

void Text::setHAlignment(int8_t value)
{
    Text::hAlignment = value;
}

void Text::setVAlignment(int8_t value)
{
    Text::vAlignment = value;
}

void Text::setParentID(std::string ID)
{
    Text::parentID = ID;
}

uint16_t Text::getMgTop()
{
    return Text::yPosition - (Text::height / 2);
}

uint16_t Text::getMgLeft()
{
    return Text::xPosition - (Text::width / 2);
}

// ---------------------------------------------------------------------------------
// ------------------------ TEXT END -----------------------------------------------
// ---------------------------------------------------------------------------------
