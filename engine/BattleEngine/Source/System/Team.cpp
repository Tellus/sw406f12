#include "Team.h"

namespace engine
{
 
Team::Team(int id)
{
    this->members = std::list<Character*>();
    this->id = id;
}

void Team::add_character(Character *to_add)
{
    this->members.push_back(to_add);
}

void Team::remove_character(Character *to_remove)
{
    this->members.remove(to_remove);
}

void Team::remove_character(int id)
{
    this->members.remove_if([id](Character *t){return t->id == id;});
}

bool Team::has_character(int id)
{
    std::list<Character*>::iterator finder;
    
    finder = std::find_if(this->members.begin(), this->members.end(), [id](Character *t){ return t->id == id;});
    
    if (finder == this->members.end()) return false;
    else return true;
}

Character* Team::get_character(int id)
{
    std::list<Character*>::iterator finder;
    
    finder = std::find_if(this->members.begin(), this->members.end(), [id](Character *t){ return t->id == id;});
    
    if (finder == this->members.end()) return NULL;
    else return *finder;
}

Character *Team::front()
{
    return this->members.front();
}

}
