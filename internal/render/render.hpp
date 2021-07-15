/*
    Contains main renderer of chars
*/

#pragma once

#include <vector>
#include <string>
#include <ncurses.h>
#include "./../bufs/bufs.hpp"
#include "./../history/history.hpp"
#include "./../position/position.hpp"

class Renderer
{
public:
    void render(Buffer<BufferCellWithCoords> *buf);

    void render_with_color(Buffer<BufferCellWithCoords> *buf, int color_pair);

    void init_render_with_color(std::string buf);

    void init_render(std::string buf);
};

extern Renderer _RENDERER;