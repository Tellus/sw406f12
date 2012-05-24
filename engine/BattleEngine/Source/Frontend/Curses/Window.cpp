#include "Frontend/Curses/Window.h"

namespace engine {
    namespace frontend {
        namespace curses {

Window::Window(int x, int y, int w, int h) :
    Entity(x, y)
{
    this->height = h;
    this->width = w;
    
    this->window = newwin(h, w, y, x);
    this->panel = new_panel(this->window);
}

void Window::move_to(int x, int y)
{
    this->_window_move(x, y);
}

void Window::move_by(int x, int y)
{
    this->_window_move(this->x + x, this->y + y);
}

void Window::_window_move(int x, int y)
{
    this->clear(false);
    Entity::move_to(x,y);
    mvwin(this->window, this->y, this->x);
    box(this->window, 0, 0);
}

void Window::clear(bool del)
{
    wborder(this->window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(this->window);
    if (del)
    {
        delwin(this->window);
    }
}

}}}
