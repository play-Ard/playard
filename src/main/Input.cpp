#include "Arduino.h"
#include "Input.h"

void Input::begin()
{
    pinMode(Input::BUTTON_1_PIN, INPUT_PULLUP);
    pinMode(Input::BUTTON_2_PIN, INPUT_PULLUP);
    pinMode(Input::BUTTON_3_PIN, INPUT_PULLUP);
    pinMode(Input::BUTTON_U_PIN, INPUT_PULLUP);
    pinMode(Input::BUTTON_R_PIN, INPUT_PULLUP);
    pinMode(Input::BUTTON_D_PIN, INPUT_PULLUP);
    pinMode(Input::BUTTON_L_PIN, INPUT_PULLUP);

    Serial.begin(Input::SERIAL_PORT);
}

void Input::print() {
    Serial.print("BUTTON 1 : ");
    Serial.print(Input::BUTTON_1());
    Serial.print(" | BUTTON 2 : ");
    Serial.print(Input::BUTTON_2());
    Serial.print(" | BUTTON 3 : ");
    Serial.print(Input::BUTTON_3());
    Serial.print(" | BUTTON U : ");
    Serial.print(Input::BUTTON_U());
    Serial.print(" | BUTTON R : ");
    Serial.print(Input::BUTTON_R());
    Serial.print(" | BUTTON D : ");
    Serial.print(Input::BUTTON_D());
    Serial.print(" | BUTTON L : ");
    Serial.println(Input::BUTTON_L());
}

bool Input::BUTTON_1()
{
    return digitalRead(Input::BUTTON_1_PIN) == Input::NOT_PRESSED;
}

bool Input::BUTTON_2()
{
    return digitalRead(Input::BUTTON_2_PIN) == Input::NOT_PRESSED;
}

bool Input::BUTTON_3()
{
    return digitalRead(Input::BUTTON_3_PIN) == Input::NOT_PRESSED;
}

bool Input::BUTTON_U()
{
    return digitalRead(Input::BUTTON_U_PIN) == Input::NOT_PRESSED;
}

bool Input::BUTTON_R()
{
    return digitalRead(Input::BUTTON_R_PIN) == Input::NOT_PRESSED;
}

bool Input::BUTTON_D()
{
    return digitalRead(Input::BUTTON_D_PIN) == Input::NOT_PRESSED;
}

bool Input::BUTTON_L()
{
    return digitalRead(Input::BUTTON_L_PIN) == Input::NOT_PRESSED;
}