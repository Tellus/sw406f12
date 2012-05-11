/*
 * PrettyPrintEnum_BASH.h
 *
 *  Created on: 01/05/2012
 *      Author: Johannes
 */

#ifndef PRETTY_PRINTER_BASH_H_
#define PRETTY_PRINTER_BASH_H_

#include <iostream>

#define FG_BOLD 1
#define BG_BOLD 0 // Not supported on BASH, far as I can tell.

namespace frontend
{

enum FG_COLOR {
	FG_BLACK = 30,
	FG_RED = 31,
	FG_GREEN = 32,
	FG_YELLOW = 33,
	FG_BLUE = 34,
	FG_MAGENTA = 35,
	FG_WHITE = 37
};

enum BG_COLOR {
	BG_BLACK = 40,
	BG_RED = 41,
	BG_GREEN = 42,
	BG_YELLOW = 43,
	BG_BLUE = 44,
	BG_MAGENTA = 45,
	BG_WHITE = 47
};

}

#endif
