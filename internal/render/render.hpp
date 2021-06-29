/*
Contains main renderer of chars
*/

#pragma once

#include "./../types/types.hpp"
#include "./../file/file.hpp"
#include "./../history/history.hpp"
#include "./../position/position.hpp"
#include <ncurses.h>
#include <string>
#include <vector>

class Renderer
{

public:
    void render(std::vector<buf_cell> buf);

    void init_render(std::string buf);
};

extern Renderer _RENDERER;