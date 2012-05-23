#pragma once

// Inherits.
#include "Frontend/Curses/Entity.h"

// Contains.
#include "Character.h"
#include "Frontend/Curses/Label.h"

#include <map>
#include <list>

namespace engine { namespace frontend { namespace curses {

/**
 * The PlayerWindow is a wrapper around a character and dynamically
 * displays their data on request.
 **/
class PlayerWindow : public Entity
{
public:
    Character* player;
    WINDOW* window;
    
    int width, height;
    
    std::map<std::string, engine::Resource*>* resources;
    std::map<std::string, engine::Attribute*>* attributes;
    std::map<std::string, engine::Ability*>* abilities;
    
    std::list<Entity*> children;
    
    PlayerWindow(Character* p);
    
    void move_to(int x, int y);
    
    void move_by(int x, int y);
    
    void clear(bool del = false);
    
    void render();
    
    void update();
    
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

    void _window_move(int x, int y);
    
private:
    void _init(int nx = 0, int ny = 0, int nw = 20, int nh = 10);
};

}}}
