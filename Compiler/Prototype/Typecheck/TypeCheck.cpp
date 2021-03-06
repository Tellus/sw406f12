/*
 * TypeCheck.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: nattfari
 */

#include "TypeCheck.h"

using namespace parser;

namespace typec {

symbol* TypeCheck::lookup_symbol(std::string name, std::map<std::string, symbol*>* looktable)
{
	if (looktable->count(name) == 0)
		return NULL;

	return (*looktable)[name];
}

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
	// Declaration table
	add_symbol(&DeclarationTable, "Character", &CharacterTable, ASSIGN_NONE);
	add_symbol(&DeclarationTable, "Ability", &AbilityTable, ASSIGN_NONE);
	add_symbol(&DeclarationTable, "Behaviour", &BehaviourTable, ASSIGN_NONE);
	add_symbol(&DeclarationTable, "Event", &EventTable, ASSIGN_NONE);
	//Character table initialized with all constant symbols
	add_symbol(&CharacterTable, "name", NULL, ASSIGN_STRING);
	add_symbol(&CharacterTable, "health", &ResourceTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "strength", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "mana", &ResourceTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "defense", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "intelligence", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "stamina", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "luck", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "magic_defense", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "evasion", &AttributeTable, ASSIGN_NUMBER);
	add_symbol(&CharacterTable, "this", &CharacterTable, ASSIGN_NONE);
	//Resource table initialized with all constant symbols
	add_symbol(&ResourceTable, "current", NULL, ASSIGN_NUMBER);
	add_symbol(&ResourceTable, "max", NULL, ASSIGN_NUMBER);
	add_symbol(&ResourceTable, "min", NULL, ASSIGN_NUMBER);
	add_symbol(&ResourceTable, "percent", NULL, ASSIGN_NUMBER);
	add_symbol(&ResourceTable, "owner", &CharacterTable, ASSIGN_NONE);
	add_symbol(&ResourceTable, "this", &ResourceTable, ASSIGN_NONE);
	//Resource table initialized with all constant symbols
	add_symbol(&AttributeTable, "initial", NULL, ASSIGN_NUMBER);
	add_symbol(&AttributeTable, "current", NULL, ASSIGN_NUMBER);
	add_symbol(&AttributeTable, "owner", &CharacterTable, ASSIGN_NONE);
	add_symbol(&AttributeTable, "this", &AttributeTable, ASSIGN_NONE);
	//Behaviour table initialized with all constant symbols
	add_symbol(&BehaviourTable, "positive", NULL, ASSIGN_LIST_LISTS);
	add_symbol(&BehaviourTable, "negative", NULL, ASSIGN_LIST_LISTS);
	add_symbol(&BehaviourTable, "owner", &CharacterTable, ASSIGN_NONE);
	add_symbol(&BehaviourTable, "this", &BehaviourTable, ASSIGN_NONE);
	//Ability table initialized with all constant symbols
	add_symbol(&AbilityTable, "costs", NULL, ASSIGN_LIST_LISTS);
	add_symbol(&AbilityTable, "targets", NULL, ASSIGN_LIST);
	add_symbol(&AbilityTable, "effects", NULL, ASSIGN_LIST);
	add_symbol(&AbilityTable, "owner", &CharacterTable, ASSIGN_NONE);
	add_symbol(&AbilityTable, "this", &AbilityTable, ASSIGN_NONE);
	//Event table initialized with all constant symbols
	add_symbol(&EventTable, "triggers", NULL, ASSIGN_LIST);
	add_symbol(&EventTable, "conditions", NULL, ASSIGN_LIST);
	add_symbol(&EventTable, "actions", NULL, ASSIGN_LIST);
	add_symbol(&EventTable, "owner", &CharacterTable, ASSIGN_NONE);
	add_symbol(&EventTable, "this", &EventTable, ASSIGN_NONE);
	//Effect table initialized with all constant symbols
	add_symbol(&EffectTable, "effect", NULL, ASSIGN_LIST);
	add_symbol(&EffectTable, "owner", &CharacterTable, ASSIGN_NONE);
	add_symbol(&EffectTable, "this", &EffectTable, ASSIGN_NONE);

	/* Print for debug
	std::map<std::string, symbol*>::iterator printer;
	std::cout << "The Character table contains the following keys: ";
	for (printer = CharacterTable.begin(); printer != CharacterTable.end(); printer++)
	{
		std::cout << printer->first <<" " << printer->second->type << " -- " << printer->second->assign << std::endl;
	}
	*/

}
//Traverse, decorate the ASTNodes with type information and perform basic type checking
bool TypeCheck::decorate(ASTNode *node, std::map<std::string, symbol*> *scope)
{
	symbol *temp;
	primitive_type type = T_NULL;

	for (list<ASTNode*>::iterator i = node->children.begin(); i != node->children.end(); i++)
	{
		switch (node->type)
		{
			case(NODE_DECLARATION):
				if ((*i)->type == NODE_SUBCLASS) // TODO For now, inheritance is disabled!
				{
					if (this->lookup_symbol((*i)->data, &(this->DeclarationTable)) != NULL)
						return false; // Duplicate declaration
				}

				if ((*i)->type == NODE_SUPERCLASS)
				{
					temp = this->lookup_symbol((*i)->data, &(this->DeclarationTable));
					if (temp == NULL)
						return false; // Missing superclass

					scope = temp->type;
				}
				break;
			default:
				break;
		}

		/*
		 * Recursive Decoration call
		 */
		if (!this->decorate(*i, scope))
			return false;

		/*
		 * Post Decoration checks
		 */
		switch(node->type)
		{
			case NODE_EXPRESSION:
			case NODE_TERM:
			case NODE_FACTOR:
				if (type == T_NULL)
					type = (*i)->dec->type;
				else if (type != (*i)->dec->type && (*i)->dec->type != T_NULL)
					return false; // Illegal operation

				break;
			default:
				break;
		}
	}

	//Handling leaves
	switch(node->type)
	{
		case NODE_STRING:
			node->dec = new decoration;
			node->dec->type = T_STRING;
			break;
		case NODE_BOOL:
			node->dec = new decoration;
			node->dec->type = T_BOOLEAN;
			break;
		case NODE_NUMBER:
			node->dec = new decoration;
			node->dec->type = T_NUMBER;
			break;
		case NODE_ASSIGNMENT:
			node->dec = node->children.back()->dec;
			break;
		case NODE_EXPRESSION:
		case NODE_TERM:
		case NODE_FACTOR:
			node->dec = node->children.front()->dec;
			break;
		default:
			if (node->children.size() == 0)
				node->dec = new decoration;
				node->dec->type = T_NULL;
			break;
	}

	return true;
}

TypeCheck::TypeCheck() {
	// TODO Auto-generated constructor stub
}

TypeCheck::~TypeCheck() {
	// TODO Auto-generated destructor stub
}

}
