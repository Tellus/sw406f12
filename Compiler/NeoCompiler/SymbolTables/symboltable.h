/// symboltable.h
///
/// This file the SymbolTable class,
/// along with structs and typedefs for typechecking;

#pragma once

#include "types.h"
#include "symbol.h"

#include <map>
#include <string>

namespace typecheck
{

class SymbolTable
{
public:
	SymbolTable();
	virtual ~SymbolTable();

	static SymbolTable &handle();

	void add_symbol(scope *target, std::string key, FORMAT_TYPE assgined_from, FORMAT_TYPE assigns, scope *reference);
	Symbol *lookup(scope *s, std::string id, bool global = false);
	scope global(scope *s);

	scope declarations;

	scope character;
	scope ability;
	scope behaviour;
	scope event;

	scope attribute;
	scope resource;
	scope con_effect;


private:
	void initialize();
};

} /* namespace typecheck */
