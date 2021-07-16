#include <iostream>
#include <ncurses.h>
#include "colors.hpp"
#include "./../bufs/bufs.hpp"

ColorWrapper::ColorWrapper(ColorInterface *src)
{
	this->src = src;
};

void ColorWrapper::remove(void *color)
{
	this->src->remove(color);
};

std::tuple<int, int> ColorWrapper::get_current_theme(){
	return this->src->get_current_theme();
};

// void Manager::useBuffer(int id)
// {
// 	this->current_buffer = id;
// };

// void FontTheme::set_font_theme(std::string color)
// {
// 	if (this->font_themes.count(color))
// 	{
// 		auto screen_theme_used_before = this->themes_used_by_buffers[this->current_buffer];
// 		attroff(COLOR_PAIR(screen_theme_used_before));

// 		attron(COLOR_PAIR(this->font_themes[color]));
// 	}

	// auto [_, b] = themes[this->current_pair[this->current_buf]];
	// init_pair(pair, color, b);
	// attron(COLOR_PAIR(pair));
// };

// void FontTheme::remove_font_color(std::string color)
// {
// 	if (this->font_themes.count(color))
// 	{
// 		attroff(COLOR_PAIR(this->font_themes[color]));
// 	}
// };

// int Colors::get_main_color()
// {
// 	return this->main_theme;
// };

// void Colors::set_main_theme(int theme)
// {
// 	int color_pair_id = this->generate this->current_pair[this->current_buf] = theme;

// 	auto [f, b] = themes[theme];
// 	init_pair(1, f, b);
// 	attron(COLOR_PAIR(1));
// 	wbkgd(stdscr, COLOR_PAIR(1));
// };

// void Colors::set_theme_by_string(std::string color_pair)
// {
// 	if (compatible_themes.count(color_pair))
// 	{
// 		auto [f, b] = themes[compatible_themes[color_pair]];
// 		init_pair(1, f, b);
// 	}
// };

// void Colors::set_color(int color_pair, int id)
// {
// 	int color_pair_id;
// 	if (id != 0)
// 	{
// 		color_pair_id = id;
// 	}
// 	else
// 	{
// 		color_pair_id = this->generate_color_pair_id();
// 	}

// 	this->current_pair[this->current_buf] = {color_pair, color_pair_id};

// 	auto [f, b] = themes[color_pair];
// 	init_pair(color_pair_id, f, b);
// 	attron(COLOR_PAIR(color_pair_id));
// 	wbkgd(stdscr, COLOR_PAIR(color_pair_id));
// };

// boost::optional<std::tuple<int, int>> Colors::get_compatible_single_color_and_pair(std::string color)
// {
// 	if (this->compatible_single_colors.count(color))
// 	{
// 		return this->compatible_single_colors[color];
// 	};
// 	return boost::none;
// };

// void Colors::remove_color(int color_pair)
// {
// 	attroff(COLOR_PAIR(color_pair));
// };
