#pragma once

#include <ncurses.h>
#include <map>
#include <tuple>
#include <string>

#define COLOR_PAIR_POINTER 1000

#define DEFAULT 0
#define BLUE 1
#define COMMAND_THEME 2

#define DEFAULT_STR "default"
#define BLUE_STR "blue"

class Colors
{
private:
    std::map<int, std::tuple<int, int>> themes = {
        {DEFAULT, {COLOR_BLACK, COLOR_BLACK | COLOR_RED | COLOR_YELLOW}},
        {BLUE, {COLOR_GREEN, COLOR_RED}},
        {COMMAND_THEME, {COLOR_MAGENTA, COLOR_CYAN}},
    };

    std::map<std::string, int> compatible_themes = {
        {DEFAULT_STR, DEFAULT},
        {BLUE_STR, BLUE},
    };

public:
    //Adds the main default pair
    //It will allow to change themes
    //due to the substitution new colors
    //to the same color pair
    void init_colors();

    void set_color(int color_pair);

    void remove_color(int color_pair);

    void set_color_by_compatible_theme(std::string color_pair);

    // void turn_on_command_theme();

    // void turn_off_command_theme();
};

extern Colors _COLORS;