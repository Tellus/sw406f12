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

#include "TypeVisitor.h"
using namespace parser;

enum assign_enum {
	ASSIGN_NONE,
	ASSIGN_NUMBER, ASSIGN_STRING,
	ASSIGN_BOOL, ASSIGN_LIST,
	ASSIGN_LIST_LISTS, ASSIGN_REFERENCE
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
		std::map<std::string, symbol*> DeclarationTable;
		std::map<std::string, symbol*> CharacterTable;
		std::map<std::string, symbol*> AbilityTable;
		std::map<std::string, symbol*> AttributeTable;
		std::map<std::string, symbol*> ResourceTable;
		std::map<std::string, symbol*> BehaviourTable;
		std::map<std::string, symbol*> EffectTable;
		std::map<std::string, symbol*> EventTable;
		std::map<std::string, symbol*> ReferenceTable;

	void initiate_table();
	void add_symbol(std::map<std::string, symbol*>* addtable, std::string name, std::map<std::string, symbol*>* reftable, assign_enum assign);
	symbol* lookup_symbol(std::string name, std::map<std::string, symbol*>* looktable);
	symbol* traverse(ASTNode *ast);
	void decorate(ASTNode *node);

	TypeCheck();
	virtual ~TypeCheck();
};
}



#endif /* TYPECHECK_H_ */
