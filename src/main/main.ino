#include "GFXEngine.h"

const char *menuXML = "<Main><Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"
                      "<Layout id='menuLayout' width='112' height='56' x-position='64' y-position='32'>"
                      "<Layout id='menuElement1' width='112' height='14' x-position='56' y-position='11'>"
                      "<Rectangle id='rect1' width='112' height='14' x-position='56' y-position='7' border-radius='4'/>"
                      "<Text id='text1' x-position='56' y-position='7'/>"
                      "</Layout>"
                      "<Layout id='menuElement2' width='112' height='14' x-position='56' y-position='25'>"
                      "<Rectangle id='rect2' width='112' height='14' x-position='56' y-position='7' border-radius='4'/>"
                      "<Text id='text2' x-position='56' y-position='7'/>"
                      "</Layout>"
                      "<Layout id='menuElement3' width='112' height='14' x-position='56' y-position='39'>"
                      "<Rectangle id='rect3' width='112' height='14' x-position='56' y-position='7' border-radius='4'/>"
                      "<Text id='text3' x-position='56' y-position='7'/>"
                      "</Layout>"
                      "<Layout id='menuElement4' width='112' height='14' x-position='56' y-position='53'>"
                      "<Rectangle id='rect4' width='112' height='14' x-position='56' y-position='7' border-radius='4'/>"
                      "<Text id='text4' x-position='56' y-position='7'/>"
                      "</Layout>"
                      "<Circle id='cursor' x-position='100' y-position='11' radius='3' fill='1'/>"
                      "</Layout>"
                      "</Layout></Main>";

const char *keyboardXML = "<Main><Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"
                          "<Layout id='textLayout' width='96' height='16' x-position='64' y-position='12'>"
                          "<Rectangle id='textBorder' width='96' height='16' x-position='48' y-position='8'/>"
                          "<Text id='entryText' x-position='48' y-position='8' value='' h-align='0'/>"
                          "</Layout>"
                          "<Layout id='kayboardLayout' width='96' height='16' x-position='64' y-position='52'>"
                          "<Rectangle id='underline' width='8' height='1'  x-position='8' y-position='16'/>"
                          "<Text id='key1' x-position='8' y-position='8'  value='A' />"
                          "<Text id='key2' x-position='28' y-position='8' value='B' />"
                          "<Text id='key3' x-position='48' y-position='8' value='C' />"
                          "<Text id='key4' x-position='68' y-position='8' value='D' />"
                          "<Text id='key5' x-position='88' y-position='8' value='E' />"
                          "</Layout>"
                          "</Layout></Main>";

GFXEngine gfxEngine;

long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
int timeInterval = 200;

#define BUTTON_1 4
#define BUTTON_2 0
#define PRESSED 0
#define NOTPRESSED 1

bool KEYBOARD_ACTIVITY = false;
bool MENU_ACTIVITY = true;

const int n = 7;
const char * options[n] = {"PROFILE", "BRIGHTNESS", "Wi-Fi", "WALLPAPER", "SOUND", "DONATE", "TURN OFF"};
uint8_t beginPointer = 0;
uint8_t cursorPos = 0;

Text *text1;
Text *text2;
Text *text3;
Text *text4;
Circle *cursor;

std::vector<Text*> texts;

void setup()
{
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

  Serial.begin(9600);
  gfxEngine.begin(128, 64, -1, 0x3C);
  gfxEngine.loadXML(menuXML);
  Serial.println("SUCCESSFULLY PARSED");

  pullComponents();
}

void loop()
{
  if (MENU_ACTIVITY) {
    showMenu();
    selectMenu();
    readBUTTON1();
  }
  
  else if (KEYBOARD_ACTIVITY) {
    closeKeyboard();
  }
  print();
  gfxEngine.update();
}

void pullComponents() {
  text1 = gfxEngine.getTextByID("text1");
  text2 = gfxEngine.getTextByID("text2");
  text3 = gfxEngine.getTextByID("text3");
  text4 = gfxEngine.getTextByID("text4");

  texts.push_back(text1); 
  texts.push_back(text2); 
  texts.push_back(text3); 
  texts.push_back(text4); 

  cursor = gfxEngine.getCircleByID("cursor");
}

void showMenu() {
  for (size_t i = 0; i < 4; i++)
  {
    texts[i]->setValue(options[i + beginPointer]);
  }
}

void readBUTTON1() {
  if (digitalRead(BUTTON_1) == PRESSED && millis() - BUTTON_1_PAST_TIME > timeInterval)
  {
    BUTTON_1_PAST_TIME = millis();
    cursorPos = (cursorPos + 1) % n;
    changeCursorPosition();
  }
}

void changeCursorPosition() {
    if (cursorPos < 4) {
      cursor->setY(11 + cursorPos * 14);
    }
    else {
      cursor->setY(11 + 3 * 14);
      beginPointer++;
    }

    if (cursorPos == 0) beginPointer = 0;
}


void selectMenu() {
  if (digitalRead(BUTTON_2) == PRESSED && millis() - BUTTON_2_PAST_TIME > timeInterval)
  {
    BUTTON_2_PAST_TIME = millis();
    if (MENU_ACTIVITY && cursorPos == 2) {
      KEYBOARD_ACTIVITY = true;
      MENU_ACTIVITY = false;
      texts.clear();
      gfxEngine.loadXML(keyboardXML);
    }
  }
}

void closeKeyboard() {
  if (digitalRead(BUTTON_2) == PRESSED && millis() - BUTTON_2_PAST_TIME > timeInterval)
  {
    BUTTON_2_PAST_TIME = millis();
    if (KEYBOARD_ACTIVITY) {
      MENU_ACTIVITY = true;
      KEYBOARD_ACTIVITY = false;
      gfxEngine.loadXML(menuXML);
      pullComponents();
      changeCursorPosition();
    }
  }
}

void print()
{
  Serial.print(" | 1: ");
  Serial.print(digitalRead(BUTTON_1) == PRESSED);
  Serial.print(" | 2: ");
  Serial.println(digitalRead(BUTTON_2) == PRESSED);
}
