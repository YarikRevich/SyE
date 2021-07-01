/*
    Contains main renderer of chars
*/

#pragma once

#include <vector>
#include <string>
#include <ncurses.h>
#include "./../index.hpp"
#include "./../history/history.hpp"
#include "./../position/position.hpp"

class Renderer
{
public:
    void render(std::vector<buf_cell_C*> buf);

    void init_render(std::string buf);
};

extern Renderer _RENDERER;