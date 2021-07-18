#pragma once

#include "./../colors.hpp"

class EffectsColor
{
private:
    // std::map<int, std::tuple<int, int>> effects_themes = {
    //     {COMMAND_THEME_DEFAULT, {COLOR_MAGENTA, COLOR_CYAN}},
    // };

    // std::map<std::string, int> compatible_themes = {
    //     {"default", COMMAND_THEME_DEFAULT},
    // };

    std::tuple<int, int> current_theme;

public:
    void set(std::string);

    // void set_by_string(std::string theme);

    void remove();

    void set_current_theme(std::tuple<int, int>);

    std::tuple<int, int> get_current_theme();
};