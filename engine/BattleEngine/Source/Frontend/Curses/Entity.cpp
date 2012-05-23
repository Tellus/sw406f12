#include "Frontend/Curses/Entity.h"

namespace engine { namespace frontend { namespace curses {

void Entity::move_to(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Entity::move_by(int x, int y)
{
    this->x += x;
    this->y += y;
}

std::string Entity::to_string() { return ""; }

}}}
