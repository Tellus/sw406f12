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


} /* namespace engine */
