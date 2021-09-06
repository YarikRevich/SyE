#include <tuple>
#include "render.hpp"
#include <algorithm>
#include "./../keys/keys.hpp"
#include "./../helper/helper.hpp"
#include "./../colors/colors.hpp"
#include "./../colors/font/font.hpp"
#include "./../states/common/common.hpp"

Renderer *Renderer::set_buf(Buffer<BufferCellWithCoords> *buf)
{
    this->buf = buf;
    return this;
};

Renderer *Renderer::set_color(const std::tuple<int, int> color_theme)
{
    this->current_color_theme = color_theme;
    return this;
};

// void Renderer::delete_cell() const
// {
//     mvdelch(Coords::curr_y, Coords::curr_x - 1);
//     // Coords::decX();
//     // wmove(stdscr, Coords::curr_y, Coords::curr_x);
// };

void Renderer::include_new_cell(const BufferCellWithCoords *cell)
{
    if (cell->fontColor.length() != 0)
    {
        _FONT_COLOR->set(cell->fontColor);
    };
    mvwprintw(stdscr, cell->coords.y, cell->coords.x, "%c", cell->symbol);

    _FONT_COLOR->remove(cell->fontColor);
};

void Renderer::include_movements() const
{
    wmove(stdscr, Coords::curr_y, Coords::curr_x);
    refresh();
};

void Renderer::render() const
{
    auto &buffer_iterator = this->buf->getBufferIterator();
    if (!buffer_iterator.empty())
    {
        std::for_each(buffer_iterator.begin(), buffer_iterator.end(), this->include_new_cell);
    };
    this->include_movements();
    refresh();
};

void Renderer::checkSearchBufferForMovement() const
{
    this->include_movements();
    refresh();
};

void Renderer::init_render(const std::string buf)
{
    if (!buf.empty())
    {
        _INSERT__BUF->addCellWithCoords(0, Coords::curr_y, Coords::curr_x);

        for (int i = 0; i < buf.size(); i++)
        {
            switch (buf[i])
            {
            case 0:
                continue;
            };

            if (Coords::curr_x == Coords::max_x)
            {
                Coords::incY();
            }

            _INSERT__BUF->addCellWithCoords(buf[i], Coords::curr_y, Coords::curr_x);
            mvprintw(Coords::curr_y, Coords::curr_x, "%c", buf[i]);

            switch (buf[i])
            {
            case 10:
                Coords::incY(), Coords::resetX();
                continue;
            };

            if (isWideChar(buf[i]))
            {
                if (!this->wide_char_await)
                {
                    this->wide_char_await = true;
                }
                else
                {
                    this->wide_char_await = false;
                    Coords::incX();
                }
            }
            else
            {
                Coords::incX();
            }
        };
        refresh();
    };
};

Renderer *_RENDERER = new Renderer;