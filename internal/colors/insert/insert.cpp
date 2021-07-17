#include "insert.hpp"

void InsertColor::set(void *theme)
{
    auto [font_color, background_color] = this->screen_themes[*static_cast<int *>(theme)];

    init_pair(1, font_color, background_color);
    attron(COLOR_PAIR(1));
    wbkgd(stdscr, COLOR_PAIR(1));
};

void InsertColor::set_by_string(std::string theme)
{
    this->set(&this->compatible_themes[theme]);
};

void InsertColor::remove(void *)
{
    attroff(COLOR_PAIR(1));
};

void InsertColor::set_current_theme(std::tuple<int, int> theme)
{
    this->current_theme = theme;
};

std::tuple<int, int> InsertColor::get_current_theme()
{
    return this->current_theme;
};

InsertColor *_INSERT_COLOR = new InsertColor;