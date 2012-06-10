#include "Frontend/Curses/Entity.h"

namespace engine {
    namespace frontend {
        namespace curses {

Entity::Entity()
{}

Entity::Entity(int x, int y)
{
    this->x = x;
    this->y = y;
}

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

int Entity::get_x(){ return this->x; }
int Entity::get_y(){ return this->y; }

std::string Entity::to_string() { return ""; }

}}}
