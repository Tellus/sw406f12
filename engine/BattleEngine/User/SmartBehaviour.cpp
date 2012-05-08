#include "Behaviour.h"

namespace user
{
    class SmartBehaviour : public Behaviour
    {
        SmartBehaviour();
    };
}
make Smart from Behaviour
{
    positive: [[owner.health, 100],
               [owner.mana ,10]];
}
