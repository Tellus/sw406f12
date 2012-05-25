#pragma once

#include "Headers/Frontend/Curses/Window.h"

#include <list>

namespace engine {
    namespace frontend {
        namespace curses {

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
     * Creates a new messaging window.
     **/
    MessageWindow();
    
    /**
     * Logs a new message.
     * \param msg Message to log.
     **/
    void log(std::string msg);
    
    virtual void render();
    
    virtual void update();
    
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
