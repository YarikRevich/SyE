#include <iostream>
#include <csignal>
#include "internal/context/context.hpp"
#include "internal/colors/colors.hpp"
#include "internal/loop.hpp"
#include "init/init.hpp"
#include "internal/term_flags/term_flags.hpp"

void handle_sigint(int signum)
{
	//Handles sigint signal to close all
	//files and disable ncurses mode

	Context::file.save_default();
	Context::file.close_file();
	Context::dev_log.close_file();
	endwin();
	exit(0);
};

int main(int argc, char **argv)
{
	TermFlags term_flags = TermFlags(argc, argv);
	term_flags.check_executive_flag();
	term_flags.check_dev_flag();

	//Inits ncurses
	initscr();

	//Disables echo mode in ncurses
	noecho();

	//Enables the opportunity to use key pad
	keypad(stdscr, true);

	//Inits color sets
	init_colors();

	//Handles sigint to close all opened files and disable ncurses mode
	signal(SIGINT, handle_sigint);

	run_loop();

	return 0;
}
