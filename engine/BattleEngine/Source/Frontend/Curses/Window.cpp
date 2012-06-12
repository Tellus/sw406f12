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
}

void Window::do_scroll(int numlines)
{
    wscrl(this->window, numlines);
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

int Window::get_top()
{
    return this->y;
}

int Window::get_left()
{
    return this->x;
}

int Window::get_right()
{
    return this->get_left() + this->width;
}

int Window::get_bottom()
{
    // Calculation: y + height - 1
    // The -1 is to get us within the window boundaries, if I calculate correctly.
    return this->get_top() + this->height;
}

void Window::render()
{
    // Make window box.
    box(this->window, 0, 0);
    mvwprintw(this->window, 0, 3, this->title.c_str());

    /** Uncomment to show some debugging symbols on window corners.
    mvwprintw(this->window, 0, 0, "*");
    mvwprintw(this->window, this->get_height(), 0, "*");
    mvwprintw(this->window, 0, this->get_width(), "*");
    mvwprintw(this->window, this->get_height(), this->get_width(), "*");
    **/
}

void Window::update()
{
    // Stub.
}

int Window::get_width() { return this->width - 1; }
int Window::get_height() { return this->height - 1; }

void Window::pre_render(){ wnoutrefresh(this->window); }
    
void Window::post_render(){ /* Stubbed */ }

}}}
