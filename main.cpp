#include <csignal>
#include <iostream>
#include "internal/loop/loop.hpp"
#include "internal/files/config/config.hpp"
#include "internal/colors/colors.hpp"
#include "internal/files/helper/helper.hpp"
#include "internal/term_flags/term_flags.hpp"

int main(int argc, char **argv)
{
	TermFlags(argc, argv);

	initscr();
	set_escdelay(FALSE);
	noecho();
	start_color();
	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);
	signal(SIGINT, close_all_files);

	_LOOP->run();

	return 0;
}
