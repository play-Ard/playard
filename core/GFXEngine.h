#ifndef GFXENGINE_H
#define GFXENGINE_H

#include "pugixml.hpp"
#include "UI.h"
#include <unordered_map>
#include <string.h>
using namespace pugi;

class GFXEngine
{
private:
    const char *FILE_PATH;
    const char *XML_ROOT_NAME = "MainFrame";
    std::string xmlStr = "<MainFrame id='mainLayout' width='128' height='128'>"
                     "<Rectangle id='rectangle1'/>"

                     "<Layout id='layout1'>"
                     "<Layout id='layout1-inner' width='64' height='32'>"
                     "<Layout id='layout1-inner-inner'>"
                     "<Rectangle id='rectangle2'/>"
                     "</Layout>"
                     "</Layout>"
                     "</Layout>"
                     "<Layout id='layout2'>"
                     "<Text id='text1' color='1' font-size='2'/>"
                     "</Layout>"
                     "</MainFrame>";

    xml_document doc;

    void parseXML();

    void createComponents(xml_node node);

    xml_node getRoot();

    void renderComonents();

    std::unordered_map<std::string, Component *> components;

public:
    Component* findComponentByID(std::string id);
    
    void begin();
};

#endif