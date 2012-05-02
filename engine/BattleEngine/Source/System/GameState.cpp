/*
 * GameState.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "GameState.h"

namespace engine {

std::map<RGR_Enum, RGRIdentifier*> GameState::rgr_identifiers = std::map<RGR_Enum, RGRIdentifier*>();

GameState::GameState() {
	// TODO Auto-generated constructor stub
}

GameState::~GameState() {
	// TODO Auto-generated destructor stub
}

/**
 * Copy constructor. Will copy the passed GameState into a new one, distinct
 * from the original.
 **/
GameState::GameState(const GameState& copy):
    characters(copy.characters)
{
    std::cout << "GameState: " << &copy << " copying into " << this << "\n";
    
    this->characters = std::list<Character*>();
    std::list<Character*> remote = copy.characters;
    
    std::cout << "\tCharacters:\n";
    for (std::list<Character*>::iterator char_iter = remote.begin();
         char_iter != remote.end();
         char_iter++)
    {
        Character *c = *char_iter;
        Character *nc = new Character(*c);
        this->characters.push_back(nc);
        
        std::cout << "\t(" << c->id << ")\t" << c << '\t' << c->name << '\n';
        std::cout << "\t\t TO \n";
        std::cout << "\t(" << nc->id << ")\t" << nc << '\t' << nc->name << '\n';
    }
    
    this->current_char = this->get_char_by_id(copy.current_char->id);
}

/**
 * Adds a character to the list of characters. Will use the pointer given
 * without copying.
 **/
void GameState::add_character(Character *to_add)
{
    this->characters.push_back(to_add);
}

Character *GameState::get_rgr(RGR_Enum rgr)
{
    if (GameState::rgr_identifiers.count(rgr) <= 0)
    {
		std::string str_tmp = "No handler for " + RGR_List::to_string(rgr) + " was found.";
		throw InvalidRGRException(str_tmp);
    }
        
    // Retrieve the proper identifier instance.
    RGRIdentifier *ident = GameState::rgr_identifiers[rgr];
    
    Character *found = ident->identify(this);
    
    if (found == NULL)
    {
		std::string str_tmp = "No results when requesting " + RGR_List::to_string(rgr) + ".";
        throw InvalidRGRException(str_tmp);
    }
    
    return found;
}

void GameState::pretty_print()
{
    std::cout << "GameState " << this << '\n';
    std::cout << "Characters:\n";
    for (std::list<Character*>::iterator char_iter = this->characters.begin();
         char_iter != this->characters.end();
         char_iter++)
    {
        Character *c = *char_iter;
        std::cout << "\t(" << c->id << ")\t" << c << '\t' << c->name;
        if ((*char_iter)->id == this->current_char->id) std::cout << " (*)";
        std::cout << '\n';
    }
    
    if (GameState::rgr_identifiers.size() == 0)
    {
        std::cout << "RGR identifiers: None!\n";
    }
    else
    {
        std::cout << "Registered RGR identifiers:\n";
        for (std::map<RGR_Enum,RGRIdentifier*>::iterator rgr_iter = GameState::rgr_identifiers.begin();
             rgr_iter != GameState::rgr_identifiers.end();
             rgr_iter++)
        {
            std::cout << '\t' << RGR_List::to_string(rgr_iter->first) << '\n';
        }
    }
}

Character* GameState::get_char_by_id(int id)
{
    for (std::list<Character*>::iterator iter = this->characters.begin();
         iter != this->characters.end();
         iter++)
    {
        if ((*iter)->id == id) return *iter;
    }
    
    return NULL;
}

void GameState::register_identifier(RGRIdentifier *r)
{
    GameState::rgr_identifiers[r->rgr] = r;
}

} /* namespace engine */
