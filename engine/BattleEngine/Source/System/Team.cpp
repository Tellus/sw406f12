#include "Team.h"

namespace engine
{
 
Team::Team(int id)
{
    this->members = std::list<int>();
    this->id = id;
}

void Team::add_character(Character *to_add)
{
	this->members.push_back(to_add->id);
}

void Team::remove_character(Character *to_remove)
{
	this->remove_character(to_remove->id);
}

void Team::remove_character(int id)
{
	this->members.remove(id);
}

bool Team::has_character(int id)
{
    std::list<int>::iterator finder;
    
    finder = std::find_if(this->members.begin(), this->members.end(), [id](int t){ return t == id;});
    
    if (finder == this->members.end()) return false;
    else return true;
}

int Team::first_char()
{
    return this->members.front();
}

}
