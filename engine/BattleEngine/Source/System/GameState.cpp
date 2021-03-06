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
	this->_init();
}

GameState::~GameState() {
	// TODO Auto-generated destructor stub
}

GameState *GameState::clone()
{
	GameState* new_state = new GameState();

	for (std::list<Primarch*>::iterator char_iter = this->children.begin();
         char_iter != this->children.end();
         char_iter++)
    {
		Character *c = dynamic_cast<Character*>((*char_iter)->clone(true));

		new_state->add_child(c);
    }
    
	new_state->current_char = dynamic_cast<Character*>(new_state->get_child_by_id(this->current_char->id));

	// Copying by list. Should be quite safe with this pointer-less ordeal.
	new_state->teams = this->teams;

	return new_state;
}

void GameState::_init()
{
	// Most inits handled by PrimarchIndexer.
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

	frontend::PrettyPrinter::print("Teams:\n");

	for (std::list<Team*>::iterator team_iter = this->teams.begin();
		 team_iter != this->teams.end();
		 team_iter++)
	{
		std::cout << ">> " << (*team_iter)->id << '\n';
		for (std::list<int>::iterator char_iter = (*team_iter)->members.begin();
			 char_iter != (*team_iter)->members.end();
			 char_iter++)
		{
			this->get_child_by_id((*char_iter))->pretty_print();
		}
	}

	std::cout << "-------------------------------\n";
}

void GameState::register_identifier(RGRIdentifier *r)
{
    GameState::rgr_identifiers[r->rgr] = r;
}

// Sets a Character to be on a specific team. Vital for some RGRIdentifiers to work properly.
bool GameState::set_team_aff(int t_id, Character* to_set)
{
	// Start by removing from all other teams.
	std::list<Team*>::iterator iter;

	// Find the correct team. We can shave off some processing time by having it early.
	Team* tp = NULL;

	// Finding the correct team.
	// std::cout << "Running through teams.\n";
	for (iter = this->teams.begin();
		 iter != this->teams.end();
		 iter++)
	{
		if ((*iter)->id == t_id)
		{
			// std::cout << "Found " << (*iter)->id << '\n';
			tp = (*iter);
			iter = this->teams.end();
			break;
		}
	}

	if (tp == NULL)
	{
		// Create new team.
		tp = new Team(t_id);
		tp->add_character(to_set);
		
		this->teams.push_back(tp);

		// frontend::PrettyPrinter::print("Team did not exist. Created and char added.\n");

		return true;
	}

	for (iter = this->teams.begin();
		 iter != this->teams.end();
		 iter++)
	{
		if ((*iter)->has_character(to_set->id))
		{
			if ((*iter)->id == tp->id)
			{
				// frontend::PrettyPrinter::print("Character already on requested team. Exiting.\n");
				return true; // Skip everything else if the character was already on the team.
			}
			else
			{
				(*iter)->remove_character(to_set->id);
				tp->add_character(to_set);

				// frontend::PrettyPrinter::print("Character added succesfully.\n");

				return true;
			}
		}
	}

	// frontend::PrettyPrinter::print("Something fucked up happened. Check debug log.\n");

	return false;
}

// Finds the team that the Character is on, if any.
int GameState::get_char_team(int c_id)
{
	for (std::list<Team*>::iterator iter = this->teams.begin();
		 iter != this->teams.end();
		 iter++)
	{
		if ((*iter)->has_character(c_id))
			return (*iter)->id;
	}

	// Phail.
	return -1;
}

// Finds the team that the Character is on, if any.
int GameState::get_char_team(Character* c_id)
{
	return this->get_char_team(c_id->id);
}

Character* GameState::get_target()
{
	return this->target_character;
}

int GameState::max_team_id()
{
	int hi = -std::numeric_limits<int>::infinity();

	int to_test;

	for (std::list<Team*>::iterator iter = this->teams.begin();
		iter != this->teams.end();
		iter++)
	{
		to_test = (*iter)->id;
		//  hi = std::max(hi, to_test);
		hi = hi < to_test ? to_test : hi;
	}

	return hi;
}

/**
 * Sets a globalised target var. This is primarily used by the TARGET identifier,
 * but can have several other uses, too.
 * \param t Character to target.
 **/ 
void GameState::set_target(Character *t)
{
	this->target_character = t;
}

}
