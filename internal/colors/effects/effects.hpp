#pragma once

#include "./../colors.hpp"

#define COMMAND_THEME_DEFAULT 0

class EffectsColor : public ColorInterface
{
private:
    std::map<int, std::tuple<int, int>> effects_themes = {
        {COMMAND_THEME_DEFAULT, {COLOR_MAGENTA, COLOR_CYAN}},
    };

    std::map<std::string, int> compatible_themes = {
        {"default", COMMAND_THEME_DEFAULT},
    };

    std::tuple<int, int> current_theme;

public:
    void set(void *theme);

    void set_by_string(std::string theme);

    void remove(void *theme = NULL);

    void set_current_theme(std::tuple<int, int>);

    std::tuple<int, int> get_current_theme();
};