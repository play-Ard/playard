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
    /* -------------- BEGIN MAGIC STRINGS -------------------- */

    const char *XML_FILE_PATH; /* File path of XML document */

    const char *XML_ROOT_NAME = "Main"; /* Root tag of given XML file */

    const char *XML_MAIN_LAYOUT_ID = "mainLayout"; /* Id of main wrapper layout */

    /* -------------- END OF MAGIC STRINGS -------------------- */

    Adafruit_SSD1306 display; /* Instance of screen */

    std::string xmlStr = "<Main><Layout id='mainLayout' width='128' height='64' x-position='64' y-position='32'>"              // experimental
                         "<Layout id='textLayout' width='96' height='16' x-position='64' y-position='12'>"                     // delete
                         "<Rectangle id='textBorder' width='96' height='16' x-position='48' y-position='8' color='1'/>"        // delete
                         "<Text id='entryText' x-position='48' y-position='8' font-size='1' value='' color='1' h-align='-1'/>" // delete
                         "</Layout>"                                                                                           // delete
                         "<Layout id='keyboardLayout' width='96' height='16' x-position='64' y-position='52'>"                 // delete
                         "<Rectangle id='underline' width='8' height='1' color='1' x-position='8' y-position='16'/>"           // delete
                         "<Text id='key1' x-position='8' y-position='8' color='1' value='X' font-size='1'/>"                   // delete
                         "<Text id='key2' x-position='28' y-position='8' color='1' value='X' font-size='1'/>"                  // delete
                         "<Text id='key3' x-position='48' y-position='8' color='1' value='X' font-size='1'/>"                  // delete
                         "<Text id='key4' x-position='68' y-position='8' color='1' value='X' font-size='1'/>"                  // delete
                         "<Text id='key5' x-position='88' y-position='8' color='1' value='X' font-size='1'/>"                  // delete
                         "</Layout>"                                                                                           // delete
                         "</Layout></Main>";                                                                                   // delete

    // std::string XML_FILE_PATH = "./design.xml";

    xml_document doc; /* The document object that contains all element tree */

    std::list<Layout *> layoutComps;     /* Holds layout components when a XML document loaded */
    std::list<Point *> pointComps;       /* Holds point components when a XML document loaded*/
    std::list<Rectangle *> rectComps;    /* Holds rectangle components when a XML document loaded*/
    std::list<Triangle *> triangleComps; /* Holds triangle components when a XML document loaded*/
    std::list<Circle *> circleComps;     /* Holds circle components when a XML document loaded*/
    std::list<Text *> textComps;         /* Holds text components when a XML document loaded*/

    void createComponents(xml_node node);
    /*
        Summary:
            Creates components and generates component vectors from given XML node

        Params:
        {
            node: The node to be parsed
        }

        Example Usage:
            createComponents(doc.child(XML_ROOT_NAME));
            createComponents(rootNode);
    */

    xml_node getRoot();
    /*
        Summary:
            Returns root element

        Usage:
            xml_node rootElement = getRoot();
    */

    void renderPoints();
    /*
        Summary:
            Renders each point component in pointComps vector
    */

    void renderRectangles();
    /*
        Summary:
            Renders each rectangle component in rectComps vector
    */

    void renderTriangles();
    /*
        Summary:
            Renders each triangle component in triangleComps vector
    */

    void renderCircles();
    /*
        Summary:
            Renders each circle component in circleComps vector
    */

    void renderTexts();
    /*
        Summary:
            Renders each text component in pointComps vector
    */

    void renderComponents();
    /*
        Summary:
            Executes all rendering methods when update method is called
    */

    void clearComponents();
    /*
        Summary:
            Clear all component vectors (pointComps, triangleComps etc.)
            Used when preparing to read a new XML document
    */

    uint8_t getMgTop(std::string parentID);
    /*
        Summary:
            Returns top margin of any component with adding top margin of each parent layout recursively

        Params:
        {
            parentID: The parent ID of the component for which the top margin is to be calculated
        }

        Example Usage:
            int topMargin = getMgTop(myTextComponent->getParentID());
    */

    uint8_t getMgLeft(std::string parentID);
    /*
        Summary:
            Returns left margin of any component with adding left margin of each parent layout recursively

        Params:
        {
            parentID: The parent ID of the component for which the left margin is to be calculated
        }

        Example Usage:
            int leftMargin = getMgLeft(myCircleComponent->getParentID());
    */

    bool getVisibility(std::string parentID);
    /*
        Summary:
            Returns state of visibility of any component
            It works recursively because if visibility of any parent layout is set to be hidden then it's desired to hide related component

        Params:
        {
            parentID: The parent ID of the component for which the left margin is to be calculated
        }

        Example Usage:
            int leftMargin = getMgLeft(myCircleComponent->getParentID());
    */

    void adjustText(Text *text); // EXPERIMENTAL
    /*
        Summary:
            Sets width and height attributes accordingly the text alignment attribute

        Params:
        {
            text: Text component to set width and height
        }

        Example Usage:
            adjustText(myTextComponent);
    */

public:
    void loadXML(const char *XMLStr);
    /*
        Summary:
            Loads xml document from given char array

        Params:
        {
            XMLStr: Text component to set width and height
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'></Layout></Main>";
            loadXML(myXML);
    */

    Layout *getLayoutByID(std::string ID);
    /*
        Summary:
            Finds the layout component and return its pointer accordingly to given ID

        Params:
        {
            ID: The ID attribute of layout
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'> <Layout id='myLayout'/></Main>";
            loadXML(myXML);

            Layout* myLayoutComponent = getLayoutByID("myLayout");
    */

    Point *getPointByID(std::string ID);
    /*
        Summary:
            Finds the point component and return its pointer accordingly to given ID

        Params:
        {
            ID: The ID attribute of point
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'> <Point id='myPoint'/></Main>";
            loadXML(myXML);

            Point* myPointComponent = getPointByID("myPoint");
    */

    Rectangle *getRectangleByID(std::string ID);
    /*
        Summary:
            Finds the rectangle component and return its pointer accordingly to given ID

        Params:
        {
            ID: The ID attribute of rectangle
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'> <Rectangle id='myRectangle'/></Main>";
            loadXML(myXML);

            Rectangle* myRectangleComponent = getRectangleByID("myPoint");
    */

    Triangle *getTriangleByID(std::string ID);
    /*
        Summary:
            Finds the triangle component and return its pointer accordingly to given ID

        Params:
        {
            ID: The ID attribute of triangle
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'> <Triangle id='myTriangle'/></Main>";
            loadXML(myXML);

            Triangle* myTriangleComponent = getTriangleByID("myTriangle");
    */

    Circle *getCircleByID(std::string ID);
    /*
        Summary:
            Finds the circle component and return its pointer accordingly to given ID

        Params:
        {
            ID: The ID attribute of circle
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'> <Circle id='myCircle'/></Main>";
            loadXML(myXML);

            Circle* myCircleComponent = getCircleByID("myCircle");
    */

    Text *getTextByID(std::string ID);
    /*
        Summary:
            Finds the text component and return its pointer accordingly to given ID

        Params:
        {
            ID: The ID attribute of text
        }

        Example Usage:
            const char * myXML = "<Main> <Layout id='mainLayout'> <Text id='myText'/></Main>";
            loadXML(myXML);

            Text* myTextComponent = getTextByID("myText");
    */

    // void setXMLPath(std::string path);

    void begin(uint16_t screen_width, uint16_t screen_height, uint8_t reset_pin, int address);
    /*
        Summary:
            Starts the graphic engine with given parameters

        Params:
        {
            screen_width: Width of display screen
            screen_height: Height of display screen
            reset_pin: Reset pin of display screen
            address: Address of display screen
        }

        Example Usage:
            begin(128, 64, -1, 0x3C);
    */

    void update();
    /*
        Summary:
            Updates the display screen and components
    */
};

#endif