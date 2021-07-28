#include <tuple>
#include "render.hpp"
#include <algorithm>
#include "./../keys/keys.hpp"
#include "./../colors/font/font.hpp"
#include "./../colors/colors.hpp"
#include "./../states/common/common.hpp"

Renderer *Renderer::set_buf(Buffer<BufferCellWithCoords> *buf)
{
    this->buf = buf;
    return this;
};

Renderer *Renderer::set_color(std::tuple<int, int> color_theme)
{
    this->current_color_theme = color_theme;
    return this;
};

void Renderer::include_new_cell(BufferCellWithCoords *cell)
{
    if (cell->fontColor.length() != 0)
    {
        _FONT_COLOR->set(cell->fontColor);
    };

    mvwprintw(stdscr, cell->coords.y, cell->coords.x, "%c", cell->symbol);

    _FONT_COLOR->remove(cell->fontColor);
};

void Renderer::include_movements()
{
    
    wmove(stdscr, Coords::curr_y, Coords::curr_x);
};

void Renderer::render()
{
    auto buffer_iterator = this->buf->getBufferIterator();
    if (!buffer_iterator.empty())
    {
        std::for_each(buffer_iterator.begin(), buffer_iterator.end(), this->include_new_cell);

        this->include_movements();
        wrefresh(stdscr);
    }
};

void Renderer::checkSearchBufferForMovement()
{
    this->include_movements();
    wrefresh(stdscr);
};

void Renderer::init_render(std::string buf)
{
    if (!buf.empty())
    {
        for (int i = 0; i < buf.size() - 1; i++)
        {
            switch (buf[i])
            {
            case 0:
                continue;
            case 10:
                Coords::incY(), Coords::resetX();
                continue;
            };
            _INSERT__BUF->addCellWithCoords(buf[i], Coords::curr_y, Coords::curr_x);
            mvwprintw(stdscr, Coords::curr_y, Coords::curr_x, "%c", buf[i]);

            Coords::incX();
        };
    };
};

Renderer *_RENDERER = new Renderer;