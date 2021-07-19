#pragma once

#include "./../colors.hpp"

class CommandColor
{
private:
    // std::map<int, std::tuple<int, int>> command_themes = {
    //     {COMMAND_THEME_DEFAULT, {COLOR_MAGENTA, COLOR_CYAN}},
    // };

    // std::map<std::string, int> compatible_themes = {
    //     {"default", COMMAND_THEME_DEFAULT},
    // };

    std::tuple<int, int> current_theme;

public:
    void set(std::tuple<std::string, std::string>);

    void remove();

    void set_current_theme(std::tuple<int, int>);

    std::tuple<int, int> get_current_theme();
};

extern CommandColor *_COMMAND_COLOR;