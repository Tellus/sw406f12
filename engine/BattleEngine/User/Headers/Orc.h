#include "Character.h"

namespace user
{

class Orc : engine::Character
{
public:
    Orc();
}

make Orc from Character
{
    name: "Hello Kitty";

    strength: 10;
    dexterity: 5;
    
    abilites: [Attack,
                Heal,
                Fire];
    behaviours: Smart;
    
    events +: [ForceHeal];
}

}
