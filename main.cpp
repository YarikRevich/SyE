#include <iostream>
#include <csignal>
#include "internal/file/file.hpp"
#include "internal/log/dev/dev.hpp"
#include "internal/colors/colors.hpp"
#include "internal/loop.hpp"
#include "internal/term_flags/term_flags.hpp"

void handle_exit()
{
	//Handles sigint signal to close all
	//files and disable ncurses mode

	_FILE.save_default();
	_FILE.close_file();
	_DEV_LOG.close_file();
	endwin();
	exit(0);
};

#pragma exit handle_exit;

int main(int argc, char **argv)
{
	TermFlags term_flags = TermFlags(argc, argv);
	term_flags.check_executive_flag();
	term_flags.check_dev_flag();

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

	run_loop();

	return 0;
}
