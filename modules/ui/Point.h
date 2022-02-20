#ifndef POINT_H
#define POINT_H

#include <cstdint>

class Point
{
private:
    uint16_t X=0;
    uint16_t Y=0;

public:
    uint16_t getX();

    uint16_t getY();

    void setX(uint16_t X);

    void setY(uint16_t Y);
};


#endif