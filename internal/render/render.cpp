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
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
        _LOG__BUF->addCellWithSymbolType('S', CHAR);
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
        for (int i = 0; i < buffer_iterator.size(); i++)
        {
            _LOG__BUF->addCellWithSymbolType(buffer_iterator[i]->symbol, INT);
            // _LOG__BUF->addCellWithSymbolType(' ', CHAR);
            // _LOG__BUF->addCellWithSymbolType(buffer_iterator[i]->wideChar.startOfChar, INT);
            // _LOG__BUF->addCellWithSymbolType(' ', CHAR);
            // _LOG__BUF->addCellWithSymbolType(buffer_iterator[i]->wideChar.endOfChar, INT);
            _LOG__BUF->addCellWithSymbolType(' ', CHAR);
            _LOG__BUF->addCellWithSymbolType('Y', CHAR);
            _LOG__BUF->addCellWithSymbolType(' ', CHAR);
            _LOG__BUF->addCellWithSymbolType(buffer_iterator[i]->y, INT);
            _LOG__BUF->addCellWithSymbolType(' ', CHAR);
            _LOG__BUF->addCellWithSymbolType('X', CHAR);
            _LOG__BUF->addCellWithSymbolType(' ', CHAR);
            _LOG__BUF->addCellWithSymbolType(buffer_iterator[i]->x, INT);

            _LOG__BUF->addCellWithSymbolType(10, CHAR);
            this->include_new_cell(i);
            // printw("%c", buffer_iterator[i]->symbol);
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
            mvwprintw(stdscr, Coords::curr_y, Coords::curr_x, "%c", buf[i]);

            Coords::incX();
        };
    };
};

Renderer *_RENDERER = new Renderer;