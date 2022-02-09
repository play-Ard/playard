#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1     //- if your screen has no reset pin, you have to change that value to -1

// Declaration for Joystick
const int xPin = A0;
const int yPin = A1;
const int buttonPin = 2;

const long serialPort = 9600;

int xPosition;
int yPosition;
int buttonFlag;

// Refers to the max and min values can be read from the joystick
const long joyMaxValue = 1023;
const long joyMinValue = 0;

const int shortDelay = 200;

// Refers to currently selected option by user
long currentOption = 0;

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
}

void loop() {
  setXPosition();
  setYPosition();
  setButtonFlag();

  createGameUI();
}

void setXPosition() {
  /* 
  Reads the horizontal position value from the analog 
  joystick and adjusts this value according to the screen width.
  Left side of screen: 0
  Right side of screen: 127
  */
  xPosition = analogRead(xPin);
  xPosition = map(xPosition, joyMinValue, joyMaxValue, SCREEN_WIDTH - 1, 0);
}

void setYPosition() {
  /* 
  Reads the vertical position value from the analog 
  joystick and adjusts this value according to the screen height.
  Top side of screen: 0
  Bottom side of screen: 63
  */
  yPosition = analogRead(yPin);
  yPosition = map(yPosition, joyMinValue, joyMaxValue, SCREEN_HEIGHT - 1, 0);
}

void setButtonFlag() {
  /* 
  Reads the button position value from the analog joystick
  0 - Unpressed
  1 - Pressed
  */
  buttonFlag = abs(digitalRead(buttonPin) - 1);
}

void printJoyValues() {
  /* 
  Prints received joystick values to Serial Port Monitor
  */
  Serial.print("X Position: ");
  Serial.print(xPosition);
  Serial.print(" | Y Position: ");
  Serial.print(yPosition);
  Serial.print(" | Button Flag: ");
  Serial.println(buttonFlag);
}

void createGameUI() {
  /*
  Creates and displays some basic UI elements for game
  */
  int rectW = 120;
  int rectH = 56;
  // Draws centered rectangle   
  drawRectCentered(rectW, rectH, SSD1306_WHITE);

  String titleText = "MILLIONAIRE";
  setCursorHorCenter(titleText, 10);
  display.println(titleText);
  displayOptions();

  display.display();
}

void drawRectCentered(int w, int h, int color, bool fill = false) {
  /*
  Draws a rectangle in the center of the screen according to given parameters
  
  Parameters: {
    w: Width of rectangle
    h: Height of rectangle
    color: Color of rectangle
    fill: Fill the rectangle?
  }
  */

  if (fill) {
    display.fillRect((display.width() - w) / 2, (display.height() - h) / 2, w, h, color);
  }
  else {
    display.drawRect((display.width() - w) / 2, (display.height() - h) / 2, w, h, color);
  }
}

void setCursorHorCenter(String text, long topMargin) {
  /*
  Sets the cursor to print a text aligned horizontal center
  
  Parameters: {
    text: text to be written
    topMargin: distance between text and top side of screen
  }
  */
  int16_t x1;
  int16_t y1;
  uint16_t w;
  uint16_t h;

  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

  display.setCursor((display.width() - w) / 2, topMargin - 1);
}

void setCursorVerCenter(String text, long leftMargin) {
  /*
  Sets the cursor to print a text aligned vertical center
  
  Parameters: {
    text: text to be written
    leftMargin: distance between text and left side of screen
  }
  */
  int16_t x1;
  int16_t y1;
  uint16_t w;
  uint16_t h;

  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

  display.setCursor(leftMargin - 1, (display.height() - h) / 2);
}

void displayOptions() {
  /* 
  Displays some options in the center of the screen
  */
  int n = 4;
  char options[n] = { 'A', 'B', 'C', 'D'};
  String seperator = "  ";

  String sOptions = convertToString(options, n, seperator);
  setCursorHorCenter(sOptions, 30);
  chooseOption(n);

  for (size_t i = 0; i < n; i++)
  {
    if (i == currentOption) {
      display.setTextColor(BLACK, WHITE);
    }
    else {
      display.setTextColor(WHITE, BLACK);
    }

    display.print(options[i]);

    display.setTextColor(WHITE);
    display.print(seperator);
  }
}


void chooseOption(int n) {
  /*
  Chooses a option according to analog joystick position
  
  Parameters: {
    n: Number of options
  }
  */
  if (xPosition == 127) {
    currentOption = (((currentOption + 1) % n) + n) % n;
    delay(shortDelay);
  }

  if (xPosition == 0) {
    currentOption = (((currentOption - 1) % n) + n) % n;
    delay(shortDelay);
  }
}

String convertToString(char* a, int size, String sep)
{
  /*
  Takes an char array and converts into a string 
  (Created for some kind of UI tweak, can be removed later)

  Parameters: {
    a: array to be converted
    size: number of characters in the char array
    sep: string to be inserted between characters
  } 
  */
  int i;
  String s = "";
  for (i = 0; i < size; i++) {
      s = s + a[i];
      if (i != size - 1) {
        s = s + sep;
      }
  }
  return s;
}