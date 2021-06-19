#include <iostream>
#include "internal/context/context.hpp"
#include "internal/colors/colors.hpp"
#include <ncurses.h>
#include "internal/loop.h"

int main(int argc, char **argv)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	init_colors();
	Context::file.prepare_file(argc, argv);
	run_loop();
	Context::file.close_file();
	endwin();

	return 0;
}
