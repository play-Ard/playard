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

/*
    Declaration for class Layout

    - A layout is a unique component that can contain other types of components, including layouts.
    - When position of a layout is changed also positions of child components changes
    - It can be used for grouping components to move together
    - It is useful to create more attractive designs with less mathematical and logical operations
*/
class Layout : public Component
{
private:
    std::string ID;
    uint16_t width;
    uint16_t height;
    uint16_t yPosition;
    uint16_t xPosition;
    bool visibility;
    std::string parentID; // Id of parent layout

public:
    std::string getID();
    /*
        Summary:
            Returns ID of a layout

        Example Usage:
            std::string layoutID = myLayout->getID();
    */

    uint16_t getW();
    /*
        Summary:
            Returns width of a layout

        Example Usage:
            int layoutWidth = myLayout->getW();
    */

    uint16_t getH();
    /*
        Summary:
            Returns height of a layout

        Example Usage:
            int layoutWidth = myLayout->getH();
    */

    uint16_t getY();
    /*
        Summary:
            Returns vertical position of a layout

        Example Usage:
            int yPosition = myLayout->getY();
    */

    uint16_t getX();
    /*
        Summary:
            Returns horizontal position of a layout

        Example Usage:
            int xPosition = myLayout->getX();
    */

    bool getVisibility();
    /*
        Summary:
            Returns state of visibility of a layout

        Example Usage:
            bool isNotHidden = myLayout->getVisibility();
    */

    std::string getParentID();
    /*
        Summary:
            Returns ID of parent layout of a layout

        Example Usage:
            std::string parentID = myLayout->getParentID();
    */

    void setID(std::string ID);
    /*
        Summary:
            Replaces the ID of a layout with the given value

        Params: {
            ID: Value to set
        }

        Example Usage:
            myLayout->setID("newLayoutID");
    */

    void setW(uint16_t width);
    /*
        Summary:
            Replaces the width of a layout with the given value

        Params: {
            width: Value to set
        }

        Example Usage:
            myLayout->setW(96);
    */

    void setH(uint16_t height);
    /*
        Summary:
            Replaces the height of a layout with the given value

        Params: {
            height: Value to set
        }

        Example Usage:
            myLayout->setH(48);
    */

    void setY(uint16_t yPosition);
    /*
        Summary:
            Replaces the vertical position of a layout with the given value

        Params: {
            yPosition: Value to set
        }

        Example Usage:
            myLayout->setY(myLayout->getY() + 4); // Shifts layout and its all child components up by 4 pixels
    */

    void setX(uint16_t xPosition);
    /*
        Summary:
            Replaces the horizontal position of a layout with the given value

        Params: {
            xPosition: Value to set
        }

        Example Usage:
            myLayout->setX(myLayout->getX() - 8); // Shifts layout and its all child components left by 8 pixels
    */

    void setVisibility(bool visibility);
    /*
        Summary:
            Replaces the state of visibility of a layout with the given value

        Params: {
            visibility: Value to set
        }

        Example Usage:
            myLayout->setVisibility(0); // Hides layout and its all child components
    */

    void setParentID(std::string ID);
    /*
        Summary:
            Replaces the ID of a layout's parent layout with the given value

        Params: {
            ID: Value to set
        }

        Example Usage:
            myLayout->setParentID("otherLayout");
    */

    uint16_t getMgTop();
    /*
        Summary:
            Returns the non-relative top margin of a layout

        Example Usage:
            int mgTop = myLayout->getMgTop(); // Returns number of pixels between top side of layout and top side of display screen
    */

    uint16_t getMgLeft();
    /*
        Summary:
            Returns the non-relative left margin of a layout

        Example Usage:
            int mgLeft = myLayout->getMgLeft(); // Returns number of pixels between left side of layout and left side of display screen
    */
};

// ---------------------------------------------------------------------------------
// ------------------------ LAYOUT END ---------------------------------------------
// ---------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------
// ------------------------ POINT BEGIN --------------------------------------------
// ---------------------------------------------------------------------------------

/*
    Declaration for class Point

    - Point is a class for drawing a single pixel in display screen
    - Useful for creating particles, ammos etc.
*/
class Point : public Component
{
private:
    std::string ID;
    uint8_t color;
    uint16_t X = 0;
    uint16_t Y = 0;
    bool visibility;
    std::string parentID; // ID of parent layout

public:
    Point(uint16_t X, uint16_t Y);
    /*
        Summary:
            Constructor for class Point
        
        Params: {
            X: Horizontal position of point component
            Y: Vertical position of point component
        }

        Example Usage:
            Point myPoint = Point(12, 24);
    */

    std::string getID();
    /*
        Summary:
            Returns ID of a point component

        Example Usage:
            std::string myPointID = myPoint->getID();
    */

    uint8_t getColor();
    /*
        Summary:
            Returns color of a point component

        Example Usage:
            int myPointColor = myPoint->getColor();
    */


    uint16_t getX();
    /*
        Summary:
            Returns horizontal position of a point component

        Example Usage:
            int myPointX = myPoint->getX();
    */

    uint16_t getY();
    /*
        Summary:
            Returns vertical position of a point component

        Example Usage:
            int myPointY = myPoint->getY();
    */
   

    bool getVisibility();
    /*
        Summary:
            Returns state of visibility of a point component

        Example Usage:
            bool myPointVisibility = myPoint->getVisibility();
    */

    std::string getParentID();
    /*
        Summary:
            Returns ID of parent layout of a point component

        Example Usage:
            bool myPointParentID = myPoint->getParentID();
    */

    void setID(std::string ID);
    /*
        Summary:
            Replaces the ID of a point with the given value

        Params: {
            ID: Value to set
        }

        Example Usage:
            myPoint->setID("point1");
    */

    void setColor(uint8_t color);
    /*
        Summary:
            Replaces the color of a point with the given value

        Params: {
            color: Value to set
        }

        Example Usage:
            int WHITE = 1;
            myPoint->setColor(WHITE);
    */

    void setX(uint16_t X);
    /*
        Summary:
            Replaces the horizontal position of a point with the given value

        Params: {
            X: Value to set
        }

        Example Usage:
            myPoint->setX(myPoint->getX() + 5); // Shifts the point component right by 5 pixels
    */

    void setY(uint16_t Y);
    /*
        Summary:
            Replaces the vertical position of a point with the given value

        Params: {
            Y: Value to set
        }

        Example Usage:
            myPoint->setY(myPoint->getX() - 12); // Shifts the point component down by 12 pixels
    */

    void setVisibility(bool visibility);
    /*
        Summary:
            Replaces the state of visibility of a point with the given value

        Params: {
            visibility: Value to set
        }

        Example Usage:
            myPoint->setVisibility(0); // Hides the point component
    */

    void setParentID(std::string ID);
    /*
        Summary:
            Replaces the ID of parent layout of a point with the given value

        Params: {
            ID: Value to set
        }

        Example Usage:
            myPoint->setParentID("otherLayout");
    */
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
