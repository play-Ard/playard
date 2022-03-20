#include "GFXEngine.h"
#include "WiFi.h"

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
                          "<Layout id='ssidLayout' width='96' height='16' x-position='64' y-position='12'>"
                          "<Text id='ssidText' x-position='48' y-position='8' value='Zyxel' h-align='0'/>"
                          "</Layout>"
                          "<Layout id='textLayout' width='96' height='16' x-position='64' y-position='32'>"
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

const char *connectScreenXML = "<Main><Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"
                               "<Text id='statusText' x-position='64' y-position='32' value='PLACEHOLDER'/>"
                               "</Layout></Main>";
GFXEngine gfxEngine;

const int row = 4;
const int column = 30;
const char chars[row][column] PROGMEM = {
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.', ',', '_'},
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '.', ',', '_'},
    {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'},
    {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', ']', '^', '_', '{', '|', '}', '~'},
};

uint8_t beginPointer = 0;
uint8_t currentPos = 0;
uint8_t list_counter = 0;

Text *key1;
Text *key2;
Text *key3;
Text *key4;
Text *key5;
Text *entryText;
Text *statusText;

Text *ssidText;
int currentSsid = 0;
int ssidChanger;

Rectangle *underline;

std::vector<Text *> keys;
std::string password;

long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
long BUTTON_U_PAST_TIME = 0;
long BUTTON_L_PAST_TIME = 0;
long BUTTON_R_PAST_TIME = 0;
long BUTTON_D_PAST_TIME = 0;
long BUTTON_3_PAST_TIME = 0;
int timeInterval = 200;

#define BUTTON_L 15
#define BUTTON_U 12
#define BUTTON_R 13
#define BUTTON_D 32
#define BUTTON_1 33
#define BUTTON_2 27
#define BUTTON_3 35
#define PRESSED 0
#define NOTPRESSED 1

bool KEYBOARD_ACTIVITY = false;
bool STATUS_ACTIVITY = false;
bool MENU_ACTIVITY = true;

const int menuCount = 7;
const char *options[menuCount] = {"PROFILE", "BRIGHTNESS", "Wi-Fi", "WALLPAPER", "SOUND", "DONATE", "TURN OFF"};
uint8_t beginCursor = 0;
uint8_t cursorPos = 0;

Text *text1;
Text *text2;
Text *text3;
Text *text4;
Circle *cursor;

std::vector<Text *> texts;

void setup()
{
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_U, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_L, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);
  WiFi.mode(WIFI_STA);
  ssidChanger = WiFi.scanNetworks();

  Serial.begin(9600);
  gfxEngine.begin(128, 64, -1, 0x3C);
  gfxEngine.loadXML(menuXML);
  Serial.println("SUCCESSFULLY PARSED");

  pullComponents();
}

void loop()
{
  if (MENU_ACTIVITY)
  {
    showMenu();
    selectMenu();
    readBUTTON1();
  }

  else if (KEYBOARD_ACTIVITY)
  {
    changeCurrentSsid();
    highlight();
    changePos();
    changeMenu();
    changeList();
    erase();
    changeEntryText();
    connectWifi();
    // closeKeyboard();
  }

  else if (STATUS_ACTIVITY)
  {
    changeConnectStatus();
  }
  print();
  gfxEngine.update();
}

void pullComponents()
{
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

void showMenu()
{
  for (size_t i = 0; i < 4; i++)
  {
    texts[i]->setValue(options[i + beginCursor]);
  }
}

void readBUTTON1()
{
  if (digitalRead(BUTTON_D) == PRESSED && millis() - BUTTON_D_PAST_TIME > timeInterval)
  {
    BUTTON_D_PAST_TIME = millis();
    cursorPos = (cursorPos + 1) % menuCount;
    changeCursorPosition();
  }
}

void changeCursorPosition()
{
  if (cursorPos < 4)
  {
    cursor->setY(11 + cursorPos * 14);
  }
  else
  {
    cursor->setY(11 + 3 * 14);
    beginCursor++;
  }

  if (cursorPos == 0)
    beginCursor = 0;
}

void selectMenu()
{
  if (digitalRead(BUTTON_1) == PRESSED && millis() - BUTTON_1_PAST_TIME > timeInterval)
  {
    BUTTON_1_PAST_TIME = millis();
    if (MENU_ACTIVITY && cursorPos == 2)
    {

      KEYBOARD_ACTIVITY = true;
      MENU_ACTIVITY = false;
      gfxEngine.loadXML(keyboardXML);
      createKeys();
      ssidText = gfxEngine.getTextByID("ssidText");
    }
  }
}

void closeKeyboard()
{
  if (digitalRead(BUTTON_2) == PRESSED && millis() - BUTTON_2_PAST_TIME > timeInterval)
  {
    BUTTON_2_PAST_TIME = millis();
    if (KEYBOARD_ACTIVITY)
    {
      MENU_ACTIVITY = true;
      KEYBOARD_ACTIVITY = false;
      texts.clear();
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
  Serial.print(digitalRead(BUTTON_2) == PRESSED);
  Serial.print(" | U: ");
  Serial.print(digitalRead(BUTTON_U) == PRESSED);
  Serial.print(" | D: ");
  Serial.print(digitalRead(BUTTON_D) == PRESSED);
  Serial.print(" | R: ");
  Serial.print(digitalRead(BUTTON_R) == PRESSED);
  Serial.print(" | L: ");
  Serial.println(digitalRead(BUTTON_L) == PRESSED);
}

void createKeys()
{
  key1 = gfxEngine.getTextByID("key1");
  key2 = gfxEngine.getTextByID("key2");
  key3 = gfxEngine.getTextByID("key3");
  key4 = gfxEngine.getTextByID("key4");
  key5 = gfxEngine.getTextByID("key5");

  underline = gfxEngine.getRectangleByID("underline");
  entryText = gfxEngine.getTextByID("entryText");

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

void changeTexts()
{
  for (size_t i = beginPointer; i < beginPointer + 5; i++)
  {
    std::string s;
    s.push_back((char)pgm_read_byte(&(chars[list_counter][i])));
    keys[(i % 5)]->setValue(s);
  }
}

void changeEntryText()
{
  if (digitalRead(BUTTON_U) == PRESSED && millis() - BUTTON_U_PAST_TIME > timeInterval)
  {
    BUTTON_U_PAST_TIME = millis();
    password.push_back((char)pgm_read_byte(&(chars[list_counter][beginPointer + currentPos])));
    changeTexts();
    showEntryText();
  }
}

void erase()
{
  if (digitalRead(BUTTON_1) == PRESSED && millis() - BUTTON_1_PAST_TIME > timeInterval)
  {
    BUTTON_1_PAST_TIME = millis();
    if (!password.empty())
      password.pop_back();
    showEntryText();
  }
}

void showEntryText()
{
  entryText->setValue(password);
}

void changeCurrentSsid()
{

  if (digitalRead(BUTTON_2) == PRESSED && millis() - BUTTON_2_PAST_TIME > timeInterval)
  {
    BUTTON_2_PAST_TIME = millis();
    currentSsid = (currentSsid + 1) % ssidChanger;

    ssidText->setValue(std::string(WiFi.SSID(currentSsid).c_str()));
  }
}

void connectWifi()
{

  if (digitalRead(BUTTON_3) == PRESSED && millis() - BUTTON_3_PAST_TIME > timeInterval)
  {
    BUTTON_3_PAST_TIME = millis();

    WiFi.begin(ssidText->getValue().c_str(), password.c_str());
    gfxEngine.loadXML(connectScreenXML);
    statusText = gfxEngine.getTextByID("statusText");
    STATUS_ACTIVITY = true;
    KEYBOARD_ACTIVITY = false;
  }
}

void changeConnectStatus()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    statusText->setValue("CONNECTING..");
  }
  else if (WiFi.status() == WL_CONNECTED)
  {
    statusText->setValue("CONNECTED");
  }
}
