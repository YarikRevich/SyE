#include "font.hpp"
#include "./../colors.hpp"
#include "./../insert/insert.hpp"

void FontColor::set(void *color)
{
    ColorWrapper *color_wrapper = new ColorWrapper(_INSERT_COLOR);

    auto [_, background_color] = color_wrapper->get_current_theme();

    int id = (int)color + 50;
    init_pair(id, (int)color, background_color);
    attron(COLOR_PAIR(id));
    wbkgd(stdscr, COLOR_PAIR(id));
};

void FontColor::set_by_string(std::string theme)
{
    this->set(&this->font_themes[theme]);
};

void FontColor::remove(void *color)
{
    attron(COLOR_PAIR((int)color + 50));
};

void FontColor::set_current_theme(std::tuple<int, int> theme)
{
    this->current_theme = theme;
};

std::tuple<int, int> FontColor::get_current_theme()
{
    return this->current_theme;
};