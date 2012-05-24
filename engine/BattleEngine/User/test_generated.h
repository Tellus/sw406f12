#pragma once

#include "GameState.h"
#include "AbilityTable.h"

#include "FullBehaviour.h"
#include "BehaviourRatio.h"

#include "Effect.h"

#include "HealAbility.h"
#include "AttackAbility.h"

namespace testbattle
{
engine::FullBehaviour* make_fighter_behaviour();

engine::Character* make_joe();

engine::Character* make_biggi();
}
