#include <iostream>
#include <csignal>
#include "internal/file/file.hpp"
#include "internal/log/dev/dev.hpp"
#include "internal/colors/colors.hpp"
#include "internal/loop.hpp"
#include "internal/term_flags/term_flags.hpp"

void handle_exit(int signum)
{
	//Handles sigint signal to close all
	//files and disable ncurses mode

	_FILE.auto_save();
	_FILE.close();
	_DEV_LOG.close_file();
	endwin();
	exit(0);
};

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
	signal(SIGINT, handle_exit);

	run_loop();

	return 0;
}
