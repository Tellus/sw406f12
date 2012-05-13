#include "generated.h"
using namespace engine;
namespace generated
{
void run()
{
	Engine *game = new Engine();
	game->win_condition = new SimpleWinCondition();
	game->add_child(new Orc());
	game->run();
}
} /* namespace generated */
