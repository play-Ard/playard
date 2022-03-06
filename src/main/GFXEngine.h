#ifndef GFXENGINE_H
#define GFXENGINE_H

#define FILL_DEFAULT 0
#define VISIBILITY_DEFAULT 1
#define COLOR_DEFAULT 1
#define FONT_SIZE_DEFAULT 1
#define BG_COLOR_DEFAULT 0
#define BORDER_RADIUS_DEFAULT 0

#include "pugixml.hpp"
#include "UI.h"
#include <string.h>
#include <list>

using namespace pugi;

class GFXEngine
{
private:
    const char *XML_FILE_PATH; // File path of XML
    const char *XML_ROOT_NAME = "Main"; // Root tag of given XML file
    const char *XML_MAIN_LAYOUT_ID = "mainLayout";
    std::string xmlStr = "<Main><Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"    // experimental
                         "<Layout id='textLayout' width='96' height='16' x-position='64' y-position='12'>"    // delete
                         "<Rectangle id='textBorder' width='96' height='16' x-position='48' y-position='8' color='1'/>"    // delete
                         "<Text id='entryText' x-position='48' y-position='8' font-size='1' value='' color='1' h-align='-1'/>"    // delete
                         "</Layout>"    // delete
                         "<Layout id='keyboardLayout' width='96' height='16' x-position='64' y-position='52'>"    // delete
                         "<Rectangle id='underline' width='8' height='1' color='1' x-position='8' y-position='16'/>"    // delete
                         "<Text id='key1' x-position='8' y-position='8' color='1' value='X' font-size='1'/>"    // delete
                         "<Text id='key2' x-position='28' y-position='8' color='1' value='X' font-size='1'/>"    // delete
                         "<Text id='key3' x-position='48' y-position='8' color='1' value='X' font-size='1'/>"    // delete
                         "<Text id='key4' x-position='68' y-position='8' color='1' value='X' font-size='1'/>"    // delete
                         "<Text id='key5' x-position='88' y-position='8' color='1' value='X' font-size='1'/>"    // delete
                         "</Layout>"    // delete
                         "</Layout></Main>";    // delete

    // std::string XML_FILE_PATH = "./design.xml";

    xml_document doc; // The document object that contains all element tree

    void createComponents(xml_node node);

    xml_node getRoot();

    void renderComonents();

    std::list<Layout *> layoutComps;
    std::list<Point *> pointComps;
    std::list<Rectangle *> rectComps;
    std::list<Triangle *> triangleComps;
    std::list<Circle *> circleComps;
    std::list<Text *> textComps;

    void renderPoints();
    void renderRectangles();
    void renderTriangles();
    void renderCircles();
    void renderTexts();

    void renderComponents();
    void clearComponents();

    Adafruit_SSD1306 display;
    int SCREEN_ADDRESS;

    long getMgTop(std::string parentID);
    long getMgLeft(std::string parentID);
    bool getVisibility(std::string parentID);

    void adjustText(Text *text);

public:
    void loadXML(const char *XMLStr); // will edit this

    Layout *getLayoutByID(std::string id);
    Point *getPointByID(std::string id);
    Rectangle *getRectangleByID(std::string id);
    Triangle *getTriangleByID(std::string id);
    Circle *getCircleByID(std::string id);
    Text *getTextByID(std::string id);

    // void setXMLPath(std::string path);

    void begin(uint16_t screen_width, uint16_t screen_height, uint8_t reset_pin, int SCREEN_ADDRESS);
    void update();
};

#endif