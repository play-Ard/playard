#ifndef GAME_H
#define GAME_H

#include <list>

class Game
{
private:
    const char *xml;
    const unsigned char *logo;
    bool activity = 1;

public:
    Game();
    Game(const unsigned char _logo[])
    {
        this->logo = _logo;
    }

    virtual void onCreate(){};
    virtual void onStart() = 0;
    virtual void onUpdate() = 0;
    virtual void onExit(){};

    const char *getXML() { return this->xml; }

    void setXML(const char *_xml) { this->xml = _xml; }

    const unsigned char *getLogo() { return this->logo; }

    void setLogo(const unsigned char _logo[]) { this->logo = _logo; }

    bool getActivity() { return this->activity; }

    void setActivity(bool _activity) { this->activity = _activity; }

    void exit()
    {
        onExit();
        setActivity(0);
    }
};

#endif