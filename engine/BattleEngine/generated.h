#pragma once
#include "Headers/Engine.h"
#include "Headers/SimpleWinCondition.h"
#include "Headers/Character.h"
#include "Headers/Ability.h"
#include "Headers/Attribute.h"
#include "Headers/Resource.h"
#include "Headers/Behaviour.h"
#include "Headers/FullBehaviour.h"
#include "Headers/BehaviourRatio.h"
#include "Headers/EventListener.h"
#include "Headers/example_ruleset.h"
using namespace engine;
using namespace testbattle;
namespace generated
{
class Attack : public Ability
{
public:
	Attack()
	{
		// Explicit Data:
		this->name = "Bash";
		this->cost_mana = 0;
		this->add_rgr(ENEMY);
		this->add_effect(new PhysicalDamageEffect(OWNER, TARGET, 20));

		// Automatically Inserted Data:
	}
};
class Cure : public Ability
{
public:
	Cure()
	{
		// Explicit Data:
		this->name = "Cure";
		this->cost_mana = 10;
		this->add_rgr(SELF);
		this->add_rgr(ALLY);
		this->add_effect(new HealEffect(OWNER, TARGET, 20));

		// Automatically Inserted Data:
	}
};
class ForceHeal : public EventListener
{
public:
	ForceHeal()
	{
		// Explicit Data:
		this->set_condition(OWNER, "health", LESS_THAN_OR_EQUAL, 10);
		this->set_action(new Cure(), OWNER);

		// Automatically Inserted Data:
		// None for this type.
	}
};
class Smart : public FullBehaviour
{
public:
	Smart()
	{
		//Explicit Data:
		this->add_ratio(new BehaviourRatio(OWNER, "health", 100));
		this->add_ratio(new BehaviourRatio(OWNER, "mana", 10));
		this->add_ratio(new BehaviourRatio(ENEMY, "health", -1 * (100)));

		// Automatically Inserted Data:
		// None for this type.
	}
};
class Orc : public Character
{
public:
	Orc()
	{
		// Explicit Data:
		this->name = "Hello Kitty";
		this->add_resource(new Resource("health", 0, 50 * (10 / 5)));
		this->add_resource(new Resource("mana", 0, 100));
		this->add_attribute(new Attribute("strength", 10));
		this->add_attribute(new Attribute("stamina", 9));
		this->add_attribute(new Attribute("agility", 7));
		this->add_ability(new Attack());
		this->add_ability(new Cure());
		this->behaviour = new Smart();
		this->add_event(new ForceHeal());

		// Automatically Inserted Data:
		this->add_attribute(new Attribute("intelligence", 0));
		this->add_attribute(new Attribute("defense", (
				this->get_attribute("stamina")->get_current() + 
				this->get_attribute("agility")->get_current()) / 3));
		this->add_attribute(new Attribute("magic_defense", (
				this->get_attribute("stamina")->get_current() + 
				this->get_attribute("intelligence")->get_current()) / 3));
		this->add_attribute(new Attribute("attack_power", 50));
		this->add_attribute(new Attribute("magic_power", (
				this->get_attribute("intelligence")->get_current() / 2) + 1));
	}
};
class Elf : public Character
{
public:
	Elf()
	{
		// Explicit Data:
		this->name = "Hello Moron";
		this->add_resource(new Resource("health", 0, 50));
		this->add_resource(new Resource("mana", 0, 250));
		this->add_attribute(new Attribute("strength", 7));
		this->add_attribute(new Attribute("stamina", 7));
		this->add_attribute(new Attribute("agility", 25));
		this->add_ability(new Attack());
		this->add_ability(new Cure());
		this->behaviour = new Smart();

		// Automatically Inserted Data:
		this->add_attribute(new Attribute("intelligence", 0));
		this->add_attribute(new Attribute("defense", (
				this->get_attribute("stamina")->get_current() + 
				this->get_attribute("agility")->get_current()) / 3));
		this->add_attribute(new Attribute("magic_defense", (
				this->get_attribute("stamina")->get_current() + 
				this->get_attribute("intelligence")->get_current()) / 3));
		this->add_attribute(new Attribute("attack_power", (
				this->get_attribute("strength")->get_current() / 2) + 1));
		this->add_attribute(new Attribute("magic_power", (
				this->get_attribute("intelligence")->get_current() / 2) + 1));
	}
};
void run();
} /* namespace generated */
