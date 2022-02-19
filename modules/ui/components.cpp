#include <string>
#include <iostream>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

using namespace std;

class Point
{
private:
    unsigned short int X=0;
    unsigned short int Y=0;

public:
    unsigned short int getX()
    {
        return this->X;
    }
    unsigned short int getY()
    {
        return this->Y;
    }
    void setX(unsigned short int X)
    {
        this->X = X;
    }
    void setY(unsigned short int Y)
    {
        this->Y = Y;
    }

};

class Layout
{
private:
    unsigned short int width;
    unsigned short int height;
    short int mgTop;
    short int mgLeft;
    short int mgBottom;
    short int mgRight;

public:
    unsigned short int getW()
    {
        return this->width;
    }

    unsigned short int getH()
    {
        return this->height;
    }

    short int getMgTop()
    {
        return this->mgTop;
    }

    short int getMgLeft()
    {
        return this->mgLeft;
    }

    short int getMgBottom()
    {
        return this->mgBottom;
    }

    short int getMgRight()
    {
        return this->mgRight;
    }

    void setW(unsigned short int width)
    {
        this->width = width;
    }

    void setH(unsigned short int height)
    {
        this->height = height;
    }

    void setMgTop(short int mgTop)
    {
        this->mgTop = mgTop;
    }

    void setMgLeft(short int mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void setMgBottom(short int mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void setMgRight(short int mgRight)
    {
        this->mgRight = mgRight;
    }
};

class Text
{
private:
    string value;
    unsigned short int fontSize=1;
    unsigned short int color=1;
    short int mgTop;
    short int mgLeft;
    short int mgBottom;
    short int mgRight;
    Layout *layout;

public:
    string getValue()
    {
        return this->value;
    }

    unsigned short int getFontSize()
    {
        return this->fontSize;
    }

    unsigned short int getColor()
    {
        return this->color;
    }

    short int getMgTop()
    {
        return this->mgTop;
    }

    short int getMgLeft()
    {
        return this->mgLeft;
    }

    short int getMgBottom()
    {
        return this->mgBottom;
    }

    short int getMgRight()
    {
        return this->mgRight;
    }

    Layout getLayout() {
      return *this->layout;
    }

    void setValue(string value)
    {
        this->value = value;
    }

    void setFontSize(unsigned short int fontSize)
    {
        this->fontSize = fontSize;
    }

    void setColor(unsigned short int color)
    {
        this->color = color;
    }

    void setMgTop(short int mgTop)
    {
        this->mgTop = mgTop;
    }

    void setMgLeft(short int mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void setMgBottom(short int mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void setMgRight(short int mgRight)
    {
        this->mgRight = mgRight;
    }

    void setLayout(Layout *layout) {
      this->layout = layout;
    }
};



class Rectangle
{
private:
    unsigned short int color;
    unsigned short int width;
    unsigned short int height;
    short int mgTop;
    short int mgLeft;
    short int mgBottom;
    short int mgRight;
    unsigned short int radius;
    Layout *layout;

public:
    unsigned short int getColor()
    {
        return this->color;
    }

    unsigned short int getW()
    {
        return this->width;
    }

    unsigned short int getH()
    {
        return this->height;
    }

    short int getMgTop()
    {
        return this->mgTop;
    }

    short int getMgLeft()
    {
        return this->mgLeft;
    }

    short int getMgBottom()
    {
        return this->mgBottom;
    }

    short int getMgRight()
    {
        return this->mgRight;
    }

    unsigned short int getRadius()
    {
        return this->radius;
    }

    Layout getLayout() {
      return *this->layout;
    }

    void setW(unsigned short int width)
    {
      this->width = width;
    }

    void setH(unsigned short int height)
    {
      this->height = height;
    }

    void setMgTop(short int mgTop)
    {
      this->mgTop = mgTop;
    }

    void setMgLeft(short int mgLeft)
    {
      this->mgLeft = mgLeft;
    }

    void setMgBottom(short int mgBottom)
    {
      this->mgBottom = mgBottom;
    }

    void setMgRight(short int mgRight)
    {
      this->mgRight = mgRight;
    }

    void setR(unsigned short int radius)
    {
      this->radius = radius;
    }

    void setLayout(Layout *layout) {
      this->layout = layout;
    }
};

class Circle
{
private:
    unsigned short int color;
    unsigned short int radius;
    short int mgTop;
    short int mgLeft;
    short int mgBottom;
    short int mgRight;
    Layout *layout;

public:
    unsigned short int getColor()
    {
        return this->color;
    }

    unsigned short int getRadius()
    {
        return this->radius;
    }

    short int getMgTop()
    {
        return this->mgTop;
    }

    short int getMgLeft()
    {
        return this->mgLeft;
    }

    short int getMgBottom()
    {
        return this->mgBottom;
    }

    short int getMgRight()
    {
        return this->mgRight;
    }

    Layout getLayout() {
        return *this->layout;
    }

    void setColor(unsigned short int color)
    {
        this->color = color;
    }

    void setRadius(unsigned short int radius)
    {
        this->radius = radius;
    }

    void setMgTop(short int mgTop)
    {
        this->mgTop = mgTop;
    }

    void setMgLeft(short int mgLeft)
    {
        this->mgLeft = mgLeft;
    }

    void setMgBottom(short int mgBottom)
    {
        this->mgBottom = mgBottom;
    }

    void setMgRight(short int mgRight)
    {
        this->mgRight = mgRight;
    }

    void setLayout(Layout *layout) {
        this->layout = layout;
    }
};

class Triangle
{
private:
    unsigned short int color;
    Point *point1;
    Point *point2;
    Point *point3;
    Layout layout;
    
public:
    unsigned short int getColor()
    {
        return this->color;
    }

    Point getPoint1()
    {
        return *this->point1;
    }

    Point getPoint2()
    {
        return *this->point2;
    }

    Point getPoint3()
    {
        return *this->point3;
    }

    Layout getLayout(){
      return layout;
    }

    void setColor(unsigned short int color)
    {
        this->color = color;
    }

    void setPoint1(Point *point1)
    {
        this->point1 = point1;
    }

    void setPoint2(Point *point2)
    {
        this->point2 = point2;
    }

    void setPoint3(Point *point3)
    {
        this->point3 = point3;
    }

    void setPoints(Point *point1, Point *point2, Point *point3) {
        this->setPoint1(point1);
        this->setPoint2(point2);
        this->setPoint3(point3);
    }

    void setLayout(){
      this->layout = layout;
    }
};

int main(void) {
  Point point1;
  Point point2;
  Point point3;
  Triangle tri1;
  
  tri1.setPoints(&point1, &point2, &point3);

  point1.setX(4);

  std::cout<< tri1.getPoint1().getX();
  
  return 0;
}