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

/**
 * The symbol table (active from phase 2 and onwards) contains scope, type and
 * node references to our parsed AST.
 **/
class SymbolTable
{
public:
    /**
     * Initialises a symbol table containing all built-ins.
     **/
	SymbolTable();
	
	/**
	 * Stub deconstructor.
	 **/
	virtual ~SymbolTable();

    /**
     * Singleton of the SymbolTable class.
     **/
	static SymbolTable &handle();

    /**
     * Adds a new symbol to the table.
     * \todo Figure out what <b>all</b> the parameters do. In particular, the
     * difference between target and reference as well as the intention of
     * assigned_from and assigns.
     **/
	void add_symbol(scope *target, std::string key, FORMAT_TYPE assgined_from, FORMAT_TYPE assigns, scope *reference);
	
	/**
	 * Looks up a symbol in the table.
	 * \param s The scope to look in first (see global below).
	 * \param id The name of the symbol to look for.
	 * \param global If true, the global scope is searched if a local scope
	 * lookup fails.
	 * \return The symbol if found, NULL pointer otherwise.
	 **/
	Symbol *lookup(scope *s, std::string id, bool global = false);
	
	/**
	 * Globalises a scope by appending it to the existing global scope.
	 * \param s Scope to globalise.
	 * \return The new scope.
	 **/
	scope global(scope *s);

    /**
     * Scope of all declarations.
     **/
	scope declarations;

    /**
     * Scope of all tokens valid within Character definitions.
     **/
	scope character;
	
	/**
	 * Scope of all things Ability.
	 **/
	scope ability;
	
	/**
	 * Scope of all things valid within a Behaviour definition.
	 **/
	scope behaviour;
	
	/**
	 * Scope of all things valid in an Event.
	 **/
	scope event;

    /**
     * Scope of valid Attribute tokens.
     **/
	scope attribute;

    /**
     * Scope of things valid within a Resource definition.
     **/
	scope resource;

    /**
     * Scope of things valid within a continuous effect (unused).
     **/
	scope con_effect;


private:
    /**
     * Initialises the SymbolTable with all built-ins. Hardcoding abound!
     **/
	void initialize();
};

} /* namespace typecheck */
