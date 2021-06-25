#include <ncurses.h>
#include "colors.hpp"

void Colors::init_colors()
{
	start_color();
	auto [f, b] = themes[DEFAULT];
	init_pair(DEFAULT, f, b);
	auto [cf, cb] = themes[COMMAND_THEME];
	init_pair(COMMAND_THEME, cf, cb);
	attron(COLOR_PAIR(DEFAULT));
};

void Colors::set_color(int color_pair)
{
	auto [f, b] = themes[color_pair];
	init_pair(1, f, b);
};

void Colors::turn_on_command_theme()
{
	attron(COLOR_PAIR(COMMAND_THEME));
};

void Colors::turn_off_command_theme()
{
	attroff(COLOR_PAIR(COMMAND_THEME));
	attron(COLOR_PAIR(1));
};

Colors _COLORS;

