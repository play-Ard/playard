#ifndef LAYOUT_H
#define LAYOUT_H

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
    unsigned short int getW();

    unsigned short int getH();

    short int getMgTop();

    short int getMgLeft();

    short int getMgBottom();

    short int getMgRight();

    void setW(unsigned short int width);

    void setH(unsigned short int height);

    void setMgTop(short int mgTop);

    void setMgLeft(short int mgLeft);

    void setMgBottom(short int mgBottom);

    void setMgRight(short int mgRight);
};

#endif