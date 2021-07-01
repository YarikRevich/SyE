#include <ncurses.h>
#include "colors.hpp"

void Colors::init_colors()
{
	start_color();
	auto [f, b] = themes[DEFAULT];
	init_pair(1, f, b);
	auto [cf, cb] = themes[COMMAND_THEME];
	init_pair(COMMAND_THEME, cf, cb);
	attron(COLOR_PAIR(1));
	wbkgd(stdscr, COLOR_PAIR(1));
};

void Colors::set_color_by_compatible_theme(std::string color_pair)
{
	if (compatible_themes.count(color_pair))
	{
		auto [f, b] = themes[compatible_themes[color_pair]];
		init_pair(1, f, b);
	}
};

void Colors::set_color(int color_pair)
{
	auto [f, b] = themes[color_pair];
	init_pair(1, f, b);
};

void Colors::turn_on_command_theme()
{
	wattron(stdscr, COLOR_PAIR(COMMAND_THEME));
};

void Colors::turn_off_command_theme()
{
	wattroff(stdscr, COLOR_PAIR(COMMAND_THEME));
	wattron(stdscr, COLOR_PAIR(1));
};

Colors _COLORS;
