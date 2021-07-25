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
    // auto [move_y, move_x] = buf->getMovement();

    // if (!buf->isLastBufCell(Coords::curr_y, Coords::curr_x) && !buf->isIgnoreForcibleMove())
    // {

    //     wmove(stdscr, Coords::curr_y, Coords::curr_x + 1);
    // }
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // _LOG__BUF->addCellWithSymbolType('M', CHAR);
    // _LOG__BUF->addCellWithSymbolType(move_y, INT);
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // _LOG__BUF->addCellWithSymbolType(move_x, INT);
    // _LOG__BUF->addCellWithSymbolType(10, CHAR);
    // _LOG__BUF->addCellWithSymbolType(Coords::curr_x, INT);
    wmove(stdscr, Coords::curr_y, Coords::curr_x);

    // if (Position::isStartOfY())
    // {
    //     _LOG__BUF->addCellWithSymbolType('Y', CHAR);
    //     wmove(stdscr, Coords::curr_y, Coords::curr_x);
    // }
    // else if (Position::isStartOfX())
    // {
    //     wmove(stdscr, Coords::curr_y, 0);
    // }
    // else if ((!buf->isEmpty() && !((move_y == Coords::curr_y) && (move_x == Coords::curr_x))))
    // {
    //     _LOG__BUF->addCellWithSymbolType('O', CHAR);
    //     wmove(stdscr, move_y, move_x);
    // };
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
                break;
            default:
                Coords::incX();
            };
            _INSERT__BUF->addCellWithCoords(buf[i], Coords::curr_y, Coords::curr_x);
            mvwaddch(stdscr, Coords::curr_y, Coords::curr_x, buf[i]);
        };
    };
};

Renderer *_RENDERER = new Renderer;