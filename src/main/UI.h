#ifndef UI_H
#define UI_H

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <cstdint>
#include <string>

class Component
{
public:
    // virtual std::string getID() = 0;
    // virtual std::string getParentID() = 0;

    // virtual void setParentID(std::string) = 0;
};

// -----------------------------------------------------------------------------------
// ------------------------ LAYOUT BEGIN ---------------------------------------------
// -----------------------------------------------------------------------------------

class Layout : public Component
{
private:
    std::string ID;
    uint16_t width;
    uint16_t height;
    uint16_t yPosition;
    uint16_t xPosition;
    bool visibility;
    std::string parentID;

public:
    std::string getID();

    uint16_t getW();

    uint16_t getH();

    uint16_t getY();

    uint16_t getX();

    bool getVisibility();

    std::string getParentID();

    void setID(std::string ID);

    void setW(uint16_t width);

    void setH(uint16_t height);

    void setY(uint16_t yPosition);

    void setX(uint16_t xPosition);

    void setVisibility(bool visibility);

    void setParentID(std::string ID);

    uint16_t getMgTop();
    uint16_t getMgLeft();
};

// ---------------------------------------------------------------------------------
// ------------------------ LAYOUT END ---------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ POINT BEGIN --------------------------------------------
// ---------------------------------------------------------------------------------

class Point : public Component
{
private:
    std::string ID;
    uint8_t color;
    uint16_t X = 0;
    uint16_t Y = 0;
    bool visibility;
    std::string parentID;

public:
    Point(uint16_t X, uint16_t Y);

    std::string getID();

    uint8_t getColor();

    uint16_t getX();

    uint16_t getY();

    bool getVisibility();

    std::string getParentID();

    void setID(std::string ID);

    void setColor(uint8_t color);

    void setX(uint16_t X);

    void setY(uint16_t Y);

    void setVisibility(bool visibility);

    void setParentID(std::string ID);
};

// ---------------------------------------------------------------------------------
// ------------------------ POINT END ---------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ RECTANGLE BEGIN ----------------------------------------
// ---------------------------------------------------------------------------------

class Rectangle : public Component
{
private:
    std::string ID;
    uint8_t color;
    uint16_t width;
    uint16_t height;
    uint16_t yPosition;
    uint16_t xPosition;
    uint16_t borderRadius;
    bool visibility;
    bool fill;
    std::string parentID;

public:
    std::string getID();

    int16_t getColor();

    uint16_t getW();

    uint16_t getH();

    uint16_t getY();

    uint16_t getX();

    uint16_t getBorderRadius();

    bool getVisibility();

    bool getFill();

    std::string getParentID();

    void setID(std::string ID);

    void setColor(uint8_t color);

    void setW(uint16_t width);

    void setH(uint16_t height);

    void setY(uint16_t yPosition);

    void setX(uint16_t xPosition);

    void setBorderRadius(uint16_t radius);

    void setVisibility(bool visibility);

    void setFill(bool fill);

    void setParentID(std::string ID);

    uint16_t getMgTop();
    uint16_t getMgLeft();
};

// ---------------------------------------------------------------------------------
// ------------------------ RECTANGLE END ------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ TRIANGLE BEGIN -----------------------------------------
// ---------------------------------------------------------------------------------

class Triangle : public Component
{
private:
    std::string ID;
    uint8_t color;
    Point *point1;
    Point *point2;
    Point *point3;
    bool visibility;
    bool fill;
    std::string parentID;

public:
    std::string getID();

    uint8_t getColor();

    Point getPoint1();

    Point getPoint2();

    Point getPoint3();

    bool getVisibility();

    bool getFill();

    std::string getParentID();

    void setID(std::string ID);

    void setColor(uint8_t color);

    void setPoint1(Point *point);

    void setPoint2(Point *point);

    void setPoint3(Point *point);

    void setPoints(Point *point1, Point *point2, Point *point3);

    void setVisibility(bool visibility);

    void setFill(bool fill);

    void setParentID(std::string ID);
};

// ---------------------------------------------------------------------------------
// ------------------------ TRIANGLE END -------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ CIRCLE BEGIN -------------------------------------------
// ---------------------------------------------------------------------------------

class Circle : public Component
{
private:
    std::string ID;
    uint16_t color;
    uint16_t radius;
    uint16_t yPosition;
    uint16_t xPosition;
    bool visibility;
    bool fill;
    std::string parentID;

public:
    std::string getID();

    uint16_t getColor();

    uint16_t getRadius();

    uint16_t getY();

    uint16_t getX();

    bool getVisibility();

    bool getFill();

    std::string getParentID();

    void setID(std::string ID);

    void setColor(uint16_t color);

    void setRadius(uint16_t radius);

    void setY(uint16_t yPosition);

    void setX(uint16_t xPosition);

    void setVisibility(bool visibility);

    void setFill(bool fill);

    void setParentID(std::string ID);
};

// ---------------------------------------------------------------------------------
// ------------------------ CIRCLE END ---------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ TEXT BEGIN ---------------------------------------------
// ---------------------------------------------------------------------------------

class Text : public Component
{
private:
    std::string ID;
    std::string value;
    int8_t fontSize = 1;
    uint16_t color = 1;
    uint16_t bgColor = 0;
    uint16_t yPosition;
    uint16_t xPosition;
    uint8_t width;
    uint8_t height;
    bool visibility;
    int8_t hAlignment;
    int8_t vAlignment;
    std::string parentID;

public:
    std::string getID();

    std::string getValue();

    int8_t getFontSize();

    uint16_t getColor();

    uint16_t getBgColor();

    uint16_t getY();

    uint16_t getX();

    uint8_t getHeight();

    uint8_t getWidth();

    bool getVisibility();

    int8_t getHAlignment();

    int8_t getVAlignment();

    std::string getParentID();

    void setID(std::string ID);

    void setValue(std::string value);

    void setFontSize(int8_t fontSize);

    void setColor(uint16_t color);

    void setBgColor(uint16_t color);

    void setY(uint16_t yPosition);

    void setX(uint16_t xPosition);

    void setHeight(uint8_t height);

    void setWidth(uint8_t width);

    void setVisibility(bool visibility);

    void setHAlignment(int8_t value);

    void setVAlignment(int8_t value);

    void setParentID(std::string ID);

    uint16_t getMgTop();
    uint16_t getMgLeft();
};

// ---------------------------------------------------------------------------------
// ------------------------ TEXT END ---------------------------------------------
// ---------------------------------------------------------------------------------

#endif
