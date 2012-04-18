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
    this->characters = new std::list<Character*>();
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

}

/**
 * Adds a character to the list of characters. Will use the pointer given
 * without copying.
 **/
void GameState::add_character(Character *to_add)
{
    this->characters.push_back(to_add);
}

/**
 * Copies a character into the GameState, leaving the original unaffected.
 **/
void add_character_by_copy(const Character& copy)
{
    this->characters.push_back(Character(copy));
}

Character *get_rgr(RGR_Enum rgr)
{
    switch(rgr)
    {
        case ENEMY:
        {
            // RGR_Enum.ENEMY
            int team = this->current_char->team_index;
            
            std::list<Team*>::iterator iter;
            
            for (iter = teams.begin(); iter != teams.end(); iter++)
            {
                Team *tmp = *iter;
                if (!tmp->has_character(this->current_char->id))
                {
                    return tmp->front();
                }
            }
            break;
        }
    }
}

} /* namespace engine */
