/*
 * program.cpp
 *
 *  Created on: 13/04/2012
 *      Author: Ezphares
 */

// For program.cpp
#include <iostream>

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

int main_curses(int argc, char** argv)
{
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
        return 0;
    }

    // Calculate timeout based on desired fps. (1000/fps).
    double timeout = 1000/fps;

    // Initialization.
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(timeout); // Timeout matches framerate to give a naturally bounded value.

    int frame_count = 0.0; // Just to testify to running app.
    int ch;
    
    // Window panels.
    list<PANEL*> panels;
    
    // Characters.
    list<PlayerWindow*> players;

    Character* joe = make_joe();
    PlayerWindow* joew = new PlayerWindow(joe);
    players.push_back(joew);
    panels.push_back(new_panel(joew->window));
    
    Character* biggi = make_joe();
    biggi->name = "Biggi";
    PlayerWindow* biggiw = new PlayerWindow(biggi);
    players.push_back(biggiw);
    panels.push_back(new_panel(biggiw->window));
    
    // Engine.
	Engine* game = new Engine();
	game->win_condition = new SimpleWinCondition();
	game->add_character(joe);
	game->add_character(biggi);

	game->init_game();
    
    // Basic information.
    mvprintw(LINES-2, 1, "Press F1 to exit the application. Characters: ");
    printw(joe->name.c_str());
    printw(biggi->name.c_str());

    // Message window
    MessageWindow* logger = new MessageWindow();

    // Move windows into position.
    joew->move_to(1,1);
    biggiw->move_to(joew->width+3, 1);
    
    // Action pointer.
    Action* last_action = NULL;
    
    // Reset terminal cursor.
    move(0,0);
    joew->player = dynamic_cast<Character*>(game->current_state->get_child_by_id(joew->player->id));
    biggiw->player = dynamic_cast<Character*>(game->current_state->get_child_by_id(biggiw->player->id));
    // Start game loop.    
    bool exit = false;
    while ((ch = getch()) != KEY_F(1) && !exit)
    {
        if (game->win_condition->is_met(game->current_state))
        {
            exit = true;
        }
    
        if (last_action)
        {
            mvprintw(LINES - 3, 2, "Last action: %s", last_action->action_def.ability->name.c_str());
        }
    
        if (ch == 'c')
        {
            // Continue
            last_action = game->step();
            biggiw->player =
                dynamic_cast<Character*>(game->current_state->get_child_by_id(biggiw->player->id));
            joew->player =
                dynamic_cast<Character*>(game->current_state->get_child_by_id(joew->player->id));
        }
    
        // Update loop.
        for (list<PlayerWindow*>::iterator iter = players.begin();
             iter != players.end();
             iter++)
        {
            (*iter)->update();
        }
        
        // Render loop.
        for (list<PlayerWindow*>::iterator iter = players.begin();
             iter != players.end();
             iter++)
        {
            (*iter)->render();
        }
        
        mvprintw(LINES - 2, COLS - 20, "Frame: %i", frame_count++);
        
        update_panels();
        doupdate();
    }

    // Clean up.
    endwin();
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

    std::cout << "Press a key and enter to continue with ";

    #ifdef W_NCURSES
    std::cout << "curses";
    #else
    std::cout << "normal";
    #endif

    std::cout << " frontend.\n";

    std::string ignore;
    cin >> ignore;

	#ifdef W_NCURSES
	return main_curses(argc, argv);
	#else
	return main_stdout(argc, argv);
	#endif
}
