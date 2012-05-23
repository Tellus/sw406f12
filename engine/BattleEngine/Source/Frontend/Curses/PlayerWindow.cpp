#include "Frontend/Curses/PlayerWindow.h"

namespace engine { namespace frontend { namespace curses {
    
PlayerWindow::PlayerWindow(Character* p)
{
    this->_init(0, 0, (COLS-2) / 2, LINES - 20);
    this->player = p;
    this->load_char(p);
}

void PlayerWindow::move_to(int x, int y)
{
    this->_window_move(x, y);
}

void PlayerWindow::move_by(int x, int y)
{
    this->_window_move(this->x + x, this->y + y);
}

void PlayerWindow::_window_move(int x, int y)
{
    this->clear(false);
    Entity::move_to(x,y);
    mvwin(this->window, this->y, this->x);
    box(this->window, 0, 0);
}

void PlayerWindow::render()
{
    mvwprintw(this->window, 0, 3, this->player->name.c_str());
    
    int lc = 1;
    
    wattron(this->window, A_BOLD | A_UNDERLINE);
    mvwprintw(this->window, lc++, get_leftx(), "Resources: %i", this->resources->size());
    wattrset(this->window, A_NORMAL);
    for (std::map<std::string, Resource*>::iterator iter = this->resources->begin();
         iter != this->resources->end();
         iter++)
    {
        Resource* res = iter->second;
    
        mvwprintw(this->window, lc, get_leftx(), res->name.c_str());
        mvwprintw(this->window, lc, get_rightx(), "%f", res->get_current());
        lc++;
    }
    
    wattron(this->window, A_BOLD | A_UNDERLINE);
    mvwprintw(this->window, ++lc, get_leftx(), "Attributes: %i", this->attributes->size());
    wattrset(this->window, A_NORMAL);
    lc++;
    
    for (std::map<std::string, Attribute*>::iterator riter = this->attributes->begin();
         riter != this->attributes->end();
         riter++)
    {
        Attribute* attr = riter->second;
        
        mvwprintw(this->window, lc, get_leftx(), attr->name.c_str());
        mvwprintw(this->window, lc, get_rightx(), "%i", static_cast<int>(attr->get_current()));
        lc++;
    }
    
    wattron(this->window, A_BOLD | A_UNDERLINE);
    mvwprintw(this->window, ++lc, get_leftx(), "Abilities: %i", this->abilities->size());
    wattrset(this->window, A_NORMAL);
    lc++;
    
    for (std::map<std::string, Ability*>::iterator riter = this->abilities->begin();
         riter != this->abilities->end();
         riter++)
    {
        Ability* attr = riter->second;
        
        mvwprintw(this->window, lc, get_leftx(), attr->name.c_str());
        lc++;
    }
    
    lc++;
}

void PlayerWindow::clear(bool del)
{
    wborder(this->window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(this->window);
    if (del)
    {
        delwin(this->window);
    }
}

void PlayerWindow::update()
{
    // Stub for now.
}

std::string PlayerWindow::to_string()
{
    return this->player->name;
}

void PlayerWindow::load_char(Character* c)
{
    this->resources = &c->resources;
    this->attributes = &c->attributes;
    this->abilities = &c->abilities;
}

void PlayerWindow::_init(int nx, int ny, int nw, int nh)
{
    this->x = nx;
    this->y = ny;
    this->height = nh;
    this->width = nw;
    this->window = newwin(this->height,
                          this->width,
                          this->x,
                          this->y);
    this->move_to(1,1);
}

int PlayerWindow::get_leftx()
{
    return 2;
}

int PlayerWindow::get_rightx()
{
    return this->width/2 + 2;
}

}}}
