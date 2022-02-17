// #include <HTTPClient.h>
// #include <WiFiClient.h>
// #include <ArduinoJson.h>  // to parse the resulting data.
#include <Adafruit_SSD1306.h>

// ---------------------------- VARIABLES ---------------------------------------

// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1     //- if your screen has no reset pin, you have to change that value to -1

// Declaration for Joystick
const int xPin = A0;
const int yPin = A1;
const int buttonPin = 2;

const long serialPort = 9600;
const int shortDelay = 250;
const char* ssid = "Wokwi-GUEST";
const char* password = "";
long EVENT_OPTION_PREVTIME = 0;
long EVENT_OPTION_CURTIME = 0;

// Refers to the max and min values can be read from the joystick
const int p_joyMaxValue = 1023;
const int p_joyMinValue = 0;
const int joyMaxXValue = SCREEN_WIDTH - 1;
const int joyMinXValue = 0;
const int joyMaxYValue = SCREEN_HEIGHT - 1;
const int joyMinYValue = 0;

// Declarations for game mechanics
int currentAnswer = 0;
String questions;
String answers; 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define SCREEN_ADDRESS 0x3C

// -------------------------- END OF VARIABLES ------------------------------------


// -------------------------- CLASS DECLARATIONS ----------------------------------

// class WebInterface {
//   private:
//     WiFiClient wifiClient;
//     HTTPClient httpClient;
//     const long connectionDelay = 200;
//     long ardJsonMemory = 1000;
//   public:
//     void begin(const char* ssid, const char* password) {
//         WiFi.begin(ssid, password);
//         while (!this->isConnected()) {
//             delay(this->connectionDelay);
//         }
//         Serial.println("Connected");
//     }

//     bool isConnected() {
//         return WiFi.status() == WL_CONNECTED;
//     }

//     long request(const char* url) {
//       this->httpClient.begin(this->wifiClient, url);
//       return httpClient.GET();
//     }

//     DynamicJsonDocument getJSON() {
//       DynamicJsonDocument doc(this->ardJsonMemory);
//       deserializeJson(doc, this->httpClient.getString());
//       return doc;
//     }

//     void setArdJsonMemory(long mem) {
//       this->ardJsonMemory = mem;
//     }

//     void release() {
//       this->httpClient.end();
//     }
// };

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
      /*
      Init function for UserInteract class

      Parameters: {
        xPin: Pin to read horizontal position of analog joystick
        yPin: Pin to read vertical position of analog joystick
        buttonPin: Pin to read case of button on the analog joystick
      } 
      */
      this->xPin = xPin;
      this->yPin = yPin;
      this->buttonPin = buttonPin;
    }

    void begin() {
      /*
      Makes some configurations to read the values properly
      */
      pinMode(this->xPin, INPUT);
      pinMode(this->yPin, INPUT);
      pinMode(this->buttonPin, INPUT_PULLUP);
    }

    void readValues() {
      xPosition = analogRead(this->xPin);
      xPosition = map(xPosition, p_joyMinValue, p_joyMaxValue, joyMaxXValue, joyMinXValue);
      
      yPosition = analogRead(this->yPin);
      yPosition = map(yPosition, p_joyMinValue, p_joyMaxValue, joyMaxYValue, joyMinYValue);

      buttonFlag = abs(digitalRead(this->buttonPin) - 1);
    }

    void print() {
      Serial.print("X Position: ");
      Serial.print(this->xPosition);
      Serial.print(" | Y Position: ");
      Serial.print(this->yPosition);
      Serial.print(" | Button Flag: ");
      Serial.println(this->buttonFlag);
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
      return this->getXPosition() == joyMaxXValue;
    }
    
    bool LEFT () {
      return this->getXPosition() == joyMinXValue;
    }

    bool UP () {
      return this->getYPosition() == joyMinYValue;
    }

    bool DOWN () {
      return this->getYPosition() == joyMaxYValue;
    }
};

class Frame {
  private:
    int w;
    int h;
    int x;
    int y;
    bool border = false;
  public:
    Frame(int w, int h, int x, int y) {
      /* 
      Initialization function of Frame
      
      Parameters: {
        w: Width of frame
        h: Height of frame
        x: Horizontal start position of frame (It will be automatically centered in x-axis when x value is negative)
        y: Vertical start position of frame (It will be automatically centered in y-axis when y value is negative)
      }
      */
      this->w = w;
      this->h = h;
      if (x < 0) {
        this->x = x;
      } else {
        this->x = (SCREEN_WIDTH - x) / 2;
      }

      if (y < 0) {
        this->y = y;
      } else {
        this->y = (SCREEN_HEIGHT - y) / 2;
      }
    }

    int getW() {
      return this->w;
    }
    
    int getH() {
      return this->h;
    }

    int getX() {
      return this->x;
    }

    int getY() {
      return this->y;
    }

    bool haveBorder() {
      return this->border;
    }

    void toggleBorder() {
      this->border = !this->border;
    }
};

// ----------------------- END OF CLASS DECLARATIONS ----------------------------


// ----------------------- INITILIZATIONS ---------------------------------------

UserInteract userInteract(xPin, yPin, buttonPin);
// WebInterface webInterface;
Frame MAINFRAME = Frame(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);

// ----------------------- END OF INITILIZATIONS --------------------------------


void setup() {
  Serial.begin(serialPort);
  userInteract.begin();
  // webInterface.begin(ssid, password);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // long httpCode = webInterface.request("http://play-ard.herokuapp.com/questions/");
  // if (webInterface.isConnected()) {
  //   if (httpCode > 0) {
  //     DynamicJsonDocument jsondoc = webInterface.getJSON();
  //     String answers = jsondoc["answers"];
  //   }
  // }
  // webInterface.release();
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
    if (i == currentAnswer) {
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

  EVENT_OPTION_CURTIME = millis();

  if (userInteract.BUTTON()) {
    String text = "SELECTED: " + String(currentAnswer);
    setCursorHorCenter(text, 50);
    display.print(text);
  }

  else if (userInteract.RIGHT()) {
    if (EVENT_OPTION_CURTIME - EVENT_OPTION_PREVTIME > shortDelay) {
      currentAnswer = (((currentAnswer + 1) % n) + n) % n;
      EVENT_OPTION_PREVTIME = millis();
    }
  }

  else if (userInteract.LEFT()) {
    if (EVENT_OPTION_CURTIME - EVENT_OPTION_PREVTIME > shortDelay) {
      currentAnswer = (((currentAnswer - 1) % n) + n) % n;
      EVENT_OPTION_PREVTIME = millis();
    }
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