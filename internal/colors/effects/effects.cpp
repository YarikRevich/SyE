#include "effects.hpp"
#include <string>


void EffectsColor::set(std::string color)
{
    int color_int = get_int_color(color);

    init_pair(3, color_int, color_int);
    attron(COLOR_PAIR(3));
};

// void EffectsColor::set_by_string(std::string theme)
// {
//     this->set(&this->compatible_themes[theme]);
// };

void EffectsColor::remove()
{
    attroff(COLOR_PAIR(3));
};

void EffectsColor::set_current_theme(std::tuple<int, int> theme)
{
    this->current_theme = theme;
};

std::tuple<int, int> EffectsColor::get_current_theme()
{
    return this->current_theme;
};