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
const char *Listem[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem2[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem3[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem4[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem5[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem6[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem7[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem8[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem9[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem10[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem11[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem12[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem13[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem14[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem15[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem16[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem17[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem18[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem19[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem20[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem21[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem22[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem23[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};
const char *Listem24[] = {"Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?", "Falan filan nedir?"};

long randNumber;

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

  randNumber = random(0, 4);
  display.println(Listem[randNumber]);
  display.clearDisplay();
  delay(10000);
  display.display();
  display.println(Listem7[randNumber]);
  delay(10000);
   display.clearDisplay();
  delay(10000);
  display.display();
  display.println(Listem2[randNumber]);
  delay(10000);
   display.clearDisplay();
  delay(10000);
  display.display();
  display.println(Listem3[randNumber]);
  delay(10000);
   display.clearDisplay();
  delay(10000);
  display.display();
  display.println(Listem4[randNumber]);
  delay(10000);
   display.clearDisplay();
  delay(10000);
  display.display();
  display.println(Listem5[randNumber]);
  delay(10000);
   display.clearDisplay();
  delay(10000);
  display.display();
  display.println(Listem6[randNumber]);
  delay(10000);
}
