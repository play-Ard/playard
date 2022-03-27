#include "GFXEngine.h"
#include "Input.h"

GFXEngine gfxEngine;
Input input;

#define M_PI 3.14159265358979323846 /* pi */

long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
long BUTTON_U_PAST_TIME = 0;
long BUTTON_L_PAST_TIME = 0;
long BUTTON_R_PAST_TIME = 0;
long BUTTON_D_PAST_TIME = 0;
long BUTTON_3_PAST_TIME = 0;
long MOVE_CURSOR_PAST_TIME = 0;
long MOVE_BALL_PAST_TIME = 0;

long moveCursorInterval = 2;
long moveBallInterval = 2;

const char* game_xml = 
"<Main>"
"  <Layout id='mainLayout' x-position='64' y-position='32' width='128' height='64'>"
""
"    <Circle id='ball' x-position='12' y-position='56' radius='3' />"
""
"    <Layout id='barPanel' x-position='48' y-position='6' width='64' height='4' visibility='0'>"
""
"      <Rectangle id='bar' x-position='32' y-position='2' width='64' height='2' />"
""
"      <Circle id='cursor' x-position='16' y-position='2' radius='2' />"
""
"    </Layout>"
""
"    <Layout id='targetLayout' x-position='126' y-position='32' width='4' height='64'>"
""
"      <Rectangle id='wall' x-position='2' y-position='32' width='4' height='128' fill='1'/>"
""
"      <Rectangle id='target' x-position='2' y-position='24' width='4' height='20' color='0' fill='1'/>"
""
"    </Layout>"
""
"  </Layout>"
"</Main>"
;

Point *startPoint;
Point *endPoint;
Circle *ball;
Circle *cursor;
Rectangle *bar;
Layout *barPanel;

int power = 40;
float angle = 0;

int cursorDirection = 1;
int cursorSpeed = 2;
const float speedCoef = .15;
const float lineLengthCoef = .4;

float ballXSpeed = 0;
float ballYSpeed = 0;
float xLoc;
float yLoc;
float gravity = .15;

int currentState = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("SUCCESSFULY BEGIN");
  gfxEngine.begin(128, 64, -1, 0x3C);
  gfxEngine.loadXML(game_xml);
  Serial.println("SUCCESSFULLY PARSED");
  input.begin();

  startPoint = new Point(0, 0);
  endPoint = new Point(0, 0);
  ball = gfxEngine.getCircleByID("ball");
  cursor = gfxEngine.getCircleByID("cursor");
  bar = gfxEngine.getRectangleByID("bar");
  barPanel = gfxEngine.getLayoutByID("barPanel");
}

void loop()
{
  if (currentState == 0)
  {
    getAngle();
    changeLine();
    changeCurrentState();
  }
  else if (currentState == 1)
  {
    getPower();
    changeLine();
    changeCurrentState();
  }
  else if (currentState == 2)
  {
    throwBall();
  }
  gfxEngine.update();
}

void changeLine()
{
  int x1 = 12;
  int y1 = 56;
  int x2 = x1 + power * cos(angle) * lineLengthCoef;
  int y2 = y1 - power * sin(angle) * lineLengthCoef;

  startPoint->setX(x1);
  startPoint->setY(y1);

  endPoint->setX(x2);
  endPoint->setY(y2);

  gfxEngine.display.drawLine(startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY(), 1);
}

void getPower()
{
  moveCursor();
  power = cursor->getX() - (bar->getX() - bar->getW() / 2);
}

void getAngle()
{
  moveCursor();
  angle = ((float)cursor->getX() - (float)(bar->getX() - bar->getW() / 2)) / (float)(bar->getW());
  angle *= M_PI / 2.5;
  Serial.print("ANGLE : ");
  Serial.println(angle);
}

void moveCursor()
{
  if (millis() - MOVE_CURSOR_PAST_TIME > moveCursorInterval)
  {
    if (cursor->getX() == (bar->getX() - (bar->getW() / 2)))
    {
      cursorDirection = 1;
    }
    if (cursor->getX() == (bar->getX() + (bar->getW() / 2)))
    {
      cursorDirection = -1;
    }

    cursor->setX(cursor->getX() + cursorDirection * cursorSpeed);

    MOVE_CURSOR_PAST_TIME = millis();
  }
}

void changeCurrentState()
{
  if (input.BUTTON_1())
  {
    if (currentState == 1)
    {
      barVisibility(0);
      setSpeeds();
    }
    else
    {
      barVisibility(1);
    }

    currentState = (currentState + 1) % 3;
    delay(200);
  }
}

void barVisibility(bool visibility)
{
  barPanel->setVisibility(visibility);
}

void setSpeeds() {
  ballXSpeed = power * cos(angle) * speedCoef;
  ballYSpeed = power * sin(angle) * speedCoef;
  xLoc = ball->getX();
  yLoc = ball->getY();
}

void throwBall()
{
  if (millis() - MOVE_BALL_PAST_TIME > moveBallInterval)
  {
    float xAcl = 0;
    float yAcl = gravity;

    ballXSpeed = ballXSpeed + xAcl;
    ballYSpeed = ballYSpeed - yAcl;

    xLoc = xLoc + ballXSpeed;
    yLoc = yLoc - ballYSpeed;

    ball->setX(xLoc);
    ball->setY(yLoc);
    MOVE_BALL_PAST_TIME = millis();

    Serial.print("Vertical speed: ");
    Serial.print(ballYSpeed);
    Serial.print("Horizontal speed: ");
    Serial.println(ballXSpeed);
  }
}