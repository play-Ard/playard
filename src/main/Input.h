#ifndef INPUT_H
#define INPUT_H
#include <cstdint>

class Input
{
private:
    uint8_t BUTTON_1_PIN = 15;
    uint8_t BUTTON_2_PIN = 2;
    uint8_t BUTTON_3_PIN = 32;
    uint8_t BUTTON_4_PIN = 200; // disconnected
    uint8_t BUTTON_U_PIN = 0;
    uint8_t BUTTON_R_PIN = 4;
    uint8_t BUTTON_D_PIN = 33;
    uint8_t BUTTON_L_PIN = 27;

    int BUTTON_1_PREV = 0;
    int BUTTON_2_PREV = 0;
    int BUTTON_3_PREV = 0;
    int BUTTON_4_PREV = 0;
    int BUTTON_U_PREV = 0;
    int BUTTON_R_PREV = 0;
    int BUTTON_D_PREV = 0;
    int BUTTON_L_PREV = 0;
    
    uint16_t SERIAL_PORT = 9600;

    bool PRESSED = 1;
    bool NOT_PRESSED = 0;

public:
    const uint8_t shortDelay = 200;
    
    const uint16_t longDelay = 500;

    void begin();

    void print();

    bool BUTTON_1();
    
    bool BUTTON_2();

    bool BUTTON_3();

    bool BUTTON_4();

    bool BUTTON_U();

    bool BUTTON_R();

    bool BUTTON_D();

    bool BUTTON_L();

    int BUTTON_1_PREV_T();
    
    int BUTTON_2_PREV_T();

    int BUTTON_3_PREV_T();

    int BUTTON_4_PREV_T();

    int BUTTON_U_PREV_T();

    int BUTTON_R_PREV_T();

    int BUTTON_D_PREV_T();
    
    int BUTTON_L_PREV_T();

    void BUTTON_1_PREV_T(int past);

    void BUTTON_2_PREV_T(int past);
    
    void BUTTON_3_PREV_T(int past);
    
    void BUTTON_4_PREV_T(int past);
    
    void BUTTON_U_PREV_T(int past);

    void BUTTON_R_PREV_T(int past);

    void BUTTON_D_PREV_T(int past);

    void BUTTON_L_PREV_T(int past);
};

#endif