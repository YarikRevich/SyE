#pragma once

#include <ncurses.h>
#include <map>
#include <tuple>

#define DEFAULT 1
#define BLUE 2
#define COMMAND_THEME 3

extern std::map<int, std::tuple<int, int>> themes;

void init_colors();

void set_color(int color_pair);

void turn_on_command_theme();

void turn_off_command_theme();
