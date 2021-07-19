#include <map>
#include <tuple>
#include <string>
#include <iostream>
#include <ncurses.h>
#include "colors.hpp"
#include "./../bufs/bufs.hpp"

std::map<std::string, int> compatible_table_of_colors = {
	{"black", COLOR_BLACK},
	{"red", COLOR_RED},
	{"green", COLOR_GREEN},
	{"yellow", COLOR_YELLOW},
	{"blue", COLOR_BLUE},
	{"magenta", COLOR_MAGENTA},
	{"cyan", COLOR_CYAN},
	{"white", COLOR_WHITE},
};

std::tuple<int, int> get_int_theme(std::tuple<std::string, std::string> string_theme)
{
	int font_color_int;
	int background_color_int;

	auto [font_color_string, background_color_string] = string_theme;

	if (compatible_table_of_colors.count(font_color_string))
	{
		font_color_int = compatible_table_of_colors[font_color_string];
	};
	if (compatible_table_of_colors.count(background_color_string))
	{
		background_color_int = compatible_table_of_colors[background_color_string];
	};

	return {font_color_int, background_color_int};
};

int get_int_color(std::string string_color)
{
	return compatible_table_of_colors[string_color];
};
