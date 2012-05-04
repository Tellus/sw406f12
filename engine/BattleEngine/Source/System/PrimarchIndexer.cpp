#include "PrimarchIndexer.h"

namespace engine
{

PrimarchIndexer::PrimarchIndexer()
{
	// Why no implement?
}


PrimarchIndexer::~PrimarchIndexer()
{
	// Why no implement?
}

void PrimarchIndexer::_init()
{
	this->characters = std::list<Character*>();
}

Character* PrimarchIndexer::get_character_by_id(int c_id)
{
	for (std::list<Character*>::iterator iter = this->characters.begin();
		 iter != this->characters.begin();
		 iter++)
	{
		if ((*iter)->id == c_id) return *iter;
	}

	throw PrimarchDoesNotExistException("The requested Character was not in the list.");
}

}