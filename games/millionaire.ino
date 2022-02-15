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

// Refers to the max and min values can be read from the joystick
const long joyMaxValue = 1023;
const long joyMinValue = 0;

const int shortDelay = 200;

// Refers to currently selected option by user
int currentOption = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C


// Class declarations
class UserInteract
{
  private:
    int xPin;
    int yPin;
    int buttonPin;
    
    long xPosition;
    long yPosition;
    int buttonFlag;

  public:
    UserInteract (int xPin, int yPin, int buttonPin){
      this->xPin = xPin;
      this->yPin = yPin;
      this->buttonPin = buttonPin;
    }

    void begin() {
      pinMode(this->xPin, INPUT);
      pinMode(this->yPin, INPUT);
      pinMode(this->buttonPin, INPUT_PULLUP);
    }

    void readValues() {
      xPosition = analogRead(this->xPin);
      xPosition = map(xPosition, joyMinValue, joyMaxValue, SCREEN_WIDTH - 1, 0);
      
      yPosition = analogRead(this->yPin);
      yPosition = map(yPosition, joyMinValue, joyMaxValue, SCREEN_HEIGHT - 1, 0);

      buttonFlag = abs(digitalRead(this->buttonPin) - 1);
    }

    void print() {
      Serial.print("X Position: ");
      Serial.print(this->getXPosition());
      Serial.print(" | Y Position: ");
      Serial.print(this->getYPosition());
      Serial.print(" | Button Flag: ");
      Serial.println(this->getButtonFlag());
    }
    
    long getXPosition() {
      return this->xPosition;
    }
    
    long getYPosition() {
      return this->yPosition;
    }
    
    int getButtonFlag() {
      return this->buttonFlag;
    }

    bool BUTTON () {
      return this->getButtonFlag() == 1;
    }

    bool RIGHT () {
      return this->getXPosition() == SCREEN_WIDTH - 1;
    }
    
    bool LEFT () {
      return this->getXPosition() == 0;
    }

    bool UP () {
      return this->getYPosition() == 0;
    }

    bool DOWN () {
      return this->getYPosition() == SCREEN_HEIGHT - 1;
    }
};

UserInteract userInteract(xPin, yPin, buttonPin);

void setup() {
  Serial.begin(serialPort);
  userInteract.begin();
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  userInteract.readValues();
  userInteract.print();
  createGameUI();
}

void createGameUI() {
  /*
  Creates and displays some basic UI elements for game
  */
  display.clearDisplay();
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

void drawRectCentered(int w, int h, int color) {
/*
  Draws a unfilled rectangle in the center of the screen according to given parameters
  
  Parameters: {
    w: Width of rectangle
    h: Height of rectangle
    color: Color of rectangle
  }
  */

  display.drawRect((display.width() - w) / 2, (display.height() - h) / 2, w, h, color);
}

void drawRectCentered(int w, int h, int color, bool fill) {
  /*
  Draws a rectangle in the center of the screen according to given parameters
  
  Parameters: {
    w: Width of rectangle
    h: Height of rectangle
    color: Color of rectangle
    (optional)fill: Fill the rectangle? (default: false)
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
  Displays some options horizontally centered
  */
  int n = 4;
  char options[n] = { 'A', 'B', 'C', 'D'};
  String seperator = "  ";

  String sOptions = convertToString(options, n, seperator);
  chooseOption(n);
  setCursorHorCenter(sOptions, 30);

  for (size_t i = 0; i < n; i++)
  {
    if (i == currentOption) {
      display.setTextColor(BLACK, WHITE);
    }
    else {
      display.setTextColor(WHITE, BLACK);
    }
    display.print(options[i]);

    display.setTextColor(WHITE, BLACK);
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

  if (userInteract.BUTTON()) {
    String text = "SELECTED: " + String(currentOption);
    setCursorHorCenter(text, 100);
    display.print(text);
    Serial.println(text);
  }

  else if (userInteract.RIGHT()) {
    currentOption = (((currentOption + 1) % n) + n) % n;
    delay(shortDelay);
  }

  else if (userInteract.LEFT()) {
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