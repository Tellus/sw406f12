/*
 * program.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

// For program.cpp
#include <iostream>
#include <fstream>
#include <map>

#include "Engine.h"
#include "SimpleWinCondition.h"

// Other stuff.
#include "PrettyPrinter.h"
#include "User/test_generated.h"

using namespace std;
using namespace engine;
using namespace frontend;
using namespace testbattle;

#ifdef W_NCURSES

#include <boost/program_options.hpp>

#include <ncurses.h>
#include <panel.h>

#include "Frontend/Curses/Entity.h"
#include "Frontend/Curses/Label.h"
#include "Frontend/Curses/PlayerWindow.h"
#include "Frontend/Curses/MessageWindow.h"

namespace po = boost::program_options;

namespace curse = engine::frontend::curses;
using namespace curse;

/**
 * Saves pointer to the original stderr stream so we can restore it later.
 **/
streambuf* saved_cerr;

/**
 * Filebuffer we stream to instead of cerr.
 **/
filebuf ferr;

enum ERROR_ENUM{ ERR_TERM_SIZE };

/**
 * All the global state setup in one function.
 **/
int setup(int argc, char** argv)
{
    // Redirect cerr
    saved_cerr = cerr.rdbuf();
    
    // Overwrite cerr
    ferr.open("engine.log", ios::out);
    cerr.rdbuf(&ferr);
    cerr << "-----------------------\nBattle Engine initialising.\n";

    // Program options.
    int fps;
    
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "shows the help screen.")
        ("framerate,r", po::value<int>(&fps)->default_value(30), "sets the (desired) framerate.");
        
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    
    if (vm.count("help"))
    {
        std::cout << desc << '\n';
        return -1;
    }

    // Calculate timeout based on desired fps. (1000/fps).
    double timeout = 1000/fps;

    // Initialization.
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(timeout); // Timeout matches framerate to give a naturally bounded value.
    
    return 0;
}

/**
 * Global teardown. Should be called after setup, before exiting.
 **/ 
void teardown()
{
    // Clean up.
    endwin();
    
    cerr << "Engine closed.\n-----------------------\n";
    
    // Reset cerr
    cerr.rdbuf(saved_cerr);
    ferr.close();
}

int init_player_windows(std::list<PlayerWindow*>* ps, engine::Engine* engine)
{
    assert(ps);
    assert(engine);
    // Assertions.
    if (ps == NULL) ps = new std::list<PlayerWindow*>();
    if (engine == NULL)
    {
        engine = new engine::Engine();
        engine->win_condition = new SimpleWinCondition();
    }
    
    // Set up.
    Character* joe = make_joe();
    ps->push_back(new PlayerWindow(joe));
    
    Character* biggi = make_joe();
    biggi->name = "Biggi";
    ps->push_back(new PlayerWindow(biggi));
	
    int cnt = 0;
    int t_width = 0;
    int max_window_height = 0;
	
	// Place the windows on a line.
	for (list<PlayerWindow*>::iterator iter = ps->begin(); iter != ps->end(); iter++)
	{
	    // Add player to game.
	    engine->add_character((*iter)->player);
        // Move windows into position.
        (*iter)->move_to(cnt++ * (*iter)->get_width() + 2, 1);
        t_width += (*iter)->get_width();
        max_window_height = std::max(max_window_height, (*iter)->get_bottom());
	}
	engine->init_game();
    
    // Exit if the terminal does not support the width we need.
    if (COLS < (t_width + 5))
    {
        cerr << "Terminal environment is not big enough. Requires at least "
             << t_width + 5
             << " columns.\n";
        teardown();
        exit(-1);
    }
    
    return max_window_height;
}

int main_curses(int argc, char** argv)
{
    if (int v = setup(argc, argv) != 0) return v;

    int frame_count = 0.0, ch, max_window_height;

    std::list<PlayerWindow*>* players = new std::list<PlayerWindow*>();
	Engine* game = new Engine();
    max_window_height = init_player_windows(players, game);
    cerr << "Player list initialised.\n";
    cerr << "Engine initialised.\n";

    MessageWindow* logger = new MessageWindow(2, max_window_height+1, COLS / 2, LINES / 2 - 5);
    logger->title = "Battle log";
    
    cerr << "Logger initialised.\n";
    
    // Hotkey window - just using a message window right now.
    MessageWindow* information = new MessageWindow(logger->get_width()+3, logger->get_y(), COLS / 2 - 4, LINES / 3);
    information->title = "Game information";
    information->log("Players:");

    for (std::list<PlayerWindow*>::iterator iter = players->begin();
          iter != players->end();
          iter++)
    {
        information->log("\t" + (*iter)->player->name);
    }

    information->log("Hotkeys:");
    information->log("[c] - single game step.");
    information->log("[F1] - quit.");
    
    cerr << "Hotkey window initialised.\n";
    
    // Action pointer.
    Action* last_action = NULL;
    
    // Reset terminal cursor.
    move(0,0);
    
    cerr << "Recasting characters.\n";
    
    // Set character references anew.
	for (list<PlayerWindow*>::iterator iter = players->begin(); iter != players->end(); iter++)
	    (*iter)->player = dynamic_cast<Character*>(game->current_state->get_child_by_id((*iter)->player->id));
    
    // Start game loop.    
    cerr << "Engine booting up.\n";
    
    bool done = false;
    while ((ch = getch()) != KEY_F(1))
    {
        if (game->win_condition->is_met(game->current_state) && !done)
        {
            logger->log("Game Over! Press F1 to quit.");
            done = true;
        }
        else if (ch == 'c' && !done)
        {
            last_action = game->step();
            // Set character references anew.
            for (list<PlayerWindow*>::iterator iter = players->begin();
                  iter != players->end();
                  iter++)
                (*iter)->player = dynamic_cast<Character*>(game->current_state->get_child_by_id((*iter)->player->id));
        }
    
        if (last_action)
        {
            logger->log(game->current_state->current_char->name + " used " + last_action->action_def.ability->name);
            last_action = NULL;
        }
    
        // Update loop.
        for (list<PlayerWindow*>::iterator iter = players->begin();
             iter != players->end();
             iter++)
        {
            (*iter)->update();
        }
        
        // Render loop.
        for (list<PlayerWindow*>::iterator iter = players->begin();
             iter != players->end();
             iter++)
        {
            (*iter)->pre_render();
            (*iter)->render();
        }
        
        // Non-iterated loops.
        logger->update();
        logger->pre_render();
        logger->render();
        
        information->update();
        information->pre_render();
        information->render();
        
        mvprintw(LINES - 2, COLS - 20, "Frame: %i", frame_count++);
        
        // Framing lines.
        mvhline(max_window_height, 0, 0, COLS);
        
        // Shove the cursor somewhere unobtrusive.
        move(1, 1);
        
        update_panels();
        doupdate();
    }

    teardown();
    
    return 0;
}

#endif

int main_stdout(int argc, char** argv)
{
	Engine* game = new Engine();
	game->current_state->pretty_print();
	game->win_condition = new SimpleWinCondition();
	game->add_character(make_joe());
	Character *sex = make_joe();
	sex->name = "Biggi";
	game->add_character(sex);
	game->run();

	game->current_state->pretty_print();
	
	return 0;
}

int main(int argc, char** argv)
{
    PrettyPrinter::print("BattleEngine v1 alpha.\n", FG_YELLOW);

	#ifdef W_NCURSES
	return main_curses(argc, argv);
	#else
	return main_stdout(argc, argv);
	#endif
}
