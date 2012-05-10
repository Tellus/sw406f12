#include "Character.h"
// #include "GameEvent.h"

using namespace engine;

namespace user
{

class Orc : engine::Character
{
public:
    void callback_1(void* ob, GameEvent* ev)
    {
        // Force an action.
        if (this->get_resource("Health")->get_current()<=10)
            this->set_action(this->get_ability("Heal"), OWNER);
    }

    Orc() :
        Primarch("Hello Kitty")
    {
        this->add_attribute(new Strength(10));
        this->add_attribute(new Dexterity(5));
        
        this->add_ability(new AttackAbility());
        this->add_ability(new HealAbility());
        this->add_ability(new FireAbility());
        
        FullBehaviour *nb = new FullBehaviour();
    	nb->add_ratio(new ResourceRatio(OWNER, "Health", 1));
    	nb->add_ratio(new ResourceRatio(OWNER, "Mana", 0.5));

        this->behaviour = nb;
        
        this->callbacks["HEALTH_DECREASE"].push_back(callback(this,callback_1));
    }
};

}
