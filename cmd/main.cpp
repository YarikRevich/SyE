#include <clocale>
#include <csignal>
#include <iostream>
#include "./../internal/loop/loop.hpp"
#include "./../internal/colors/colors.hpp"
#include "./../internal/term_flags/term_flags.hpp"

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	TermFlags::add_args(argc, argv);
	Loop::run();
	return 0;
}
