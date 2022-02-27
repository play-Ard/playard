#include "GFXEngine.h"
#include <typeinfo>

void GFXEngine::parseXML()
{
    if(!doc.load_string(GFXEngine::xmlStr.c_str())) while (1);
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
            layout->setParentID(node.attribute("id").value());

            GFXEngine::components[child.attribute("id").value()] = layout;
            GFXEngine::createComponents(child);
        }

        else if (!strcmp(child.name(), "Rectangle"))
        {
            Rectangle *rectangle = new Rectangle();

            rectangle->setID(child.attribute("id").value());
            rectangle->setColor(child.attribute("color").as_int());
            rectangle->setW(child.attribute("width").as_int());
            rectangle->setH(child.attribute("height").as_int());
            rectangle->setX(child.attribute("x-position").as_int());
            rectangle->setY(child.attribute("y-position").as_int());
            rectangle->setBorderRadius(child.attribute("border-radius").as_int());
            rectangle->setParentID(node.attribute("id").value());

            GFXEngine::components[child.attribute("id").value()] = rectangle;
        }

        else if (!strcmp(child.name(), "Circle"))
        {
            Circle *circle = new Circle();

            circle->setID(child.attribute("id").value());
            circle->setColor(child.attribute("color").as_int());
            circle->setRadius(child.attribute("radius").as_int());
            circle->setX(child.attribute("x-position").as_int());
            circle->setY(child.attribute("y-position").as_int());
            circle->setParentID(node.attribute("id").value());

            GFXEngine::components[child.attribute("id").value()] = circle;
        }

        else if (!strcmp(child.name(), "Text"))
        {
            Text *text = new Text();

            text->setID(child.attribute("id").value());
            text->setValue(child.attribute("value").value());
            text->setFontSize(child.attribute("font-size").as_int());
            text->setColor(child.attribute("color").as_int());
            text->setX(child.attribute("x-position").as_int());
            text->setY(child.attribute("y-position").as_int());
            text->setParentID(node.attribute("id").value());

            GFXEngine::components[child.attribute("id").value()] = text;
        }
    }
}

xml_node GFXEngine::getRoot()
{
    return GFXEngine::doc.child("MainFrame");
}

Component *GFXEngine::findComponentByID(std::string id)
{
    for (auto &pair : GFXEngine::components)
    {
        if (!strcmp(id.c_str(), pair.first.c_str()))
        {
            return pair.second;
        }
    }

    while(1);

}

void GFXEngine::renderComonents() {
    for (auto &pair : GFXEngine::components)
    {
        if (!strcmp(id.c_str(), pair.first.c_str()))
        {
            return pair.second;
        }
    }
}

void GFXEngine::begin()
{
    GFXEngine::parseXML();
    GFXEngine::createComponents(GFXEngine::getRoot());
}