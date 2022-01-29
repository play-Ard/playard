#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// Declaration for SSD1306 display connected using software I2C (default case):
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64  
#define OLED_RESET -1     //- if your screen has no reset pin, you have to change that value to -1

int xPin = A0; 
int yPin = A1; 
int buttonPin = 2; 

int xPosition;
int yPosition;
int buttonFlag;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  Serial.begin(9600);
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

  xPosition = map(xPosition, 0, 1023, 0, 128);
  yPosition = map(yPosition, 0, 1023, 0, 32);
  Serial.print("X Pozisyonu: ");
  Serial.print(xPosition);
  Serial.print(" | Y Pozisyonu: ");
  Serial.print(yPosition);
  Serial.print(" | Buton Durum: ");
  Serial.println(buttonFlag);
  delay(100);
  display.writePixel(xPosition, yPosition, WHITE);
  display.display();
}
