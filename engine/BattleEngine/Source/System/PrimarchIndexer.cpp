#include "PrimarchIndexer.h"

namespace engine
{

PrimarchIndexer::PrimarchIndexer()
{
	// Why no implement?
}


PrimarchIndexer::~PrimarchIndexer()
{
	for (std::list<Primarch*>::iterator iter = this->children.begin();
		iter != this->children.end();
		iter++)
	{
		delete (*iter);
	}
}

void PrimarchIndexer::_init()
{
	this->children = std::list<Primarch*>();
}

Primarch* PrimarchIndexer::get_child_by_id(int c_id)
{
	std::list<Primarch*>::iterator finder;
    
    finder = std::find_if(this->children.begin(),
						  this->children.end(),
						  [c_id](Primarch* cp){ return cp->id == c_id;});
    
    if (finder == this->children.end())
	{
		throw PrimarchDoesNotExistException("The requested Character was not in the list.");
	}
	else
	{
		return (*finder);
	}
}

/**
 * Adds a character to the list of children. Will use the pointer given
 * without copying.
 **/
void PrimarchIndexer::add_child(Primarch *to_add)
{
    this->children.push_back(to_add);
}

bool PrimarchIndexer::has_child(int c_id)
{
	std::list<Primarch*>::iterator finder;
    
    finder = std::find_if(this->children.begin(),
						  this->children.end(),
						  [c_id](Primarch* cp){ return cp->id == c_id;});
    
    if (finder == this->children.end()) return false;
    else return true;
}

}
