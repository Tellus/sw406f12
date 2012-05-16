/// symboltable.cpp
///
/// This file contains ...

#include "symboltable.h"

namespace typecheck
{

SymbolTable::SymbolTable()
{
	this->initialize();
}

SymbolTable::~SymbolTable()
{
	// TODO: Clear the tables
}

SymbolTable &SymbolTable::handle()
{
	static SymbolTable table;
	return table;
}

void SymbolTable::initialize()
{
	this->add_symbol(&this->declarations, "Character", MetatypeNone, TypeReferenceCharacter, &this->character);
	this->add_symbol(&this->declarations, "Ability", MetatypeNone, TypeReferenceAbility, &this->ability);
	this->add_symbol(&this->declarations, "Behaviour", MetatypeNone, TypeReferenceBehaviour, &this->behaviour);
	this->add_symbol(&this->declarations, "Event", MetatypeNone, TypeReferenceEvent, &this->event);
	this->add_symbol(&this->declarations, "PhysicalDamage", MetatypeNone, TypeReferenceEffect, NULL);
	this->add_symbol(&this->declarations, "Heal", MetatypeNone, TypeReferenceEffect, NULL);
	this->add_symbol(&this->declarations, "enemy", MetatypeNone, TypeTargetGroup, &this->character);
	this->add_symbol(&this->declarations, "self", MetatypeNone, TypeTargetGroup, &this->character);
	this->add_symbol(&this->declarations, "ally", MetatypeNone, TypeTargetGroup, &this->character);
	this->add_symbol(&this->declarations, "team_ally", MetatypeNone, TypeTargetGroup, &this->character);
	this->add_symbol(&this->declarations, "team_enemy", MetatypeNone, TypeTargetGroup, &this->character);
	this->add_symbol(&this->declarations, "all", MetatypeNone, TypeTargetGroup, &this->character);

	this->add_symbol(&this->character, "name", TypeString, TypeString, NULL);
	this->add_symbol(&this->character, "health", TypeNumber, TypeNumber, &this->resource);
	this->add_symbol(&this->character, "mana", TypeNumber, TypeNumber, &this->resource);
	this->add_symbol(&this->character, "strength", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "agility", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "intelligence", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "stamina", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "defense", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "magic_defense", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "attack_power", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "magic_power", TypeNumber, TypeNumber, &this->attribute);
	this->add_symbol(&this->character, "abilities", TypeList | TypeReferenceAbility, MetatypeNone, NULL);
	this->add_symbol(&this->character, "events", TypeList | TypeReferenceEvent, MetatypeNone, NULL);
	this->add_symbol(&this->character, "behaviour", TypeReferenceBehaviour, MetatypeNone, NULL);

	this->add_symbol(&this->ability, "name", TypeString, TypeString, NULL);
	this->add_symbol(&this->ability, "effects", TypeList | TypeReferenceEffect | TypeCall, MetatypeNone, NULL);
	this->add_symbol(&this->ability, "mana_cost", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->ability, "health_cost", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->ability, "targets", TypeList | TypeTargetGroup, MetatypeNone, NULL);
	this->add_symbol(&this->ability, "target", MetatypeNone, TypeReferenceCharacter, NULL);
	this->add_symbol(&this->ability, "owner", MetatypeNone, TypeReferenceCharacter, &this->character);

	this->add_symbol(&this->behaviour, "positive", TypeList | TypePair | TypeNumber, MetatypeNone, NULL);
	this->add_symbol(&this->behaviour, "negative", TypeList | TypePair | TypeNumber, MetatypeNone, NULL);
	this->add_symbol(&this->behaviour, "owner", MetatypeNone, TypeReferenceCharacter, &this->character);

	this->add_symbol(&this->event, "triggers", TypeList | TypeReferenceEvent, MetatypeNone, NULL);
	this->add_symbol(&this->event, "condition", TypeBool, MetatypeNone, NULL);
	this->add_symbol(&this->event, "action", TypeReferenceAbility | TypeCall, MetatypeNone, NULL);
	this->add_symbol(&this->event, "owner", MetatypeNone, TypeReferenceCharacter, &this->character);

	this->add_symbol(&this->attribute, "current", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->attribute, "initial", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->attribute, "owner", MetatypeNone, TypeReferenceCharacter, &this->character);
	this->add_symbol(&this->attribute, "decrease", MetatypeNone, TypeReferenceEvent, &this->event);
	this->add_symbol(&this->attribute, "increase", MetatypeNone, TypeReferenceEvent, &this->event);
	this->add_symbol(&this->attribute, "change", MetatypeNone, TypeReferenceEvent, &this->event);

	this->add_symbol(&this->resource, "current", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->resource, "initial", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->resource, "maximum", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->resource, "percent", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->resource, "minimum", TypeNumber, TypeNumber, NULL);
	this->add_symbol(&this->resource, "owner", MetatypeNone, TypeReferenceCharacter, &this->character);
	this->add_symbol(&this->resource, "decrease", MetatypeNone, TypeReferenceEvent, &this->event);
	this->add_symbol(&this->resource, "increase", MetatypeNone, TypeReferenceEvent, &this->event);
	this->add_symbol(&this->resource, "change", MetatypeNone, TypeReferenceEvent, &this->event);
}

Symbol *SymbolTable::lookup(scope *s, std::string id, bool global)
{
	if (s == NULL)
		return NULL;

	std::map<std::string, Symbol*>::iterator it;

	it = s->find(id);

	if (it != s->end())
		return it->second;

	if (global)
	{
		it = this->declarations.find(id);
		if (it != this->declarations.end())
			return it->second;
	}

	return NULL;
}

void SymbolTable::add_symbol(scope *target, std::string key, FORMAT_TYPE assigned_from, FORMAT_TYPE assigns, scope *reference)
{
	Symbol* s = new Symbol(assigned_from, assigns, reference);
	std::pair<std::string, Symbol*> insert(key, s);
	target->insert(insert);
}

scope SymbolTable::global(scope *s)
{
	scope global;

	global.insert(s->begin(), s->end());
	global.insert(this->declarations.begin(), this->declarations.end());

	return global;
}



} /* namespace typecheck */
