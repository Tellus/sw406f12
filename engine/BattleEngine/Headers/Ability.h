/*
 * Ability.h
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

#ifndef ABILITY_H_
#define ABILITY_H_

// #include "EffectDefinition.h"
#include "Effect.h"
#include "RGR_List.h"

#include <vector>

namespace engine {

/**
 * Ability from langname.
 **/
class Ability : public Primarch, public RGR_List
{
public:
    Ability();

    /** 
     * Creates and initialises a new Ability.
     * \param name The name of the Ability.
     * \param cost_health Cost of the "health" Resource to use this Ability.
     * \param cost_mana Cost of the "mana" Resource to use this Ability.
     **/
    Ability(std::string name, float cost_health, float cost_mana);
    
    /** 
     * \todo Implement.
     **/
	virtual ~Ability();	
	
	/**
	 * Cost of health to use this Ability.
	 **/
	float cost_health;
	
	/**
	 * Cost of mana to use this ability.
	 **/
	float cost_mana;
    
    /**
     * Outputs data about the Ability in a neat, human-readable form to stdout.
     **/
    void pretty_print();

    /**
     * The effects applied when an ability is used. It is preferred that you
     * use Effect::clone() when you need an effects rather than use it directly.
     **/
	std::vector<Effect*> effects;

    /**
     * Inherited from Primarch. Creates an exact copy of the Ability.
     * \param with_id It True, the new Ability uses the same Id as the original.
     * Used by GameState cloning. If false, the Ability gets a new Id. used for
     * mass-production.
     **/
	Primarch* clone(bool with_id = false);
    
	/**
	 * Returns something completely nonsensical.
	 **/
	float get_value();

    /**
     * Adds another Effect to the Ability.
     * \param to_add The Effect to add.
     **/
	void add_effect(Effect* to_add);

    /**
     * Modifies the value of the Ability. This could either be construed to be
     * the health cost or the effect magnitude.
     **/
	void modify(float amount);
};

} /* namespace engine */
#endif /* ABILITY_H_ */
