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

class ForceRenderer
{
public:
    virtual void rerender_insert_forcely();
};

class Renderer : public ForceRenderer
{
private:
    Buffer<BufferCellWithCoords> *buf;
    std::tuple<int, int> current_color_theme;

public:
    bool wide_char_await;

    Renderer *set_buf(Buffer<BufferCellWithCoords> *buf);

    Renderer *set_color(const std::tuple<int, int>);

    static void include_new_cell(const BufferCellWithCoords *);

    void include_movements() const;

    void delete_cell() const;

    void render() const;

    void checkSearchBufferForMovement() const;

    void init_render(const std::string buf);
};

extern Renderer *_RENDERER;