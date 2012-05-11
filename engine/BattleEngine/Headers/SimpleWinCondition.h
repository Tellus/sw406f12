#ifndef SIMPLE_WIN_CONDITION_H_
#define SIMPLE_WIN_CONDITION_H_

#include "WinCondition.h"

namespace engine
{

class SimpleWinCondition :
	public engine::WinCondition
{
public:
	SimpleWinCondition();
	virtual ~SimpleWinCondition();

	bool is_met(GameState* check);
};

}

#endif
