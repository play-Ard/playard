#include "GFXEngine.h"
#include <typeinfo>

void GFXEngine::loadXML(const char *XMLStr) // will be edited
{
    // if (!GFXEngine::doc.load_file(GFXEngine::XML_FILE_PATH.c_str()))
    //     while (0)
    //         ;

    if (!doc.load_string(XMLStr))
        while (1)
            ;

    GFXEngine::clearComponents();
    GFXEngine::createComponents(GFXEngine::getRoot());
}

void GFXEngine::clearComponents()
{
    GFXEngine::layoutComps.clear();
    GFXEngine::rectComps.clear();
    GFXEngine::circleComps.clear();
    GFXEngine::textComps.clear();
    GFXEngine::triangleComps.clear();
}

void GFXEngine::createComponents(xml_node node)
{
    for (const auto &child : node)
    {
        if (!strcmp(child.name(), "Layout"))
        {
            Layout *layout = new Layout();

            layout->setID(child.attribute("id").value());
            layout->setW(child.attribute("width").as_int());
            layout->setH(child.attribute("height").as_int());
            layout->setX(child.attribute("x-position").as_int());
            layout->setY(child.attribute("y-position").as_int());
            layout->setVisibility(child.attribute("visibility").as_bool(VISIBILITY_DEFAULT));
            layout->setParentID(node.attribute("id").value());

            GFXEngine::layoutComps.push_back(layout);

            GFXEngine::createComponents(child);
        }

        else if (!strcmp(child.name(), "Rectangle"))
        {
            Rectangle *rectangle = new Rectangle();

            rectangle->setID(child.attribute("id").value());
            rectangle->setColor(child.attribute("color").as_uint(COLOR_DEFAULT));
            rectangle->setW(child.attribute("width").as_int());
            rectangle->setH(child.attribute("height").as_int());
            rectangle->setX(child.attribute("x-position").as_int());
            rectangle->setY(child.attribute("y-position").as_int());
            rectangle->setBorderRadius(child.attribute("border-radius").as_uint(BORDER_RADIUS_DEFAULT));
            rectangle->setVisibility(child.attribute("visibility").as_bool(VISIBILITY_DEFAULT));
            rectangle->setFill(child.attribute("fill").as_bool(FILL_DEFAULT));
            rectangle->setParentID(node.attribute("id").value());

            GFXEngine::rectComps.push_back(rectangle);
        }

        else if (!strcmp(child.name(), "Circle"))
        {
            Circle *circle = new Circle();

            circle->setID(child.attribute("id").value());
            circle->setColor(child.attribute("color").as_uint(COLOR_DEFAULT));
            circle->setRadius(child.attribute("radius").as_int());
            circle->setX(child.attribute("x-position").as_int());
            circle->setY(child.attribute("y-position").as_int());
            circle->setVisibility(child.attribute("visibility").as_bool(VISIBILITY_DEFAULT));
            circle->setFill(child.attribute("fill").as_bool(FILL_DEFAULT));
            circle->setParentID(node.attribute("id").value());

            GFXEngine::circleComps.push_back(circle);
        }

        else if (!strcmp(child.name(), "Text"))
        {
            Text *text = new Text();

            text->setID(child.attribute("id").value());
            text->setValue(child.attribute("value").value());
            text->setFontSize(child.attribute("font-size").as_uint(FONT_SIZE_DEFAULT));
            text->setColor(child.attribute("color").as_uint(COLOR_DEFAULT));
            text->setBgColor(child.attribute("bg-color").as_uint(BG_COLOR_DEFAULT));
            text->setX(child.attribute("x-position").as_int());
            text->setY(child.attribute("y-position").as_int());
            text->setVisibility(child.attribute("visibility").as_bool(VISIBILITY_DEFAULT));
            text->setHAlignment(child.attribute("h-align").as_int());
            text->setParentID(node.attribute("id").value());

            GFXEngine::textComps.push_back(text);
        }
    }
}

uint8_t GFXEngine::getMgTop(std::string parentID)
{
    Layout *parentLayout = GFXEngine::getLayoutByID(parentID.c_str());
    uint8_t m_mgTop = parentLayout->getMgTop();

    if (!strcmp(parentID.c_str(), GFXEngine::XML_MAIN_LAYOUT_ID))
    {
        return m_mgTop;
    }

    else
    {
        return m_mgTop + GFXEngine::getMgTop(parentLayout->getParentID());
    }
}

uint8_t GFXEngine::getMgLeft(std::string parentID)
{
    Layout *parentLayout = GFXEngine::getLayoutByID(parentID.c_str());
    uint8_t m_mgLeft = parentLayout->getMgLeft();

    if (!strcmp(parentID.c_str(), GFXEngine::XML_MAIN_LAYOUT_ID))
    {
        return m_mgLeft;
    }
    else
    {
        return m_mgLeft + GFXEngine::getMgLeft(parentLayout->getParentID());
    }
}

bool GFXEngine::getVisibility(std::string parentID)
{
    Layout *parentLayout = GFXEngine::getLayoutByID(parentID.c_str());
    bool visibility = parentLayout->getVisibility();

    if (!strcmp(parentID.c_str(), GFXEngine::XML_MAIN_LAYOUT_ID))
    {
        return visibility;
    }

    else
    {
        return visibility && GFXEngine::getVisibility(parentLayout->getParentID());
    }
}

xml_node GFXEngine::getRoot()
{
    return GFXEngine::doc.child(GFXEngine::XML_ROOT_NAME);
}

Layout *GFXEngine::getLayoutByID(std::string id)
{
    for (Layout *&layout : GFXEngine::layoutComps)
    {
        if (!strcmp(layout->getID().c_str(), id.c_str()))
        {
            return layout;
        }
    }

    while (1)
        ;
}

Point *GFXEngine::getPointByID(std::string id)
{
    for (Point *&point : GFXEngine::pointComps)
    {
        if (!strcmp(point->getID().c_str(), id.c_str()))
        {
            return point;
        }
    }

    while (1)
        ;
}

Rectangle *GFXEngine::getRectangleByID(std::string id)
{
    for (Rectangle *&rect : GFXEngine::rectComps)
    {
        if (!strcmp(rect->getID().c_str(), id.c_str()))
        {
            return rect;
        }
    }

    while (1)
        ;
}

Triangle *GFXEngine::getTriangleByID(std::string id)
{
    for (Triangle *&triangle : GFXEngine::triangleComps)
    {
        if (!strcmp(triangle->getID().c_str(), id.c_str()))
        {
            return triangle;
        }
    }

    while (1)
        ;
}

Circle *GFXEngine::getCircleByID(std::string id)
{
    for (Circle *&circle : GFXEngine::circleComps)
    {
        if (!strcmp(circle->getID().c_str(), id.c_str()))
        {
            return circle;
        }
    }

    while (1)
        ;
}

Text *GFXEngine::getTextByID(std::string id)
{
    for (Text *&text : GFXEngine::textComps)
    {
        if (!strcmp(text->getID().c_str(), id.c_str()))
        {
            return text;
        }
    }

    while (1)
        ;
}

void GFXEngine::adjustText(Text *text)
{
    int16_t x1, y1;
    uint16_t w, h;
    GFXEngine::display.getTextBounds(text->getValue().c_str(), text->getMgLeft(), text->getMgTop(), &x1, &y1, &w, &h);

    if (text->getHAlignment() == 0)
    {
        text->setWidth(w);
        text->setHeight(h);
    }
}

void GFXEngine::renderPoints()
{
    for (Point *&point : GFXEngine::pointComps)
    {
        if (point->getVisibility())
        {
            uint16_t X = GFXEngine::getMgTop(point->getParentID()) + point->getY();
            uint16_t Y = GFXEngine::getMgLeft(point->getParentID()) + point->getX();
            uint8_t color = point->getColor();
            GFXEngine::display.drawPixel(X, Y, color);
        }
    }
}

// void GFXEngine::setXMLPath(std::string path) {
//     GFXEngine::XML_FILE_PATH = path;
// }

void GFXEngine::renderTexts()
{
    for (Text *&text : GFXEngine::textComps)
    {
        bool visibility = text->getVisibility() && GFXEngine::getVisibility(text->getParentID());
        if (visibility)
        {

            adjustText(text);
            uint16_t mgTop = GFXEngine::getMgTop(text->getParentID()) + text->getMgTop();
            uint16_t mgLeft = GFXEngine::getMgLeft(text->getParentID()) + text->getMgLeft();
            GFXEngine::display.setCursor(mgLeft, mgTop);
            GFXEngine::display.setTextColor(text->getColor(), text->getBgColor());
            GFXEngine::display.setTextSize(text->getFontSize());
            GFXEngine::display.print(text->getValue().c_str());
        }
    }
}

void GFXEngine::renderRectangles()
{
    for (Rectangle *&rectangle : GFXEngine::rectComps)
    {
        bool visibility = rectangle->getVisibility() && GFXEngine::getVisibility(rectangle->getParentID());
        if (visibility)
        {
            uint16_t mgTop = GFXEngine::getMgTop(rectangle->getParentID()) + rectangle->getMgTop();
            uint16_t mgLeft = GFXEngine::getMgLeft(rectangle->getParentID()) + rectangle->getMgLeft();
            uint8_t width = rectangle->getW();
            uint8_t height = rectangle->getH();
            uint8_t color = rectangle->getColor();
            uint8_t radius = rectangle->getBorderRadius();
            if (rectangle->getFill())
            {
                GFXEngine::display.fillRoundRect(mgLeft, mgTop, width, height, radius, color);
            }
            else
            {
                GFXEngine::display.drawRoundRect(mgLeft, mgTop, width, height, radius, color);
            }
        }
    }
}

void GFXEngine::renderTriangles()
{
    for (Triangle *&triangle : GFXEngine::triangleComps)
    {
        bool visibility = triangle->getVisibility() && GFXEngine::getVisibility(triangle->getParentID());
        if (visibility)
        {
            uint8_t y1 = GFXEngine::getMgTop(triangle->getParentID()) + triangle->getPoint1().getY();
            uint8_t y2 = GFXEngine::getMgTop(triangle->getParentID()) + triangle->getPoint2().getY();
            uint8_t y3 = GFXEngine::getMgTop(triangle->getParentID()) + triangle->getPoint3().getY();
            uint8_t x1 = GFXEngine::getMgLeft(triangle->getParentID()) + triangle->getPoint1().getX();
            uint8_t x2 = GFXEngine::getMgLeft(triangle->getParentID()) + triangle->getPoint2().getX();
            uint8_t x3 = GFXEngine::getMgLeft(triangle->getParentID()) + triangle->getPoint3().getX();
            uint8_t color = triangle->getColor();
            GFXEngine::display.drawTriangle(x1, y1, x2, y2, x3, y3, color);
        }
    }
}

void GFXEngine::renderCircles()
{
    for (Circle *&circle : GFXEngine::circleComps)
    {
        bool visibility = circle->getVisibility() && GFXEngine::getVisibility(circle->getParentID());
        if (visibility)
        {
            uint8_t y1 = GFXEngine::getMgTop(circle->getParentID()) + circle->getY();
            uint8_t x1 = GFXEngine::getMgLeft(circle->getParentID()) + circle->getX();
            uint8_t radius = circle->getRadius();
            uint8_t color = circle->getColor();
            if (circle->getFill())
            {
                GFXEngine::display.fillCircle(x1, y1, radius, color);
            }

            else
            {
                GFXEngine::display.drawCircle(x1, y1, radius, color);
            }
        }
    }
}

void GFXEngine::renderComponents()
{
    GFXEngine::renderPoints();
    GFXEngine::renderRectangles();
    GFXEngine::renderTriangles();
    GFXEngine::renderCircles();
    GFXEngine::renderTexts();
}

void GFXEngine::begin(uint16_t screen_width, uint16_t screen_height, uint8_t reset_pin, int SCREEN_ADDRESS)
{
    GFXEngine::loadXML(GFXEngine::xmlStr.c_str());
    GFXEngine::display = Adafruit_SSD1306(screen_width, screen_height, &Wire, reset_pin);
    GFXEngine::display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
    GFXEngine::display.clearDisplay();
}

void GFXEngine::update()
{
    GFXEngine::display.clearDisplay();
    GFXEngine::renderComponents();
    display.display();
}
