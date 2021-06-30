#include <csignal>
#include <iostream>
#include "internal/loop.hpp"
#include "internal/colors/colors.hpp"
#include "internal/files/helper/helper.hpp"
#include "internal/term_flags/term_flags.hpp"

int main(int argc, char **argv)
{
	TermFlags(argc, argv);

	//Inits ncurses
	initscr();

	//Disables echo mode in ncurses
	noecho();

	//Turn off scroll
	scrollok(stdscr, TRUE);

	//Enables the opportunity to use key pad
	keypad(stdscr, true);

	//Inits color sets
	_COLORS.init_colors();

	//Handles sigint signal
	signal(SIGINT, close_all_files);

	run_loop();

	return 0;
}
