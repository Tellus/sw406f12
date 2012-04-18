/*
 * AbilityTable.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include "AbilityTable.h"

namespace engine {

AbilityTable::AbilityTable()
{
	// TODO Auto-generated constructor stub

}

AbilityTable::~AbilityTable()
{
	// TODO Auto-generated destructor stub
}

void AbilityTable::create_actions(Character *from)
{
    // Get a short-hand.
    std::list<Ability*> abils = from->get_abilities();
    
    // Final list of usable abilities.
    std::vector<Ability*> usable;
    
    //
    std::vector<Ability*>::iterator iter;
    Ability *abil;
    
    // Discard all unusable Ability objects.
    for (iter = abils.begin(); iter != abils.end(); iter++)
    {
        // Get abil. Test cost.
        abil = *iter;
        if (abil->cost_health <= from->get_resource_current("health") &&
            abil->cost_mana <= from->get_resource_current("mana"))
                usable.push_back(*iter);
    }
    
    // Create the Action list.
    
}

void AbilityTable::iterate_ability(Ability *src)
{
    /*
        In order to 
    */
    for (int i=0; i<__RGR__END__; i*=2)
    {
    
    }
}

} /* namespace engine */
