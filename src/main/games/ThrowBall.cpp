#include "../core/PlayardCore.h"

class ThrowBall : public Game
{
public:
    const unsigned char logo[384] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xfe, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x9f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x8f, 0x00, 0x00, 0x00,
        0xff, 0xf3, 0xfe, 0x0f, 0x8f, 0x1f, 0x03, 0xe0, 0xff, 0xf3, 0xff, 0x0f, 0x8f, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xdf, 0x0f, 0x8f, 0x1f, 0x03, 0xe0, 0x0f, 0x03, 0xcf, 0x0f, 0x8f, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xcf, 0x0f, 0x8f, 0x1f, 0x03, 0xe0, 0x0f, 0x03, 0xcf, 0x0f, 0x8f, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xdf, 0x0f, 0x8f, 0x1f, 0x03, 0xe0, 0x0f, 0x03, 0xff, 0x0f, 0x8f, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xff, 0x0f, 0x8f, 0x1f, 0x03, 0xe0, 0x0f, 0x03, 0xdf, 0x00, 0x00, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xcf, 0x00, 0x00, 0x1f, 0x03, 0xe0, 0x0f, 0x03, 0xcf, 0x00, 0x00, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xcf, 0x00, 0x00, 0x1f, 0x03, 0xe0, 0x0f, 0x03, 0xdf, 0x01, 0xf8, 0x1f, 0x03, 0xe0,
        0x0f, 0x03, 0xff, 0x01, 0xf8, 0x1f, 0xfb, 0xff, 0x0f, 0x03, 0xfe, 0x01, 0xfc, 0x1f, 0xfb, 0xff,
        0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    const char *xml =
        "<Main>"
        "  <Layout id='mainLayout' x-position='64' y-position='32' width='128' height='64'>"
        ""
        "    <Text id='scoreText' x-position='10' y-position='10' value='0'/>"
        ""
        "    <Circle id='ball' x-position='12' y-position='56' radius='3' />"
        ""
        "    <Layout id='barPanel' x-position='52' y-position='10' width='64' height='4' visibility='0'>"
        ""
        "      <Rectangle id='bar' x-position='32' y-position='2' width='64' height='2' />"
        ""
        "      <Circle id='cursor' x-position='16' y-position='2' radius='2' />"
        ""
        "    </Layout>"
        ""
        "    <Rectangle id='wall' x-position='126' y-position='32' width='4' height='64' fill='1'/>"
        "      "
        "    <Rectangle id='target' x-position='126' y-position='24' width='4' height='20' color='0' fill='1'/>"
        ""
        "  </Layout>"
        "</Main>";

    GFXEngine *gfxEngine;
    Input *input;

    int pi = 3.141593; /* pi */

    int SCREEN_WIDTH = 127;
    int SCREEN_HEIGHT = 63;

    long MOVE_CURSOR_PAST_TIME = 0;
    long MOVE_TARGET_PAST_TIME = 0;
    long MOVE_BALL_PAST_TIME = 0;
    long COLLISION_PAST_TIME = 0;

    long moveCursorInterval = 2;
    long moveBallInterval = 2;
    long moveTargetInterval = 20;
    long collisionInterval = 100;

    Point *startPoint;
    Point *endPoint;
    Circle *ball;
    Circle *cursor;
    Rectangle *bar;
    Layout *barPanel;
    Rectangle *target;
    Text *scoreText;

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
    int score = 0;
    float targetSpeed = 0;
    float targetMoveDirection = 1;

    int currentState = 0;

    int TARGET_HEIGHT_UPPER_BOUND = 28;
    int TARGET_HEIGHT_LOWER_BOUND = 14;
    int TARGET_POSITION_LOWER_BOUND = 16;
    int TARGET_POSITION_UPPER_BOUND = 52;
    int TARGET_MOVE_TOP_BOUND;
    int TARGET_MOVE_BOTTOM_BOUND;

    int GET_ANGLE_STATE = 0;
    int GET_POWER_STATE = 1;
    int BALL_MOVE_STATE = 2;

    ThrowBall(GFXEngine *engine, Input *inp) : Game(logo)
    {
        setXML(xml);
        gfxEngine = engine;
        input = inp;
    }

    void onCreate()
    {
    }

    void onStart() override
    {
        startPoint = new Point(0, 0);
        endPoint = new Point(0, 0);
        ball = gfxEngine->getCircleByID("ball");
        cursor = gfxEngine->getCircleByID("cursor");
        bar = gfxEngine->getRectangleByID("bar");
        barPanel = gfxEngine->getLayoutByID("barPanel");
        target = gfxEngine->getRectangleByID("target");
        scoreText = gfxEngine->getTextByID("scoreText");
    }

    void onUpdate() override
    {
        if (score >= 10)
        {
            moveTarget();
        }
        if (currentState == GET_ANGLE_STATE)
        {
            getAngle();
            changeLine();
            changeCurrentState();
        }
        else if (currentState == GET_POWER_STATE)
        {
            getPower();
            changeLine();
            changeCurrentState();
        }
        else if (currentState == BALL_MOVE_STATE)
        {
            moveBall();
            checkCollisions();
        }
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

        gfxEngine->display.drawLine(startPoint->getX(), startPoint->getY(), endPoint->getX(), endPoint->getY(), 1);
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
        angle *= pi / 2.5;
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
        if (input->BUTTON_1())
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

    void setSpeeds()
    {
        ballXSpeed = power * cos(angle) * speedCoef;
        ballYSpeed = power * sin(angle) * speedCoef;
        xLoc = ball->getX();
        yLoc = ball->getY();
    }

    void moveBall()
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
        }
    }

    void checkCollisions()
    {
        if ((yLoc - ball->getRadius()) >= target->getMgTop() && (yLoc + ball->getRadius()) <= (target->getMgTop() + target->getH()))
        {
            if (xLoc >= SCREEN_WIDTH)
            {
                createRandomTarget();
                score++;
                resetBallPosition();
            }
        }
        else
        {
            if ((xLoc + ball->getRadius()) >= (SCREEN_WIDTH - target->getW()) && millis() - COLLISION_PAST_TIME > collisionInterval)
            {
                ballXSpeed = -.6 * ballXSpeed;
                ballYSpeed = .6 * ballYSpeed;
                COLLISION_PAST_TIME = millis();
            }
        }

        if (yLoc >= SCREEN_HEIGHT)
        {
            resetBallPosition();
        }
    }

    void resetBallPosition()
    {
        ball->setVisibility(0);
        delay(250);
        ball->setVisibility(1);
        ball->setX(12);
        ball->setY(56);
        currentState = 0;
        power = 40;
        angle = 0;
        scoreText->setValue(score);
    }

    void createRandomTarget()
    {
        target->setH(random(TARGET_HEIGHT_LOWER_BOUND, TARGET_HEIGHT_UPPER_BOUND));
        target->setY(random(TARGET_POSITION_LOWER_BOUND, TARGET_POSITION_UPPER_BOUND));
        TARGET_MOVE_TOP_BOUND = target->getY() - random(6, 13);
        TARGET_MOVE_BOTTOM_BOUND = target->getY() + random(6, 13);
        targetSpeed = (score / 20) + 1;
        if (targetSpeed > 3)
            targetSpeed = 3;
    }

    void moveTarget()
    {
        if (millis() - MOVE_TARGET_PAST_TIME > moveTargetInterval)
        {

            if (target->getY() <= TARGET_MOVE_TOP_BOUND)
            {
                targetMoveDirection = 1;
            }

            else if (target->getY() >= TARGET_MOVE_BOTTOM_BOUND)
            {
                targetMoveDirection = -1;
            }
            target->setY(target->getY() + (targetSpeed * targetMoveDirection));
            MOVE_TARGET_PAST_TIME = millis();
        }
    }
};