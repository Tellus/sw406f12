#pragma once

#include "types.h"

#include <string>
#include <map>

namespace typecheck
{

struct Symbol; // Forward declaration


typedef std::map<std::string, Symbol*> scope;

/**
 * The symbol goes into the SymbolTable and represents a single declared
 * node in the AST.
 * \todo Turn this into a proper class. This thing is mixing methods and
 * members in one.
 **/
struct Symbol
{
	FORMAT_TYPE assigned_from;
	FORMAT_TYPE assigns;
	
	/**
	 * Pointer to the scope that this symbol resides in.
	 **/
	scope *reference;
	
	/**
	 * Constru... WTF?!
	 **/
	Symbol(FORMAT_TYPE af, FORMAT_TYPE a, scope *r) :
		assigned_from(af),
		assigns(a),
		reference(r)
	{ }
};

} /* namespace typecheck */
