#include "effects.hpp"

void EffectsColor::set(void *theme)
{
    auto [font_color, background_color] = this->effects_themes[*static_cast<int *>(theme)];

    init_pair(3, font_color, background_color);
    attron(COLOR_PAIR(3));
};

void EffectsColor::set_by_string(std::string theme)
{
    this->set(&this->compatible_themes[theme]);
};

void EffectsColor::remove(void *)
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