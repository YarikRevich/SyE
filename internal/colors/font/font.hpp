#pragma once

#include "./../colors.hpp"

class FontColor : public ColorInterface
{
private:
    std::map<std::string, int> font_themes = {
        {"black", COLOR_BLACK},
        {"red", COLOR_RED},
        {"green", COLOR_GREEN},
        {"yellow", COLOR_YELLOW},
        {"blue", COLOR_BLUE},
        {"magenta", COLOR_MAGENTA},
        {"cyan", COLOR_CYAN},
        {"white", COLOR_WHITE},
    };

    std::tuple<int, int> current_theme;

public:
    void set(void *color);

    void set_by_string(std::string theme);

    void remove(void *color);

    void set_current_theme(std::tuple<int, int>);

    std::tuple<int, int> get_current_theme();
};