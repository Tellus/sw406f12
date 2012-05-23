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

    // Move windows into position.
    joew->move_to(1,1);
    biggiw->move_to(COLS/2+1, 1);
    
    // Reset terminal cursor.
    move(0,0);    
    while ((ch = getch()) != KEY_F(1))
    {
        if (ch == 'c')
        {
            // Continue
            game->step();
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

	// Uncomment to perform basic initialization, cloning and AI test.
	// base_test();
	
	#ifdef W_NCURSES
	return main_curses(argc, argv);
	#else
	return main_stdout(argc, argv);
	#endif
}
