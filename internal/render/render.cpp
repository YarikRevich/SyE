#include "render.hpp"
#include "./../keys/keys.hpp"
#include "./../colors/colors.hpp"
#include "./../status/status.hpp"
#include "./../states/common/common.hpp"

void Renderer::render(Buffer<BufferCellWithCoords> *buf)
{
    auto b = buf->getBuf();
    if (!b.empty())
    {
        auto [curr_y, curr_x] = _POSITION.get_curr_coords();
        auto [max_y, max_x] = _POSITION.get_max_coords();

        for (int i = 0; i < b.size(); i++)
        {
            mvwprintw(stdscr, b[i]->y, b[i]->x, "%c", b[i]->symbol);
        }

        if (!buf->isLastBufCell(*curr_y, *curr_x) && !buf->isIgnoreForcibleMove())
        {
            wmove(stdscr, *curr_y, *curr_x + 1);
        }

        auto [move_y, move_x] = buf->getMovement();

        // _LOG__BUF->addCellWithSymbolType(move_y, INT);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // _LOG__BUF->addCellWithSymbolType(move_x, INT);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        if (_POSITION.isStartOfY())
        {
            wmove(stdscr, 0, buf->getLastXInRow(0));
        }
        else if (_POSITION.isStartOfX())
        {
            wmove(stdscr, *curr_y, 0);
        }
        else if ((!buf->isEmpty() && !((move_y == *curr_y) && (move_x == *curr_x))))
        {
            wmove(stdscr, move_y, move_x);
        };

        buf->deleteMovement();

        buf->setIgnoreForcibleMove(false);

        wrefresh(stdscr);
    }
};

void Renderer::render_with_color(Buffer<BufferCellWithCoords> *buf, int color_pair)
{
    _COLORS.set_color(color_pair);
    this->render(buf);
    _COLORS.remove_color(color_pair);
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

Renderer _RENDERER;