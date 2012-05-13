#include "Headers/Engine.h"
#include "Headers/Character.h"
#include "Headers/Ability.h"
#include "Headers/Attribute.h"
#include "Headers/Resource.h"
#include "Headers/Behaviour.h"
#include "Headers/FullBehaviour.h"
#include "Headers/BehaviourRatio.h"
#include "Headers/example_ruleset.h"
using namespace engine;
using namespace testbattle;
namespace generated
{
class Cure : Ability
{
	Cure()
	{
		// Explicit Data:
		this->cost_mana = 10;
		this->add_rgr(SELF);
		this->add_rgr(ALLY);
		this->add_effect(new HealEffect(OWNER, TARGET, 20));

		// Automatically Inserted Data:
		this->name = "No Name";
	}
}
class ForceHeal : Event
{
	ForceHeal()
	{
		/* Not yet implemented */

		// Automatically Inserted Data:
		// None for this type.
	}
}
class Smart : FullBehaviour
{
	Smart()
	{
		//Explicit Data:
		this->add_ratio(new BehaviourRatio(OWNER, "health", 100));
		this->add_ratio(new BehaviourRatio(OWNER, "mana", 10));
		this->add_ratio(new BehaviourRatio(ENEMY, "health", -100));

		// Automatically Inserted Data:
		// None for this type.
	}
}
class Orc : Character
{
	Orc()
	{
		// Explicit Data:
		this->name = "Hello Kitty";
		this->add_resource(new Resource("health", 0, 50));
		this->add_resource(new Resource("mana", 0, 100));
		this->add_attribute(new Attribute("strength", 10));
		this->add_attribute(new Attribute("stamina", 9));
		this->add_ability(new Cure());
		this->behaviour = new Smart();
		/*Events not yet implemented*/

		// Automatically Inserted Data:
		this->add_attribute("agility", 0);
		this->add_attribute("intelligence", 0);
		this->add_attribute("defense", (
				this->get_attribute("stamina")->get_current() + 
				this->get_attribute("agility")->get_current()) / 3);
		this->add_attribute("magic_defense", (
				this->get_attribute("stamina")->get_current() + 
				this->get_attribute("intelligence")->get_current()) / 3);
		this->add_attribute("attack_power", (
				this->get_attribute("strength")->get_current() / 2) + 1);
		this->add_attribute("attack_power", (
				this->get_attribute("intelligence")->get_current() / 2) + 1);
	}
}
void run();
} /* namespace generated */
