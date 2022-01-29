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
int butonPin = 2; 

int xPozisyon;
int yPozisyon;
int butonDurum;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define SCREEN_ADDRESS 0x3C

void setup() {

  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(butonPin, INPUT_PULLUP);

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
  xPozisyon = analogRead(xPin);
  yPozisyon = analogRead(yPin);
  butonDurum = digitalRead(butonPin);

  xPozisyon = map(xPozisyon, 0, 1023, 0, 128);
  yPozisyon = map(yPozisyon, 0, 1023, 0, 32);
  Serial.print("X Pozisyonu: ");
  Serial.print(xPozisyon);
  Serial.print(" | Y Pozisyonu: ");
  Serial.print(yPozisyon);
  Serial.print(" | Buton Durum: ");
  Serial.println(butonDurum);
  delay(100);
  display.writePixel(xPozisyon, yPozisyon, WHITE);
  display.display();
}
