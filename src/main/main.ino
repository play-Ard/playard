#include "GFXEngine.h"
#include "Input.h"
#include "games/Games.h"

const char *menuXML = "<Main>"
                      "    <Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"
                      "        <Layout id='menuLayout' width='48' height='32' x-position='100' y-position='32'>"
                      "            <Text id='menuElement1' value='Games' x-position='4' y-position='0' h-align='-1'/>"
                      "            <Text id='menuElement2' value='Options' x-position='4' y-position='12' h-align='-1'/>"
                      "            <Text id='menuElement1' value='Info' x-position='4' y-position='24' h-align='-1'/>"
                      "            <Circle id='cursor' x-position='0' y-position='3' radius='1' fill='1'/>"
                      "        </Layout>"
                      "</Layout>"
                      "</Main>";
GFXEngine gfxEngine;
Input input;

const int GAMES_LEN = 3;
std::vector<Game *> games = {
    new ThrowBall(&gfxEngine, &input),
    new Pong(&gfxEngine, &input),
    new Millionaire(&gfxEngine, &input),
};

int currentGame = 0;
int currentActivity = 0;

int changeMenuInterval = 200;

bool MENU_OPEN = true;

void setup()
{
  input.begin();
  Serial.begin(9600);
  gfxEngine.begin(128, 64, -1, 0x3C);
  gfxEngine.loadXML(menuXML);
  Serial.println("SUCCESSFULLY PARSED");
}

void loop()
{
  if (MENU_OPEN)
  {
    changeCurrentImage();
    changeMenu();
  }
  else
  {
    games[currentGame]->onUpdate();
    MENU_OPEN = !games[currentGame]->getActivity();
    if (!MENU_OPEN) {
      gfxEngine.loadXML(menuXML);
    }
  }
  Serial.println(currentGame);
  input.print();
  gfxEngine.update();
}

void changeMenu()
{
  if (input.BUTTON_1() && millis() - input.BUTTON_1_PREV_T() > changeMenuInterval)
  {
    MENU_OPEN = false;
    games[currentGame]->setActivity(1);
    games[currentGame]->onCreate();
    gfxEngine.loadXML(games[currentGame]->getXML());
    games[currentGame]->onStart();
    input.BUTTON_1_PREV_T(millis());
  }
}

void changeCurrentImage()
{
  if (input.BUTTON_U() && millis() - input.BUTTON_U_PREV_T() > changeMenuInterval)
  {
    currentGame = ((currentGame - 1) + GAMES_LEN) % GAMES_LEN;
    input.BUTTON_U_PREV_T(millis());
  }
  else if (input.BUTTON_D() && millis() - input.BUTTON_D_PREV_T() > changeMenuInterval)
  {
    currentGame = (currentGame + 1) % GAMES_LEN;
    input.BUTTON_D_PREV_T(millis());
  }

  gfxEngine.display.drawBitmap(4, 8, games[currentGame]->getLogo(), 64, 48, 1);
}