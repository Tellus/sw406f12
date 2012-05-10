#pragma once

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