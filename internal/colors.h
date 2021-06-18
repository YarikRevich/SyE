#include <ncurses.h>
#include <map>
#include <tuple>

#define DEFAULT 1
#define BLUE 2

std::map<int, std::tuple<int, int>> _standart_themes = {
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
	auto [f, b] = _standart_themes[DEFAULT];
	init_pair(DEFAULT, f, b);
	attron(COLOR_PAIR(DEFAULT));
};

void set_color(int color_pair)
{
	auto [f, b] = _standart_themes[color_pair];
	init_pair(1, f, b);
};
