#ifndef POINT_H
#define POINT_H

class Point
{
private:
    unsigned short int X=0;
    unsigned short int Y=0;

public:
    unsigned short int getX();

    unsigned short int getY();

    void setX(unsigned short int X);

    void setY(unsigned short int Y);
};


#endif