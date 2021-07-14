#include <ncurses.h>
#include <iostream>
#include "colors.hpp"

void ColorManager::useBuffer(int id){
	this->current_buf = id;
};

void Colors::init_colors()
{
	start_color();
	auto [f, b] = themes[DEFAULT];
	init_pair(1, f, b);
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
	this->current_pair[this->current_buf] = color_pair;

	auto [f, b] = themes[color_pair];
	init_pair(color_pair, f, b);
	attron(COLOR_PAIR(color_pair));
};

void Colors::set_temporar_font_color(int color, int pair)
{
	auto [_, b] = themes[this->current_pair[this->current_buf]];
	init_pair(pair, color, b);
	attron(COLOR_PAIR(pair));
};

std::tuple<int, int> Colors::get_compatible_single_color_and_pair(std::string color)
{
	if (this->compatible_single_colors.count(color))
	{
		return this->compatible_single_colors[color];
	};
	return {};
};

void Colors::remove_color(int color_pair)
{
	attroff(COLOR_PAIR(color_pair));
};

void Colors::remove_temporar_font_color(int pair)
{
	attroff(COLOR_PAIR(pair));
	this->set_color(this->current_pair[this->current_buf]);
};

Colors _COLORS;
