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
    
    void move_to(int x, int y);
    
    void move_by(int x, int y);
    
    int get_top();
    int get_bottom();
    int get_left();
    int get_right();
    
    /**
     * Clears the window's display.
     * \param del If set to true, the window will be destroyed along with the
     * buffer clearing.
     **/
    void clear(bool del = false);

    /**
     * Scrolls the window. Proxy for wscrl(this->window, numlines).
     * \param numlines The number of lines to scroll. Positive scrolls the window up one line, negative the other way.
     **/
    void do_scroll(int numlines);
    
    virtual void render();
    
    virtual void update();

    int get_width();
    int get_height();

    virtual void pre_render();
    
    virtual void post_render();
    
    /**
     * Title of the window. Will be shown near the top-left corner along the
     * top border.
     **/
    std::string title;
    
protected:
    void _window_move(int x, int y);
    
    int width, height;

private:
};

}}}
