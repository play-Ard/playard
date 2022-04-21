#include "../core/PlayardCore.h"

class Pong : public Game
{
public:
    const unsigned char logo[384] PROGMEM = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
        0x38, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x3c, 0x1c, 0x03, 0xfc,
        0x7f, 0xf8, 0x00, 0x00, 0x3e, 0x1c, 0x0f, 0xfe, 0x7f, 0xf8, 0x0f, 0xc0, 0x3e, 0x1c, 0x0f, 0xfe,
        0x78, 0xf8, 0x1f, 0xe0, 0x3f, 0x1c, 0x1f, 0x9e, 0x78, 0x78, 0x3f, 0xf0, 0x3f, 0x9c, 0x1e, 0x0c,
        0x78, 0x78, 0x3f, 0xf0, 0x3f, 0xdc, 0x1e, 0x00, 0x78, 0xf8, 0x7f, 0xf0, 0x3f, 0xdc, 0x3c, 0x0e,
        0x7f, 0xf8, 0x7f, 0xf0, 0x3b, 0xfc, 0x3c, 0x0e, 0x7f, 0xf8, 0x7f, 0xf0, 0x3b, 0xfc, 0x1e, 0x0e,
        0x7f, 0xf0, 0x3f, 0xf0, 0x39, 0xfc, 0x1e, 0x0e, 0x7f, 0x80, 0x3f, 0xf0, 0x38, 0xfc, 0x1f, 0x9e,
        0x78, 0x00, 0x1f, 0xe0, 0x38, 0x7c, 0x0f, 0xfe, 0x78, 0x00, 0x0f, 0x80, 0x38, 0x7c, 0x0f, 0xfe,
        0x78, 0x00, 0x00, 0x00, 0x38, 0x3c, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x70, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x0e, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

    const char *xml = "<Main>"
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

    GFXEngine *gfxEngine;
    Input *input;

    int currentImage = 0;

    int changeImageTime = 200;
    int moveTimeInterval = 2;

    int timeInterval = 200;

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

    Pong(GFXEngine *engine, Input *inp) : Game(logo)
    {
        setXML(xml);
        gfxEngine = engine;
        input = inp;
    }

    void onCreate()
    {
    }

    void onStart()
    {
        paddle1 = gfxEngine->getRectangleByID("paddle1");
        paddle2 = gfxEngine->getRectangleByID("paddle2");
        ball = gfxEngine->getCircleByID("ball");
        score1Text = gfxEngine->getTextByID("score1Text");
        score2Text = gfxEngine->getTextByID("score2Text");
        restartGame();
    }

    void onUpdate()
    {
        updateScores();
        movePaddles();
        moveBall();
        if (input->BUTTON_2()) {
            this->exit();
        }
    }

    void updateScores()
    {
        score1Text->setValue(score1);
        score2Text->setValue(score2);
    }

    void movePaddles()
    {
        if (input->BUTTON_U() && millis() - input->BUTTON_U_PREV_T() > moveTimeInterval)
        {
            input->BUTTON_U_PREV_T(millis());
            if (paddle1->getY() - paddle1->getH() / 2 > 0)
            {
                paddle1->setY(paddle1->getY() - paddleAcl);
            }
        }
        else if (input->BUTTON_D() && millis() - input->BUTTON_D_PREV_T() > moveTimeInterval)
        {
            input->BUTTON_D_PREV_T(millis());
            if (paddle1->getY() + paddle1->getH() / 2 < 63)
            {
                paddle1->setY(paddle1->getY() + paddleAcl);
            }
        }

        if (input->BUTTON_1() && millis() - input->BUTTON_1_PREV_T() > moveTimeInterval)
        {
            input->BUTTON_1_PREV_T(millis());
            if (paddle2->getY() - paddle2->getH() / 2 > 0)
            {
                paddle2->setY(paddle2->getY() - paddleAcl);
            }
        }
        else if (input->BUTTON_3() && millis() - input->BUTTON_3_PREV_T() > moveTimeInterval)
        {
            input->BUTTON_3_PREV_T(millis());
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
            ySpeed = -ySpeed;
        }

        if (ball->getX() - ball->getRadius() < (0 + paddle1->getW()))
        {
            if (ball->getY() <= paddle1->getY() + (paddle1->getH() / 2) && ball->getY() >= paddle1->getY() - (paddle1->getH() / 2))
            {
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
        paddle1->setY(32);
        paddle2->setY(32);
        ball->setX(64);
        ball->setY(32);

        ySpeed = random(0, 2) ? ballAcl : -ballAcl;
        xSpeed = random(0, 2) ? ballAcl : -ballAcl;

        delay(500);
    }
};