#include "GFXEngine.h"


const int row = 4;
const int column = 30;
const char chars[row][column] PROGMEM = {
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.', ',', '_'},
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '.', ',', '_'},
    {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', ']', '^', '_', '{', '|', '}', '~'},
};

uint8_t beginPointer = 0;
uint8_t endPointer = beginPointer + 5;
uint8_t currentPos = 0;
uint8_t list_counter = 0;

GFXEngine gfxEngine;

Text *key1;
Text *key2;
Text *key3;
Text *key4;
Text *key5;
Text *entryText;

Rectangle *underline;

std::vector<Text *> keys;
std::string entryTextValue;

long BUTTON_R_PAST_TIME = 0;
long BUTTON_L_PAST_TIME = 0;
long BUTTON_D_PAST_TIME = 0;
long BUTTON_UP_PAST_TIME = 0;
long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
int timeInterval = 200;

#define BUTTON_R 13
#define BUTTON_L 15
#define BUTTON_UP 12
#define BUTTON_D 32
#define BUTTON_1 33
#define BUTTON_2 27
#define PRESSED 0
#define NOTPRESSED 1

void setup()
{
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_L, INPUT_PULLUP);
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

  Serial.begin(9600);
  gfxEngine.begin(128, 64, -1, 0x3C);
  Serial.println("SUCCESSFULLY PARSED");
  createKeys();
  entryText = gfxEngine.getTextByID("entryText");
  underline = gfxEngine.getRectangleByID("underline");
}

void loop()
{
  highlight();
  changePos();
  changeMenu();
  changeList();
  erase();
  print();
  changeEntryText();
  gfxEngine.update();
}

void createKeys()
{
  key1 = gfxEngine.getTextByID("key1");
  key2 = gfxEngine.getTextByID("key2");
  key3 = gfxEngine.getTextByID("key3");
  key4 = gfxEngine.getTextByID("key4");
  key5 = gfxEngine.getTextByID("key5");

  keys.push_back(key1);
  keys.push_back(key2);
  keys.push_back(key3);
  keys.push_back(key4);
  keys.push_back(key5);

  changeTexts();
}

void highlight()
{
  underline->setX(8 + currentPos * 20);
}

void changePos()
{
  if (digitalRead(BUTTON_R) == PRESSED && millis() - BUTTON_R_PAST_TIME > timeInterval)
  {
    BUTTON_R_PAST_TIME = millis();
    currentPos = (((currentPos + 1) % 5) + 5) % 5;
  }
}

void changeMenu()
{
  if (digitalRead(BUTTON_L) == PRESSED && millis() - BUTTON_L_PAST_TIME > timeInterval)
  {
    BUTTON_L_PAST_TIME = millis();
    beginPointer = (((beginPointer + 5) % column) + column) % column;
    endPointer = beginPointer + 5;
    changeTexts();
  }
}

void changeList()
{
  if (digitalRead(BUTTON_D) == PRESSED && millis() - BUTTON_D_PAST_TIME > timeInterval)
  {
    BUTTON_D_PAST_TIME = millis();
    list_counter++;
    list_counter %= row;
    changeTexts();
  }
}

void print()
{
  Serial.print("U: ");
  Serial.print(digitalRead(BUTTON_UP) == PRESSED);
  Serial.print(" | L: ");
  Serial.print(digitalRead(BUTTON_L) == PRESSED);
  Serial.print(" | R: ");
  Serial.print(digitalRead(BUTTON_R) == PRESSED);
  Serial.print(" | D: ");
  Serial.print(digitalRead(BUTTON_D) == PRESSED);
  Serial.print(" | 1: ");
  Serial.print(digitalRead(BUTTON_1) == PRESSED);
  Serial.print(" | 2: ");
  Serial.println(digitalRead(BUTTON_2) == PRESSED);
}

void changeTexts()
{
  for (size_t i = beginPointer; i < endPointer; i++)
  {
    std::string s;
    s.push_back((char)pgm_read_byte(&(chars[list_counter][i])));
    keys[(i % 5)]->setValue(s);
  }
}

void changeEntryText()
{
  if (digitalRead(BUTTON_UP) == PRESSED && millis() - BUTTON_UP_PAST_TIME > timeInterval)
  {
    BUTTON_UP_PAST_TIME = millis();
    entryTextValue.push_back((char)pgm_read_byte(&(chars[list_counter][beginPointer + currentPos])));
    changeTexts();
    showEntryText();
  }
}

void erase()
{
  if (digitalRead(BUTTON_1) == PRESSED && millis() - BUTTON_1_PAST_TIME > timeInterval)
  {
    BUTTON_1_PAST_TIME = millis();
    if (!entryTextValue.empty())
      entryTextValue.pop_back();
    showEntryText();
  }
}

void showEntryText()
{
  entryText->setValue(entryTextValue);
}