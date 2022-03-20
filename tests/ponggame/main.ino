#include "GFXEngine.h"
#include "Input.h"

const char *gameXML = "<Main>"
                      "  <Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"
                      "    <Layout id='scorePanel' width='24' height='8' x-position='64' y-position='8'>"
                      "      <Text id='score1Text' x-position='2' y-position='4' value='0'/>"
                      "      <Text id='scoreSep' x-position='12' y-position='4' value='-'/>"
                      "      <Text id='score2Text' x-position='22' y-position='4' value='0'/>"
                      "    </Layout>"
                      "    <Circle id='ball' radius='1' x-position='64' y-position='32' fill='1'/>"
                      "    <Rectangle id='paddle1' width='4' height='16' border-radius='2' x-position='4' y-position='32'/>"
                      "    <Rectangle id='paddle2' width='4' height='16' border-radius='2' x-position='124' y-position='32'/>"
                      "  </Layout>"
                      "</Main>";

GFXEngine gfxEngine;
Input input;

long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
long BUTTON_U_PAST_TIME = 0;
long BUTTON_L_PAST_TIME = 0;
long BUTTON_R_PAST_TIME = 0;
long BUTTON_D_PAST_TIME = 0;
long BUTTON_3_PAST_TIME = 0;
int buttonTimeInterval = 250;
int moveTimeInterval = 5;

long BALL_MOVE_PAST_TIME = 0;

Rectangle *paddle1;
Rectangle *paddle2;
Circle *ball;
Text *score1Text;
Text *score2Text;

int xSpeed = 0;
int ySpeed = 0;
int score1 = 0;
int score2 = 0;

int ballAcl = 2;
int paddleAcl = 2;

void setup()
{
  input.begin();
  Serial.begin(9600);
  gfxEngine.begin(128, 64, -1, 0x3C);
  gfxEngine.loadXML(gameXML);
  Serial.println("SUCCESSFULLY PARSED");

  paddle1 = gfxEngine.getRectangleByID("paddle1");
  paddle2 = gfxEngine.getRectangleByID("paddle2");
  ball = gfxEngine.getCircleByID("ball");
  score1Text = gfxEngine.getTextByID("score1Text");
  score2Text = gfxEngine.getTextByID("score2Text");
  restartGame();
}

void loop()
{
  updateScores();
  movePaddles();
  moveBall();
  gfxEngine.update();
}

void updateScores()
{
  score1Text->setValue(score1);
  score2Text->setValue(score2);
}

void movePaddles()
{
  if (input.BUTTON_U() && millis() - BUTTON_U_PAST_TIME > moveTimeInterval)
  {
    BUTTON_U_PAST_TIME = millis();
    if (paddle1->getY() - paddle1->getH() / 2 > 0)
    {
      paddle1->setY(paddle1->getY() - paddleAcl);
    }
  }
  else if (input.BUTTON_D() && millis() - BUTTON_D_PAST_TIME > moveTimeInterval)
  {
    BUTTON_D_PAST_TIME = millis();
    if (paddle1->getY() + paddle1->getH() / 2 < 63)
    {
      paddle1->setY(paddle1->getY() + paddleAcl);
    }
  }

  if (input.BUTTON_1() && millis() - BUTTON_1_PAST_TIME > moveTimeInterval)
  {
    BUTTON_1_PAST_TIME = millis();
    if (paddle2->getY() - paddle2->getH() / 2 > 0)
    {
      paddle2->setY(paddle2->getY() - paddleAcl);
    }
  }
  else if (input.BUTTON_3() && millis() - BUTTON_3_PAST_TIME > moveTimeInterval)
  {
    BUTTON_3_PAST_TIME = millis();
    if (paddle2->getY() + paddle2->getH() / 2 < 63)
    {
      paddle2->setY(paddle2->getY() + paddleAcl);
    }
  }
}

void moveBall()
{
  if (millis() - BALL_MOVE_PAST_TIME > moveTimeInterval)
  {
    detectCollisions();
    ball->setX(ball->getX() + xSpeed);
    ball->setY(ball->getY() + ySpeed);
    BALL_MOVE_PAST_TIME = millis();
  }
}

void detectCollisions()
{
  if (ball->getY() + ball->getRadius() >= 63 || ball->getY() - ball->getRadius() <= 1)
  {
    Serial.println("Vertical bounce");
    ySpeed = -ySpeed;
  }

  if (ball->getX() - ball->getRadius() < (0 + paddle1->getW()))
  {
    if (ball->getY() <= paddle1->getY() + (paddle1->getH() / 2) && ball->getY() >= paddle1->getY() - (paddle1->getH() / 2))
    {
      Serial.println("Paddle 1 bounce");
      xSpeed = -xSpeed;
      ySpeed = random(-1, 2) * ballAcl + ySpeed;
    }
    else
    {
      score2++;
      restartGame();
    }
  }

  else if (ball->getX() + ball->getRadius() > (128 - paddle2->getW()))
  {
    if (ball->getY() <= paddle2->getY() + (paddle2->getH() / 2) && ball->getY() >= paddle2->getY() - (paddle2->getH() / 2))
    {
      Serial.println("Paddle 2 bounce");
      xSpeed = -xSpeed;
      ySpeed = random(-1, 2) * ballAcl + ySpeed;
    }
    else
    {
      score1++;
      restartGame();
    }
  }
}

void restartGame()
{
  Serial.println("RESTART GAME");
  paddle1->setY(32);
  paddle2->setY(32);
  ball->setX(64);
  ball->setY(32);

  ySpeed = random(0, 2) ? ballAcl : -ballAcl;
  xSpeed = random(0, 2) ? ballAcl : -ballAcl;

  delay(500);
}