#include "GFXEngine.h"
#include "WiFi.h"

const char *gameXML = "<Main>"
"  <Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"
"    <Layout id='scorePanel' width='16' height='8' x-position='64' y-position='8'>"
"      <Text id='scoreText' x-position='8' y-position='4' value='0-0'/>"
"    </Layout>"
"    <Circle id='ball' radius='1' x-position='64' y-position='32' fill='1'/>"
"    <Rectangle id='paddle1' width='4' height='16' border-radius='2' x-position='4' y-position='32'/>"
"    <Rectangle id='paddle2' width='4' height='16' border-radius='2' x-position='124' y-position='32'/>"
"  </Layout>"
"</Main>";

GFXEngine gfxEngine;

long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
long BUTTON_U_PAST_TIME = 0;
long BUTTON_L_PAST_TIME = 0;
long BUTTON_R_PAST_TIME = 0;
long BUTTON_D_PAST_TIME = 0;
long BUTTON_3_PAST_TIME = 0;
int timeInterval = 200;
int moveInterval = 3;

long BALL_MOVE_PAST_TIME = 0;

#define BUTTON_L 15
#define BUTTON_U 4
#define BUTTON_R 13
#define BUTTON_D 2
#define BUTTON_1 12
#define BUTTON_2 14
#define BUTTON_3 18
#define PRESSED 0
#define NOTPRESSED 1

Rectangle* paddle1;
Rectangle* paddle2;
Circle* ball;

bool gameStarted = false;

int xSpeed = 0;
int ySpeed = 0;

int ballAcl = 2;

void setup()
{
  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);
  pinMode(BUTTON_U, INPUT_PULLUP);
  pinMode(BUTTON_D, INPUT_PULLUP);
  pinMode(BUTTON_R, INPUT_PULLUP);
  pinMode(BUTTON_L, INPUT_PULLUP);
  pinMode(BUTTON_3, INPUT_PULLUP);

  Serial.begin(9600);
  gfxEngine.begin(128, 64, -1, 0x3C);
  gfxEngine.loadXML(gameXML);
  Serial.println("SUCCESSFULLY PARSED");

	paddle1 = gfxEngine.getRectangleByID("paddle1");
	paddle2 = gfxEngine.getRectangleByID("paddle2");
	ball = gfxEngine.getCircleByID("ball");
}

void loop()
{
	movePaddle();
	moveBall();
  gfxEngine.update();
}

void movePaddle() {
	if (digitalRead(BUTTON_U) == PRESSED && millis() - BUTTON_U_PAST_TIME > moveInterval) {
		BUTTON_U_PAST_TIME = millis();
		if (paddle1->getY() - paddle1->getH() / 2 > 0) {
			paddle1->setY(paddle1->getY() - 5);
		}
	}
	else if (digitalRead(BUTTON_D) == PRESSED && millis() - BUTTON_D_PAST_TIME > moveInterval) {
		BUTTON_D_PAST_TIME = millis();
		if (paddle1->getY() + paddle1->getH() / 2 < 63) {
			paddle1->setY(paddle1->getY() + 5);
		}
	}

	if (digitalRead(BUTTON_1) == PRESSED && millis() - BUTTON_1_PAST_TIME > moveInterval) {
		BUTTON_1_PAST_TIME = millis();
		if (paddle2->getY() - paddle2->getH() / 2 > 0) {
			paddle2->setY(paddle2->getY() - 5);
		}
	}
	else if (digitalRead(BUTTON_2) == PRESSED && millis() - BUTTON_2_PAST_TIME > moveInterval) {
		BUTTON_2_PAST_TIME = millis();
		if (paddle2->getY() + paddle2->getH() / 2 < 63) {
			paddle2->setY(paddle2->getY() + 5);
		}
	}
}

void moveBall() {
	if (!gameStarted) {
		gameStarted = true;
		int randomXSpeed = random(0, 1);
		int randomYSpeed = random(0, 1);
		if (randomXSpeed) {
			xSpeed = ballAcl;
		}
		else {
			xSpeed = -ballAcl;
		}

		if (randomYSpeed) {
			ySpeed = ballAcl;
		}

		else {
			ySpeed = -ballAcl;
		}

	}
	if (millis() - BALL_MOVE_PAST_TIME > moveInterval) {
		BALL_MOVE_PAST_TIME = millis();
		ball->setX(ball->getX() + xSpeed);
		ball->setY(ball->getY() + ySpeed);
		if (ball->getY() + ball->getRadius() > 63 || ball->getY() - ball->getRadius() < 1) {
			Serial.println("Vertical bounce");
			ySpeed = -ySpeed;
		}
		if (ball->getX() + ball->getRadius() > 127 && ball->getY() < paddle1) {
			Serial.println("Horizontal bounce");
			xSpeed = -xSpeed;
		}
	}
}