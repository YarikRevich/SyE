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
    void render(BufferInterface<buf_cell_C> *buf);

    void render_with_color(BufferInterface<buf_cell_C> *buf, int color_pair);

    void init_render(std::string buf);
};

extern Renderer _RENDERER;