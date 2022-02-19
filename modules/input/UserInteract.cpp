#include "UserInteract.h"

UserInteract::UserInteract(int xPin, int yPin, int buttonPin)
{
    this->xPin = xPin;
    this->yPin = yPin;
    this->buttonPin = buttonPin;
}

void UserInteract::begin() {
    /*
    Makes some configurations to read the values properly
    */
    pinMode(UserInteract::xPin, INPUT);
    pinMode(UserInteract::yPin, INPUT);
    pinMode(UserInteract::buttonPin, INPUT_PULLUP);
}

void UserInteract::readValues()
{
    UserInteract::xPosition = analogRead(this->xPin);
    UserInteract::xPosition = map(xPosition, UserInteract::pjoyMinValue, UserInteract::pjoyMaxValue, UserInteract::joyMaxXValue, UserInteract::joyMinXValue);

    UserInteract::yPosition = analogRead(this->yPin);
    UserInteract::yPosition = map(yPosition, UserInteract::pjoyMinValue, UserInteract::pjoyMaxValue, UserInteract::joyMaxYValue, UserInteract::joyMinYValue);

    UserInteract::joyTrigger = abs(digitalRead(this->buttonPin) - 1);
}

void UserInteract::print()
{
    Serial.print("X Position: ");
    Serial.print(UserInteract::xPosition);
    Serial.print(" | Y Position: ");
    Serial.print(UserInteract::yPosition);
    Serial.print(" | Button Flag: ");
    Serial.println(UserInteract::joyTrigger);
}

uint16_t UserInteract::getXPosition()
{
    return UserInteract::xPosition;
}

uint16_t UserInteract::getYPosition()
{
    return UserInteract::yPosition;
}

bool UserInteract::getJoyTrigger()
{
    return UserInteract::joyTrigger;
}

bool UserInteract::JOYTRIGGER()
{
    return UserInteract::getJoyTrigger() == 1;
}

bool UserInteract::RIGHT()
{
    return UserInteract::getXPosition() == UserInteract::joyMaxXValue;
}

bool UserInteract::LEFT()
{
    return UserInteract::getXPosition() == UserInteract::joyMinXValue;
}

bool UserInteract::UP()
{
    return UserInteract::getYPosition() == UserInteract::joyMinYValue;
}

bool UserInteract::DOWN()
{
    return UserInteract::getYPosition() == UserInteract::joyMaxYValue;
}