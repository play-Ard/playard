  using namespace std;

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

  // Refers to the maximum value read from the joystick

  const long joyMaxValue = 1023;
  const long joyMinValue = 0;

  const int shortDelay = 200;

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

    createGameScreen();
  }

  long setXPosition() {
    xPosition = analogRead(xPin);
    xPosition = map(xPosition, joyMinValue, joyMaxValue, SCREEN_WIDTH - 1, 0);
  }

  long setYPosition() {
    yPosition = analogRead(yPin);
    yPosition = map(yPosition, joyMinValue, joyMaxValue, SCREEN_HEIGHT - 1, 0);
  }

  long setButtonFlag() {
    buttonFlag = digitalRead(buttonPin);
  }

  void printValues() {
    Serial.print("X Position: ");
    Serial.print(xPosition);
    Serial.print(" | Y Position: ");
    Serial.print(yPosition);
    Serial.print(" | Button Flag: ");
    Serial.println(buttonFlag);
  }

  void createGameScreen() {
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
    display.drawRect((display.width() - w) / 2, (display.height() - h) / 2, w, h, color);
  }

  void setCursorHorCenter(String text, long topMargin) {
    int16_t x1;
    int16_t y1;
    uint16_t w;
    uint16_t h;

    display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

    // display on horizontal and vertical center
    display.setCursor((display.width() - w) / 2, topMargin - 1);
  }

  void setCursorVerCenter(String text, long leftMargin) {
    int16_t x1;
    int16_t y1;
    uint16_t w;
    uint16_t h;

    display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);

    // display on horizontal and vertical center
    display.setCursor(leftMargin - 1, (display.height() - h) / 2);
  }

  void displayOptions() {
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


  int chooseOption(int n) {
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