#pragma once

#include "Window.h"

namespace engine { namespace frontend { namespace curses

/**
 * Shows information in a scrolling window.
 **/
class MessageWindow : public Window
{
public:
    /**
     * Creates a new messaging window.
     * \param x Starting x position.
     * \param y Starting y position.
     * \param w Width of the window.
     * \param h Height of the window. This is also the number of lines the
     * window can hold.
     **/
    MessageWindow(int x, int y, int w, int h);
    
    /**
     * Logs a new message.
     * \param msg Message to log.
     **/
    void log(std::string msg);
    
    /**
     * Scrolls the window.
     * \param numlines Number of lines to scroll. Positive numbers scroll
     * forward, negative numbers scroll backwards.
     **/
    void scroll(int numlines);
    
    virtual void render();
    
protected:
    /**
     * The offset for displaying messages. We use this to create the scrolling
     * effect.
     **/
    int offset;

    std::list<std::string> messages;

    /**
     * Container for the window. Helps us to ease refreshes.
     **/
    PANEL* panel;
    
    /**
     * The window that contains the goodness.
     **/
    WINDOW* window;
private:

};

}}}
