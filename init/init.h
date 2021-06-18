#include <ncurses.h>
#include "./../internal/loop.h"

void init()
{
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	init_colors();
	printw("Hello, you are in Yaroslav's editor\n");
	run_loop();
	endwin();
}
