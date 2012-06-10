#pragma once

#include "ncurses.h"

#include <string>

namespace engine { namespace frontend { namespace curses {

/**
 * Generic curses entity. Useless on its own.
 **/
class Entity
{
public:
    Entity(int x, int y);
    Entity();
    
    virtual void move_to(int x, int y);
    
    virtual void move_by(int x, int y);
    
    /**
     * Renders to screen.
     **/
    virtual void render() = 0;
    
    /**
     * Updates data.
     **/
    virtual void update() = 0;
    
    virtual std::string to_string();

    int get_x();
    
    int get_y();

protected:
    int x, y;
};

}}}
