#include "Frontend/Curses/MessageWindow.h"

namespace engine {
    namespace frontend {
        namespace curses {

MessageWindow::MessageWindow() :
    Window(0, 0, COLS - 4, (LINES / 2) - 3)
{}

MessageWindow::MessageWindow(int x, int y, int w, int h) :
    Window(x, y, w, h)
{

}

/**
 * Logs a new message in the window.
 **/
void MessageWindow::log(std::string msg)
{

}

void MessageWindow::render()
{
   
}

void MessageWindow::update()
{

}

}}} /** End namespaces. **/
