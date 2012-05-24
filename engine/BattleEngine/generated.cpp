#include "generated.h"
namespace generated
{
void run()
{
	engine::Engine *game = new engine::Engine();
	game->win_condition = new SimpleWinCondition();
	game->add_character(new Orc());
	game->add_character(new Elf());
	game->run();
}
} /* namespace generated */
