#pragma once

#include <map>
#include <tuple>
#include <string>
#include <ncurses.h>

extern std::map<std::string, int> compatible_table_of_colors;

std::tuple<int, int> get_int_theme(std::tuple<std::string, std::string> string_theme);

int get_int_color(std::string string_color);

class StateInterface
{
private:
    std::tuple<int, int> current_theme;

public:
    virtual void set_current_theme(std::tuple<int, int>) = 0;

    virtual std::tuple<int, int> get_current_theme() = 0;
};