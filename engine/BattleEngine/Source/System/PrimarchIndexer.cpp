#include "PrimarchIndexer.h"

namespace engine
{

PrimarchIndexer::PrimarchIndexer()
{
	// Why no implement?
}


PrimarchIndexer::~PrimarchIndexer()
{
	for (std::list<Character*>::iterator iter = this->characters.begin();
		iter != this->characters.end();
		iter++)
	{
		delete (*iter);
	}
}

void PrimarchIndexer::_init()
{
	this->characters = std::list<Character*>();
}

Character* PrimarchIndexer::get_character_by_id(int c_id)
{
	std::list<Character*>::iterator finder;
    
    finder = std::find_if(this->characters.begin(),
						  this->characters.end(),
						  [c_id](Character* cp){ return cp->id == c_id;});
    
    if (finder == this->characters.end())
	{
		throw PrimarchDoesNotExistException("The requested Character was not in the list.");
	}
	else
	{
		return (*finder);
	}
}

/**
 * Adds a character to the list of characters. Will use the pointer given
 * without copying.
 **/
void PrimarchIndexer::add_character(Character *to_add)
{
    this->characters.push_back(to_add);
}

bool PrimarchIndexer::has_character(int c_id)
{
	std::list<Character*>::iterator finder;
    
    finder = std::find_if(this->characters.begin(),
						  this->characters.end(),
						  [c_id](Character* cp){ return cp->id == c_id;});
    
    if (finder == this->characters.end()) return false;
    else return true;
}

}