#include <iostream>
#include "internal/file.h"
#include <ncurses.h>
#include "internal/loop.h"

int main(int argc, char **argv)
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	init_colors();
	f::prepare_file(argc, argv);
	run_loop();
	f::close_file();
	endwin();

	return 0;
}
