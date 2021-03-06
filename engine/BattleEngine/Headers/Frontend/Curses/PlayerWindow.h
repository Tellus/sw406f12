#pragma once

// Inherits.
#include "Frontend/Curses/Window.h"

// Contains.
#include "Character.h"

#include <map>
#include <list>

namespace engine { namespace frontend { namespace curses {

/**
 * The PlayerWindow is a wrapper around a character and dynamically
 * displays their data on request.
 **/
class PlayerWindow : public Window
{
public:
    PlayerWindow(Character* p);
    PlayerWindow(int x, int y, int w, int h, Character* p);

    Character* player;
    
    std::map<std::string, engine::Resource*>* resources;
    std::map<std::string, engine::Attribute*>* attributes;
    std::map<std::string, engine::Ability*>* abilities;
    
    std::list<Entity*> children;
    
    virtual void render();
    
    virtual void update();
    
    virtual std::string to_string();
    
    /**
     * Retrieves the starting x coordinate for outputting in the left column.
     **/
    int get_leftx();
    
    /**
     * Retrieves the starting x coordinate for outputting in the right column.
     **/
    int get_rightx();
    
protected:
    /**
     * Loads the Character into the various lists.
     **/
    void load_char(Character* c);
    
private:
    void _init(Character* c);
};

}}}
