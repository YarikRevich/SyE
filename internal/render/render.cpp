#include <tuple>
#include "render.hpp"
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
    wmove(stdscr, Coords::curr_y, Coords::curr_x);
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
            mvwaddch(stdscr, Coords::curr_y, Coords::curr_x, buf[i]);

            Coords::incX();
        };
    };
};

Renderer *_RENDERER = new Renderer;