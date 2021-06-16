#include <ncurses.h>
#include "./../internal/loop.h"

void init(){
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	printw("Hello, you are in Yaroslav's editor\n");
	refresh();
	run_loop();
	endwin();
}
