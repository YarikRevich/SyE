#pragma once

#include <tuple>
#include <string>
#include "./../colors.hpp"

class InsertColor
{
private:
    // std::map<int, std::tuple<int, int>> screen_themes = {
    //     {INSERT_THEME_DEFAULT, {COLOR_BLACK, COLOR_BLACK | COLOR_RED | COLOR_YELLOW}},
    //     {INSERT_THEME_BLUE, {COLOR_GREEN, COLOR_RED}},
    // };

    // std::map<std::string, int> compatible_themes = {
    //     {"default", INSERT_THEME_DEFAULT},
    //     {"blue", INSERT_THEME_BLUE},
    // };

    std::tuple<int, int> current_theme;

public:
    void set(std::tuple<std::string, std::string>);

    // void set_by_string(std::string theme);

    void remove();

    void set_current_theme(std::tuple<int, int>);

    std::tuple<int, int> get_current_theme();
};

extern InsertColor *_INSERT_COLOR;