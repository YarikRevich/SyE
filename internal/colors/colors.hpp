#pragma once

#include <map>
#include <tuple>
#include <string>
#include <ncurses.h>

#define COLOR_PAIR_POINTER 1000

#define DEFAULT 0
#define BLUE 1
#define COMMAND_THEME 2

#define DEFAULT_STR "default"
#define BLUE_STR "blue"

class ColorManager
{
protected:
    int current_buf;

public:
    void useBuffer(int id);
};

class Colors : public ColorManager
{
private:
    std::map<int, int> current_pair;

    std::map<int, std::tuple<int, int>> themes = {
        {DEFAULT, {COLOR_BLACK, COLOR_BLACK | COLOR_RED | COLOR_YELLOW}},
        {BLUE, {COLOR_GREEN, COLOR_RED}},
        {COMMAND_THEME, {COLOR_MAGENTA, COLOR_CYAN}},
    };

    std::map<std::string, int> compatible_themes = {
        {DEFAULT_STR, DEFAULT},
        {BLUE_STR, BLUE},
    };

    std::map<std::string, std::tuple<int, int>> compatible_single_colors = {
        {"BLACK", {0, 100}},
        {"RED", {1, 101}},
        {"GREEN", {2, 102}},
        {"YELLOW", {3, 103}},
        {"BLUE", {4, 104}},
        {"MAGENTA", {5, 105}},
        {"CYAN", {6, 106}},
        {"WHITE", {7, 107}},
    };

public:
    //Adds the main default pair
    //It will allow to change themes
    //due to the substitution new colors
    //to the same color pair
    void init_colors();

    void set_color(int color_pair);

    void set_temporar_font_color(int color, int pair);

    std::tuple<int, int> get_compatible_single_color_and_pair(std::string color);

    void remove_color(int color_pair);

    void remove_temporar_font_color(int pair);

    void set_color_by_compatible_theme(std::string color_pair);
};

extern Colors _COLORS;