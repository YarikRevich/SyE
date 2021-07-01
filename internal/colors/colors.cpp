#include <ncurses.h>
#include "colors.hpp"

void Colors::init_colors()
{
	start_color();
	auto [f, b] = themes[DEFAULT];
	init_pair(1, f, b);
	attron(COLOR_PAIR(1));
	wbkgd(stdscr, COLOR_PAIR(1));

	// auto [cf, cb] = themes[COMMAND_THEME];
	// init_pair(, cf, cb);
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
	init_pair(color_pair, f, b);
	attron(COLOR_PAIR(color_pair));
};

void Colors::remove_color(int color_pair)
{
	attroff(COLOR_PAIR(color_pair));
};

// void Colors::turn_on_command_theme()
// {
// 	attron(COLOR_PAIR(10));
// };

// void Colors::turn_off_command_theme()
// {
// 	attroff(COLOR_PAIR(10));
// 	attron(COLOR_PAIR(1));
// };

Colors _COLORS;
