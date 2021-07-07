#include <csignal>
#include <iostream>
#include "internal/loop.hpp"
#include "internal/colors/colors.hpp"
#include "internal/files/helper/helper.hpp"
#include "internal/term_flags/term_flags.hpp"

int main(int argc, char **argv)
{
	TermFlags(argc, argv);

	initscr();
	set_escdelay(FALSE);
	noecho();
	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);
	_COLORS.init_colors();
	signal(SIGINT, close_all_files);
	run_loop();
	return 0;
}
