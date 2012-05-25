#include "Frontend/Curses/PlayerWindow.h"

namespace engine { namespace frontend { namespace curses {
 
PlayerWindow::PlayerWindow(int x, int y, int w, int h, Character* p) :
    Window(x, y, w, h)
{
    this->_init(p);    
}
    
PlayerWindow::PlayerWindow(Character* p) :
    Window(0, 0, 30,
                    p->get_attributes()->size() +
                    p->get_resources()->size() +
                    p->get_abilities()->size() + 7)
{
    this->_init(p);
}

void PlayerWindow::_init(Character* c)
{
    this->load_char(c);
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
    mvwprintw(this->window, ++lc, get_leftx(), "Attributes: %5.2f", this->attributes->size());
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

void PlayerWindow::update()
{
    // Stub for now.
    this->load_char(this->player);
}

std::string PlayerWindow::to_string()
{
    return this->player->name;
}

void PlayerWindow::load_char(Character* c)
{
    this->player = c;
    this->resources = &c->resources;
    this->attributes = &c->attributes;
    this->abilities = &c->abilities;
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
