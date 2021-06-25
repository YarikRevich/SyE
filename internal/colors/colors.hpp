#pragma once

#include <ncurses.h>
#include <map>
#include <tuple>

#define DEFAULT 1
#define BLUE 2
#define COMMAND_THEME 3

class Colors
{
private:
    std::map<int, std::tuple<int, int>> themes = {
        {DEFAULT, {COLOR_GREEN, COLOR_BLUE}},
        {BLUE, {COLOR_GREEN, COLOR_RED}},
        {COMMAND_THEME, {COLOR_MAGENTA, COLOR_CYAN}},
    };
    ;

public:
    //Adds the main default pair
    //It will allow to change themes
    //due to the substitution new colors
    //to the same color pair
    void init_colors();

    void set_color(int color_pair);

    void turn_on_command_theme();

    void turn_off_command_theme();
};

extern Colors _COLORS;