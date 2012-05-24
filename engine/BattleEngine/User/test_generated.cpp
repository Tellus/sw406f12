// For unit tests.
#include "test_generated.h"

using namespace std;
using namespace engine;
using namespace testbattle;

namespace testbattle{

FullBehaviour* make_fighter_behaviour()
{
	FullBehaviour *nb = new FullBehaviour();
	nb->add_ratio(new BehaviourRatio(ENEMY, "health", -0.5));
	nb->add_ratio(new BehaviourRatio(OWNER, "health", 2));

	return nb;
}

Character* make_joe()
{
	Character *johannes = new Character();
	johannes->name = "Johannes";

	johannes->add_resource(new Resource("health", 0, 100));
	johannes->add_resource(new Resource("mana", 0, 100));

	johannes->add_attribute(new Attribute("strength", 17));
	johannes->add_attribute(new Attribute("intelligence", 25));
	johannes->add_attribute(new Attribute("sexyness", 10000));
	johannes->add_attribute(new Attribute("stamina", 31));
	johannes->add_attribute(new Attribute("agility", 12));
	johannes->add_attribute(new Attribute("defense",
	    (johannes->get_attribute("stamina")->get_current() +
	     johannes->get_attribute("agility")->get_current())/3));
	johannes->add_attribute(new Attribute("mdefense",
	    (johannes->get_attribute("stamina")->get_current() +
	     johannes->get_attribute("intelligence")->get_current())/3));
	johannes->add_attribute(new Attribute("attack_power", 50));

	FullBehaviour* beh = new FullBehaviour();
	johannes->behaviour = beh;
	beh->add_ratio(new BehaviourRatio(OWNER, "health", 2));
	beh->add_ratio(new BehaviourRatio(ENEMY, "health", -1));
	
	johannes->add_ability(new AttackAbility());
	johannes->add_ability(new HealAbility());

    johannes->add_event(
			new EventCondition(OWNER, "health", LESS_THAN, 50),
			new ActionDefinition(OWNER, OWNER, dynamic_cast<Ability*>(johannes->get_child("Heal"))));

	return johannes;
}

Character* make_biggi()
{
    Character *biggi = new Character();
    biggi->name = "Biggi";
    
    // PrettyPrinter::print("Resources...\n", FG_YELLOW);
	biggi->add_resource(new Resource("health", 0, 250));
	biggi->add_resource(new Resource("mana", 0, 50));

	biggi->add_attribute(new Attribute("strength", 50));
	biggi->add_attribute(new Attribute("intelligence", 1));
	biggi->add_attribute(new Attribute("sexyness", -5));
	biggi->add_attribute(new Attribute("stamina", 47));
	biggi->add_attribute(new Attribute("agility", 3));
	biggi->add_attribute(new Attribute("defense",
	    (biggi->get_attribute("stamina")->get_current() +
	     biggi->get_attribute("agility")->get_current())/3));
	biggi->add_attribute(new Attribute("mdefense",
	    (biggi->get_attribute("stamina")->get_current() +
	     biggi->get_attribute("intelligence")->get_current())/3));
	biggi->add_attribute(new Attribute("attack_power", 50));
	// Behaviour
	biggi->behaviour = make_fighter_behaviour();

    // Abilities.
    // PrettyPrinter::print("Abilities...\n", FG_YELLOW);
    // biggi->add_ability("Maul", new AttackAbility());
	Ability* abil = new Ability("Maul", 0, 0);
	
//	abil->add_child(new Effect(OWNER, TARGET, "health", -10));
	abil->add_child(new PhysicalDamageEffect(OWNER, TARGET));
	biggi->add_ability(abil);

	return biggi;
}

}
