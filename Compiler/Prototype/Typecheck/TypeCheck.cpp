/*
 * TypeCheck.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: nattfari
 */

#include "TypeCheck.h"

namespace typec {
/*symbol* TypeCheck::lookup_symbol(std::string name, std::map<std::string, symbol*>* looktable)
{
	symbol* retsym = NULL;



	return retsym;
}*/

void TypeCheck::add_symbol(std::map<std::string, symbol*>* addtable, std::string name, std::map<std::string, symbol*>* reftable, assign_enum assign)
{
	//std::map<std::string, symbol*>::iterator add_iterator;
	//std::pair<std::map<std::string, symbol*>::iterator, bool> ret;

	symbol* make_struct = new symbol;
	make_struct->type = reftable;
	make_struct->assign = assign;

	addtable->insert(std::pair<std::string, symbol*>(name, make_struct));
}

void TypeCheck::initiate_table()
{
	add_symbol(&CharacterTable, "name", NULL, ASSIGN_STRING);
	add_symbol(&CharacterTable, "health", &Resource, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "strength", &Attribute, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "mana", &Resource, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "defense", &Attribute, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "intelligence", &Attribute, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "stamina", &Attribute, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "luck", &Attribute, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "magic_defense", &Attribute, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "evasion", &Attribute, ASSIGN_NUMBER);

	add_symbol(&Resource, "current", NULL, ASSIGN_NUMBER);
	add_symbol(&Resource, "max", NULL, ASSIGN_NUMBER);
	add_symbol(&Resource, "min", NULL, ASSIGN_NUMBER);
	add_symbol(&Resource, "percent", NULL, ASSIGN_NUMBER);



	std::map<std::string, symbol*>::iterator printer;
	std::cout << "The Charactertable contains the following keys: ";
	for (printer = CharacterTable.begin(); printer != CharacterTable.end(); printer++)
	{
		std::cout << printer->first <<" " << printer->second->type << std::endl;
	}

}

TypeCheck::TypeCheck() {
	// TODO Auto-generated constructor stub
}

TypeCheck::~TypeCheck() {
	// TODO Auto-generated destructor stub
}

}
