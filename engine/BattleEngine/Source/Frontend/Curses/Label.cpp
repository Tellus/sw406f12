#include "Frontend/Curses/Label.h"

namespace engine { namespace frontend { namespace curses {

Label::Label(std::string text)
{
    this->label = text;
}

void Label::draw(WINDOW* on)
{
    mvwprintw(on, this->y, this->x, this->label.c_str());
}

void Label::set_text(std::string text)
{
    this->label = text;
}

std::string Label::get_text()
{
    return this->label;
}

void Label::update()
{
    // Nothing important to be done.
}

void Label::render()
{
//        if (this->parent == NULL) return;
//        mvwprintw(this->parent, this->y, this->y, this->label.c_str());
}

void Label::move_to(int x, int y)
{
    _label_move(x, y);
}

void Label::move_by(int x, int y)
{
    _label_move(this->x+x, this->y+y);
}

void Label::clear()
{
    move(this->y, this->x);
    for (unsigned int i = 0; i < this->label.size(); i++)
    {
        putchar(' ');
    }
}

std::string Label::to_string()
{
    return this->label;
}

void Label::_label_move(int x, int y)
{
    this->clear();
    Entity::move_to(x, y);
    mvwprintw(this->parent, this->y, this->x, this->label.c_str());
    mvprintw(this->y, this->x, this->label.c_str());
}

}}}
