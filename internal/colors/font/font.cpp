#include "font.hpp"
#include <string>
#include "./../colors.hpp"
#include "./../insert/insert.hpp"

void FontColor::set(std::string color)
{
    auto [_, background_color] = _INSERT_COLOR->get_current_theme();

    int color_int = get_int_color(color);

    int id = color_int + 50;
    init_pair(id, color_int, background_color);
    attron(COLOR_PAIR(id));
};

// void FontColor::set_by_string(std::string theme)
// {
//     this->set(&this->font_themes[theme]);
// };

void FontColor::remove(std::string color)
{
    int color_int = get_int_color(color);

    int id = color_int + 50;
    attroff(COLOR_PAIR(id));
};

void FontColor::set_current_theme(std::tuple<int, int> theme)
{
    this->current_theme = theme;
};

std::tuple<int, int> FontColor::get_current_theme()
{
    return this->current_theme;
};