#ifndef INPUT_H
#define INPUT_H
#include <cstdint>

class Input
{
private:
    uint8_t BUTTON_1_PIN = 15;
    uint8_t BUTTON_2_PIN = 2;
    uint8_t BUTTON_3_PIN = 32;
    uint8_t BUTTON_U_PIN = 0;
    uint8_t BUTTON_R_PIN = 4;
    uint8_t BUTTON_D_PIN = 33;
    uint8_t BUTTON_L_PIN = -1;
    
    uint16_t SERIAL_PORT = 9600;

    bool NOT_PRESSED = 0;
    bool PRESSED = 1;

public:
    void begin();

    void print();

    bool BUTTON_1();
    
    bool BUTTON_2();

    bool BUTTON_3();

    bool BUTTON_U();

    bool BUTTON_R();

    bool BUTTON_D();

    bool BUTTON_L();
};

#endif
