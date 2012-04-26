/*
 * GameState.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "GameState.h"

namespace engine {

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
    std::cout << "GameState: " << &copy << " copied into " << this << "\n";
    
    this->characters = std::list<Character*>();
    std::list<Character*> remote = copy.characters;
    
    for (std::list<Character*>::iterator char_iter = remote.begin();
         char_iter != remote.end();
         char_iter++)
     {
        this->characters.push_back(new Character(**char_iter));
     }
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
    if (this->rgr_identifiers.count(rgr) < 0)
    {
        std::cout << "No handler for " << RGR_List::to_string(rgr) << " was found.";
        return NULL;
    }
        
    // Retrieve the proper identifier instance.
    RGRIdentifier *ident = this->rgr_identifiers[rgr];
    
    return ident->identify(this);
}

void GameState::pretty_print()
{
    std::cout << "GameState " << this << '\n';
    std::cout << "Characters:\n";
    for (std::list<Character*>::iterator char_iter = this->characters.begin();
         char_iter != this->characters.end();
         char_iter++)
    {
        std::cout << '\t' << (*char_iter)->name << '\t' << *char_iter;
        if ((*char_iter)->id == this->current_char->id) std::cout << " (*)";
        std::cout << '\n';
    }
    
    std::cout << "Registered RGR identifiers:\n";
    for (std::map<RGR_Enum,RGRIdentifier*>::iterator rgr_iter = this->rgr_identifiers.begin();
         rgr_iter != this->rgr_identifiers.end();
         rgr_iter++)
    {
        std::cout << '\t' << RGR_List::to_string(rgr_iter->first) << '\n';
    }
}

} /* namespace engine */
