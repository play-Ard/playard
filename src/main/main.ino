#include "GFXEngine.h"
#include "Input.h"

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

const unsigned char logo_bitmap[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xfc, 0x07, 0x80, 0x07, 0xe0, 0x38, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xfc, 0x07, 0x80, 0x07, 0xe0, 0x38, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0x87, 0x80, 0x3f, 0xfc, 0x3f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x87, 0x87, 0x80, 0x3c, 0x3c, 0x0f, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x87, 0x87, 0x80, 0x3c, 0x3c, 0x0f, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0x87, 0x80, 0x3f, 0xfc, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xfc, 0x07, 0x80, 0x3f, 0xfc, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xfc, 0x07, 0x80, 0x3f, 0xfc, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x07, 0x80, 0x3c, 0x3c, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x07, 0x80, 0x3c, 0x3c, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x07, 0xfc, 0x3c, 0x3c, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x07, 0xfc, 0x3c, 0x3c, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x07, 0xfc, 0x3c, 0x3c, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0x80, 0x07, 0xfc, 0x3c, 0x3c, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0x80, 0x1f, 0xfe, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0x80, 0x1f, 0xfe, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0x80, 0x1f, 0xfe, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0x80, 0x1f, 0xfe, 0x00, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xf8, 0x1f, 0xff, 0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x03, 0xc0, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x03, 0xc0, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x03, 0xc0, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xf8, 0x1f, 0xff, 0xc0, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xf8, 0x1f, 0xfe, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xf8, 0x1f, 0xfe, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xf8, 0x1f, 0xfe, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x3e, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x3e, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x3e, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x3f, 0xc0, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x03, 0xc0, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x03, 0xc0, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0xf8, 0x1f, 0x03, 0xc0, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char pong_bitmap[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xf8, 0x1f, 0xfe, 0x30, 0x0c, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xfc, 0x3f, 0xfe, 0x38, 0x0c, 0x3f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x1c, 0x78, 0x3f, 0x3c, 0x0c, 0x7c, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x1c, 0xf0, 0x3e, 0x3c, 0x0c, 0x70, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x1c, 0xe0, 0x3e, 0x3e, 0x0c, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x3c, 0xc0, 0x07, 0x3f, 0x0c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xfc, 0xc0, 0x07, 0x37, 0x8c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xf0, 0xc0, 0x07, 0x33, 0xcc, 0xe0, 0x7f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0xc0, 0x07, 0x31, 0xec, 0xe0, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0xe0, 0x07, 0x30, 0xfc, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0xe0, 0x0e, 0x30, 0x7c, 0x70, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0xf0, 0x1e, 0x30, 0x3c, 0x78, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0x7c, 0x3c, 0x30, 0x1c, 0x3e, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0x3f, 0xf8, 0x30, 0x1c, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0e, 0x00, 0x1f, 0xf0, 0x30, 0x0c, 0x0f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const int bitmap_array_LEN = 2;
const unsigned char *bitmap_array[bitmap_array_LEN] = {
    logo_bitmap,
    pong_bitmap,
};

GFXEngine gfxEngine;
Input input;

int currentImage = 0;

int changeImageTime = 200;
int moveTimeInterval = 2;

long BUTTON_1_PAST_TIME = 0;
long BUTTON_2_PAST_TIME = 0;
long BUTTON_U_PAST_TIME = 0;
long BUTTON_L_PAST_TIME = 0;
long BUTTON_R_PAST_TIME = 0;
long BUTTON_D_PAST_TIME = 0;
long BUTTON_3_PAST_TIME = 0;
int timeInterval = 200;

#define MENU 0
#define PONG_GAME 1

int currentMenu = 0;
int currentActivity = 0;

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
    gfxEngine.loadXML(menuXML);
    Serial.println("SUCCESSFULLY PARSED");
}

void loop()
{
    if (currentActivity == MENU)
    {
        changeCurrentImage();
        changeMenu();
    }
    else if (currentActivity == PONG_GAME)
    {
        updateScores();
        movePaddles();
        moveBall();
    }
    gfxEngine.update();
}

void changeMenu()
{
    if (input.BUTTON_1() && millis() - BUTTON_1_PAST_TIME > changeImageTime)
    {
        if (currentImage == PONG_GAME)
        {
            currentActivity = PONG_GAME;
            gfxEngine.loadXML(gameXML);
            paddle1 = gfxEngine.getRectangleByID("paddle1");
            paddle2 = gfxEngine.getRectangleByID("paddle2");
            ball = gfxEngine.getCircleByID("ball");
            score1Text = gfxEngine.getTextByID("score1Text");
            score2Text = gfxEngine.getTextByID("score2Text");
            restartGame();
        }
        BUTTON_1_PAST_TIME = millis();
    }
}

void changeCurrentImage()
{
    if (input.BUTTON_U() && millis() - BUTTON_U_PAST_TIME > changeImageTime)
    {
        currentImage = ((currentImage - 1) + bitmap_array_LEN) % bitmap_array_LEN;
        BUTTON_U_PAST_TIME = millis();
    }
    else if (input.BUTTON_D() && millis() - BUTTON_D_PAST_TIME > changeImageTime)
    {
        currentImage = (currentImage + 1) % bitmap_array_LEN;
        BUTTON_D_PAST_TIME = millis();
    }

    gfxEngine.display.drawBitmap(0, 0, bitmap_array[currentImage], 128, 64, 1);
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