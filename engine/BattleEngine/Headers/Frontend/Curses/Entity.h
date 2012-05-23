#pragma once

#include "ncurses.h"

#include <string>

namespace engine { namespace frontend { namespace curses {

class Entity
{
public:
    int x, y;
    
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
};

}}}
