#include <ncurses.h>
#include "colors.hpp"

std::map<int, std::tuple<int, int>> themes = {
    {DEFAULT, {COLOR_GREEN, COLOR_BLUE}},
    {BLUE, {COLOR_GREEN, COLOR_RED}},
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
	attron(COLOR_PAIR(DEFAULT));
};

void set_color(int color_pair)
{
	auto [f, b] = themes[color_pair];
	init_pair(1, f, b);
};
