#include <tuple>
#include "render.hpp"
#include "./../keys/keys.hpp"
#include "./../colors/font/font.hpp"
#include "./../colors/colors.hpp"
#include "./../status/status.hpp"
#include "./../states/common/common.hpp"

Renderer *Renderer::set_buf(Buffer<BufferCellWithCoords> *buf)
{
    this->buf = buf;
    return this;
};

Renderer *Renderer::set_color(std::tuple<int, int> color_theme){
    this->current_color_theme = color_theme;
    return this;
};

void Renderer::include_new_cell(int index)
{
    auto buffer_iterator = buf->getBufferIterator();

    if (buffer_iterator[index]->fontColor.length() != 0)
    {
        _FONT_COLOR->set(buffer_iterator[index]->fontColor);
        mvwprintw(stdscr, buffer_iterator[index]->y, buffer_iterator[index]->x, "%c", buffer_iterator[index]->symbol);
        _FONT_COLOR->remove(buffer_iterator[index]->fontColor);
        return;
    };
    mvwprintw(stdscr, buffer_iterator[index]->y, buffer_iterator[index]->x, "%c", buffer_iterator[index]->symbol);
};

void Renderer::include_movements()
{
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();
    auto [move_y, move_x] = buf->getMovement();

    if (!buf->isLastBufCell(*curr_y, *curr_x) && !buf->isIgnoreForcibleMove())
    {
        wmove(stdscr, *curr_y, *curr_x + 1);
    }

    if (_POSITION.isStartOfY())
    {
        wmove(stdscr, *curr_y, *curr_x);
    }
    else if (_POSITION.isStartOfX())
    {
        wmove(stdscr, *curr_y, 0);
    }
    else if ((!buf->isEmpty() && !((move_y == *curr_y) && (move_x == *curr_x))))
    {
        wmove(stdscr, move_y, move_x);
    };
};

void Renderer::render()
{
    auto buffer_iterator = this->buf->getBufferIterator();
    if (!buffer_iterator.empty())
    {
        for (int i = 0; i < buffer_iterator.size(); i++)
        {
            this->include_new_cell(i);
        }
        this->include_movements();

        buf->deleteMovement();

        buf->setIgnoreForcibleMove(false);

        wrefresh(stdscr);
    }
}; 

void Renderer::init_render(std::string buf)
{
    if (!buf.empty())
    {
        auto [curr_y, curr_x] = _POSITION.get_curr_coords();

        for (int i = 0; i < buf.size() - 1; i++)
        {
            switch (buf[i])
            {
            case 0:
                continue;
            case 10:
                _POSITION.incy();
                _POSITION.resetx();
                break;
            default:
                _POSITION.incx();
            };
            _INSERT__BUF->addCellWithCoords(buf[i], *curr_y, *curr_x);

            mvwaddch(stdscr, *curr_y, *curr_x, buf[i]);
        };
    };
};

Renderer *_RENDERER = new Renderer;