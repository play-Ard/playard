#include <stdint.h>

#ifndef USERINTERACT_H
#define USERINTERACT_H


class UserInteract
{
  private:
    uint8_t xPin;
    uint8_t yPin;
    uint8_t buttonPin;
    
    uint16_t xPosition;
    uint16_t yPosition;
    bool joyTrigger;

    uint16_t pjoyMinValue = 1024;
    uint16_t pjoyMaxValue = 1024;
    uint16_t joyMinXValue = 0;
    uint16_t joyMaxXValue = 127;
    uint16_t joyMinYValue = 0;
    uint16_t joyMaxYValue = 63;
  
  public:
    /*
    Init function for UserInteract class

    Parameters: {
    xPin: Pin to read horizontal position of analog joystick
    yPin: Pin to read vertical position of analog joystick
    buttonPin: Pin to read case of button on the analog joystick
    } 
    */
    UserInteract (int xPin, int yPin, int buttonPin);

    /*
    Makes some configurations to read the values properly
    */
    void begin();

    void readValues();

    void print();
    
    uint16_t getXPosition();
    
    uint16_t getYPosition();
    
    bool getJoyTrigger();

    bool JOYTRIGGER ();

    bool RIGHT ();
    
    bool LEFT ();

    bool UP ();

    bool DOWN ();
};

#endif