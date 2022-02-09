#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1     //- if your screen has no reset pin, you have to change that value to -1

// Connections of analog joystick pins
const int xPin = A0;
const int yPin = A1;
const int buttonPin = 2;

const long serialPort = 9600;

int xPosition;
int yPosition;
int buttonFlag;

// Refers to the maximum value read from the joystick for each side
const long joyMaxValue = 1023;
const long joyMinValue = 0;

const int shortDelay = 100;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  Serial.begin(serialPort);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Hello World");
  display.display();

}

void loop() {
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonFlag = digitalRead(buttonPin);

  // The received position values ​​must be converted to be displayed on the screen.
  xPosition = map(xPosition, joyMinValue, joyMaxValue, SCREEN_WIDTH - 1, 0);
  yPosition = map(yPosition, joyMinValue, joyMaxValue, SCREEN_HEIGHT - 1, 0);
  
  printJoyValues();

  delay(shortDelay);

  display.writePixel(xPosition, yPosition, WHITE);
  display.display();
}

void printJoyValues() {
  Serial.print("X Position: ");
  Serial.print(xPosition);
  Serial.print(" | Y Position: ");
  Serial.print(yPosition);
  Serial.print(" | Button Flag: ");
  Serial.println(buttonFlag);
}