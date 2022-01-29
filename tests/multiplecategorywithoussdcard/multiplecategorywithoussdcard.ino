#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET -1 //- if your screen has no reset pin, you have to change that value to -1

const long serialPort = 9600;
int xPin = A0; 
int yPin = A1; 
int buttonPin = 2; 

int xPosition;
int yPosition;
int buttonFlag;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

// Two dimensional list to hold questions
// Maybe can be converted into HashMaps to categorize topics
const int nRows = 4
const int nColumns = 2
const char *Questions[ rows ][ columns ] = { 
  {'Where is the capital of Turkey?', 'How many legs do chickens have?'},
  {'Father of Python?', 'Which is the moon of jupyter?'},
  {'Which one is the default seperator for CSV files?', 'R or Python? :D'},
  {'Full name of HP?', 'How old was Alan Turing when he died?'},
}

// Index of random category
long randNRow;

const long nShortDelay = 100;
const long nLongDelay = 10000;

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

 void loop(){
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  buttonFlag = digitalRead(buttonPin);
  
  xPosition = map(xPosition, 0, 1023, 0, SCREEN_WIDTH);
  yPosition = map(yPosition, 0, 1023, 0, SCREEN_HEIGHT);
  Serial.print("X Position: ");
  Serial.print(xPosition);
  Serial.print(" | Y Position: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonFlag);
  delay(nShortDelay);

  // Choosing random question for each category
  for (int i = 0; i < nRows; i++)
  {
    randNRow = random(0, nColumns);
    display.println(Questions[i][rand]);
    display.clearDisplay();
    delay(nLongDelay);
    display.display()
  }
  
}