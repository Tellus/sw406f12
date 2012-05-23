#pragma once

#include "Entity.h"
#include "panel.h"

namespace engine {
    namespace frontend {
        namespace curses {
 
/**
 * More a border class than an actual proxy for ncurses' WINDOW type, this class
 * works like a visible rectangle on the screen.
 **/       
class Window : public Entity
{
public:
    Window(int x, int y, int w, int h);

    /**
     * The panel used for rendering order.
     **/
    PANEL* panel;
    
    /**
     * The window used for actual drawing and boxing.
     **/
    WINDOW* window;
    
    int width, height;
    
    void move_to(int x, int y);
    
    void move_by(int x, int y);
    
    void clear(bool del = false);
    
protected:
    void _window_move(int x, int y);

private:
};

}}}
