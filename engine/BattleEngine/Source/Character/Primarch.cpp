/*
 * Primarch.cpp
 *
 *  Created on: 18/04/2012
 *      Author: Johannes
 */

#include "Primarch.h"

namespace engine 
{

long Primarch::_id_counter=0;

Primarch::Primarch()
{
    // For new Primarchs, we get new id's.
    this->id = Primarch::get_new_id();
}

Primarch::Primarch(std::string name)
{
    this->name = name;
    this->id = Primarch::get_new_id();
}

Primarch::~Primarch()
{

}

long Primarch::get_new_id()
{
	Primarch::_id_counter += 1;
	return Primarch::_id_counter;
}

std::list<GameEvent*> Primarch::get_pending_events()
{
	// Get all underlying events. This means a single call to the top Primarch
	// will sink to the bottom and get them all.
	for (std::list<Primarch*>::iterator p_iter = this->children.begin();
		 p_iter != this->children.end();
		 p_iter++)
	{
		this->pending_events.merge((*p_iter)->get_pending_events());
	}

    std::list<GameEvent*> to_ret = this->pending_events; // Copies.
    
    this->pending_events.clear();
    
    return to_ret;
}

const std::list<Primarch*>* Primarch::get_children()
{
	return &(this->children);
}

void Primarch::add_child(Primarch* to_add)
{
	this->children.push_back(to_add);
}

void Primarch::remove_child(Primarch* to_remove)
{
	// this->children.remove(to_remove);
	this->remove_child(id);
}

void Primarch::remove_child(int c_id)
{
	for (std::list<Primarch*>::iterator iter = this->children.begin();
		 iter != this->children.end();
		 iter++)
	{
		if ((*iter)->id == c_id)
		{
			this->children.remove(*iter);
		}
	}
}

bool Primarch::has_child(int c_id, bool deep)
{
	for (std::list<Primarch*>::iterator iter = this->children.begin();
		 iter != this->children.end();
		 iter++)
	{
	    // Regular check.
		if ((*iter)->id == c_id) return true;
		else
		{
		    // Deep check.
		    if (deep && ((*iter)->has_child(c_id), deep)) return true;
		}
	}

	return false;
}

bool Primarch::has_child(std::string name, bool deep)
{
	for (std::list<Primarch*>::iterator iter = this->children.begin();
		 iter != this->children.end();
		 iter++)
	{
	    // Regular check.
		if ((*iter)->name == name) return true;
		else
		{
		    // Deep check.
		    if (deep && ((*iter)->has_child(name), deep)) return true;
		}
	}

	return false;
}

Primarch* Primarch::get_child(std::string name, bool deep)
{
    Primarch* to_ret;
    std::list<Primarch*>::iterator finder;
        
    // Shallow search.
    finder = std::find_if(this->children.begin(),
                         this->children.end(),
                         [name](Primarch* cp){ return cp->name == name;});
    
    if (finder == this->children.end() && deep)
    {
        for (std::list<Primarch*>::iterator iter = this->children.begin();
             iter != this->children.end();
             iter++)
        {
            try
            {
                to_ret = (*iter)->get_child(name, deep);
                return to_ret;
            }
            catch (PrimarchDoesNotExistException e)
            {
                // Do nothing, just catch it for safety :D
            }
        }    
    }
	else if (finder != this->children.end())
	{
		return (*finder);
	}
    
    throw PrimarchDoesNotExistException("The requested object is not contained in this Primarch.");
}

Primarch* Primarch::get_child(int c_id, bool deep)
{
    // Performing a prelim check is noble, but costs about as much as the search
    // itself, so let's not do that.
    // if (!this->has_child(c_id, deep))
    //    throw PrimarchDoesNotExistException("The requested object is not contained in this Primarch.");
    
    Primarch* to_ret;
    std::list<Primarch*>::iterator finder;
        
    // Shallow search.
    finder = std::find_if(this->children.begin(),
                         this->children.end(),
                         [c_id](Primarch* cp){ return cp->id == c_id;});
    
    if (finder == this->children.end() && deep)
    {
        for (std::list<Primarch*>::iterator iter = this->children.begin();
             iter != this->children.end();
             iter++)
        {
            try
            {
                to_ret = (*iter)->get_child(c_id, deep);
                return to_ret;
            }
            catch (PrimarchDoesNotExistException e)
            {
                // Do nothing, just catch it for safety :D
            }
        }    
    }
    
    throw PrimarchDoesNotExistException("The requested object is not contained in this Primarch.");
}

std::map<std::string, std::list<callback>> Primarch::get_callbacks()
{
	// Opposed to raised events, callbacks are more persistent.
	// We can't simply purge the list every time, but must construct
	// one hiarchially...billy...silly.
	// TODO: Moar pointers.

	std::map<std::string, std::list<callback>> cb = this->_callbacks;

	for (std::list<Primarch*>::iterator iter = this->children.begin();
		 iter != this->children.end();
		 iter++)
	{
		std::map<std::string, std::list<callback>> tmp = (*iter)->get_callbacks();
		for (std::map<std::string, std::list<callback>>::iterator cb_iter = tmp.begin();
			 cb_iter != tmp.end();
			 cb_iter++)
		{
			cb[(*cb_iter).first].merge((*cb_iter).second);
		}
	}

	return cb;
}

void Primarch::raise_event(std::string name)
{
    GameEvent* e = new GameEvent();
    
    this->pending_events.push_back(
        new GameEvent(this, boost::to_upper_copy(name)));
}

std::string Primarch::get_default_name(std::string in)
{
	return in + "_" + boost::lexical_cast<std::string>(this->id);
}

}
