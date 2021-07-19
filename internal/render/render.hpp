/*
    Contains main renderer of chars
*/

#pragma once

#include <tuple>
#include <vector>
#include <string>
#include <ncurses.h>
#include "./../bufs/bufs.hpp"
#include "./../history/history.hpp"
#include "./../position/position.hpp"

class Renderer
{
private:
    Buffer<BufferCellWithCoords> *buf;
    std::tuple<int, int> current_color_theme;

public:
    Renderer *set_buf(Buffer<BufferCellWithCoords> *buf);

    Renderer *set_color(std::tuple<int, int>);

    void include_new_cell(int index);

    void include_movements();

    void render();

    void init_render_with_color(std::string buf);

    void init_render(std::string buf);
};

extern Renderer *_RENDERER;