#ifndef SIMPLE_WIN_CONDITION_H_
#define SIMPLE_WIN_CONDITION_H_

#include "WinCondition.h"

namespace engine
{

/**
 * Extends WinCondition with actual functionality. This win condition is so
 * simple, it returns true if *anything* has died.
 **/
class SimpleWinCondition : 	public engine::WinCondition
{
public:
    /**
     * Creates and initialises new SimpleWinCondition.
     **/
	SimpleWinCondition();
	
	/**
	 * \todo Implement or delete-ement?
	 **/
	virtual ~SimpleWinCondition();

    /**
     * Returns true if any Character is dead. False otherwise.
     * \return True if any Character is dead. False otherwise.
     **/
	bool is_met(GameState* check);
};

}

#endif
