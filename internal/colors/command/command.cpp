#include <tuple>
#include <string>
#include "command.hpp"

void CommandColor::set(std::tuple<std::string, std::string> theme)
{

    auto [font_color, background_color] = get_int_theme(theme);

    init_pair(2, font_color, background_color);
    attron(COLOR_PAIR(2));
};

// void CommandColor::set_by_string(std::string theme)
// {
//     this->set(&this->compatible_themes[theme]);
// };

void CommandColor::remove()
{
    attroff(COLOR_PAIR(2));
};

void CommandColor::set_current_theme(std::tuple<int, int> theme)
{
    this->current_theme = theme;
};

std::tuple<int, int> CommandColor::get_current_theme()
{
    return this->current_theme;
};