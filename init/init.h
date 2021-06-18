#include <ncurses.h>
#include "./../internal/loop.h"

void init()
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	init_colors();
	run_loop();
	endwin();
}
