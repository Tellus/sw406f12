/*
 * TypeCheck.h
 *
 *  Created on: Apr 13, 2012
 *      Author: nattfari
 */

#ifndef TYPECHECK_H_
#define TYPECHECK_H_

#include "../Parser/ASTNode.h"
#include <string>
#include <map>
#include <iostream>

using namespace parser;

enum assign_enum {
	ASSIGN_NONE,
	ASSIGN_NUMBER, ASSIGN_STRING,
	ASSIGN_BOOL, ASSIGN_LIST,
	ASSIGN_LIST_LISTS
};

struct symbol
{
	std::map<std::string, symbol*>* type;
	assign_enum assign;
};

namespace typec {

class TypeCheck {
public:
	//Initialize tables for all types
		std::map<std::string, symbol*> Declaration;
		std::map<std::string, symbol*> CharacterTable;
		std::map<std::string, symbol*> Ability;
		std::map<std::string, symbol*> Attribute;
		std::map<std::string, symbol*> Resource;
		std::map<std::string, symbol*> Behaviour;
		std::map<std::string, symbol*> Effect;
		std::map<std::string, symbol*> Event;

	void initiate_table();
	void add_symbol(std::map<std::string, symbol*>* addtable, std::string name, std::map<std::string, symbol*>* reftable, assign_enum assign);
	symbol* lookup_symbol(std::string name, std::map<std::string, symbol*>* looktable);
	void decorate(ASTNode *node);

	TypeCheck();
	virtual ~TypeCheck();
};
}



#endif /* TYPECHECK_H_ */
