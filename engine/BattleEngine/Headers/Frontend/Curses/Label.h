#pragma once

#include "Frontend/Curses/Entity.h"

namespace engine { namespace frontend { namespace curses {

class Label : public Entity
{
public:
    WINDOW* parent;

    Label(std::string text);
    
    void draw(WINDOW* on);
    
    void set_text(std::string text);
    
    std::string get_text();
    
    virtual void update();
    
    virtual void render();
    
    void move_to(int x, int y);
    
    void move_by(int x, int y);
    
    void clear();
    
    std::string to_string();
protected:
    void _label_move(int x, int y);
    
private:
    std::string label;
};

}}}
