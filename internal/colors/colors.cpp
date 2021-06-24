#include <ncurses.h>
#include "colors.hpp"

std::map<int, std::tuple<int, int>> themes = {
	{DEFAULT, {COLOR_GREEN, COLOR_BLUE}},
	{BLUE, {COLOR_GREEN, COLOR_RED}},
	{COMMAND_THEME, {COLOR_MAGENTA, COLOR_CYAN}},
};

void init_colors()
{
	//Adds the main default pair
	//It will allow to change themes
	//due to the substitution new colors
	//to the same color pair

	start_color();
	auto [f, b] = themes[DEFAULT];
	init_pair(DEFAULT, f, b);
	auto [cf, cb] = themes[COMMAND_THEME];
	init_pair(COMMAND_THEME, cf, cb);
	attron(COLOR_PAIR(DEFAULT));
};

void set_color(int color_pair)
{
	auto [f, b] = themes[color_pair];
	init_pair(1, f, b);
};

void turn_on_command_theme()
{
	attron(COLOR_PAIR(COMMAND_THEME));
}

void turn_off_command_theme()
{
	attroff(COLOR_PAIR(COMMAND_THEME));
	attron(COLOR_PAIR(1));
}
