/*
 * program.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#include <iostream>

#include "GameState.h"

#include "EffectDefinition.h"

using namespace std;
using namespace engine;

void sp(std::string to_print)
{
    cout << to_print << "\n";
}

int main(int argc, char *argv[])
{
    cout << "Initializing character...\n";

    // Let's do a simple verification test: Create and populate a character.
    Character *johannes = new Character();
    sp("\tResources...");
    johannes->add_resource("Health", new Resource(100, 0, 100));
    johannes->add_resource("Mana", new Resource(100, 0, 100));
    sp("\tAttributes...");
    johannes->add_attribute("Strength", new Attribute(17));
    johannes->add_attribute("Intelligence", new Attribute(25));
    johannes->add_attribute("Sexyness", new Attribute(10000));
    // Behaviour
    // add behaviour
    // Abilities.
    sp("\tAbilities...");
    johannes->abilities.push_back(new Ability(10, 0));
    johannes->abilities.push_back(new Ability(0, 25));
    johannes->abilities.push_back(new Ability(0,0));

    sp("Done!");
    
    cout << johannes->get_resource("Health")->get_current();

	return 0;
}
