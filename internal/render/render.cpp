#include "render.hpp"
#include "./../bufs/bufs.hpp"
#include "./../keys/keys.hpp"
#include "./../colors/colors.hpp"
#include "./../status/status.hpp"
#include "./../states/common/common.hpp"

void Renderer::render(BufferInterface<buf_cell_C> *buf)
{
    auto b = buf->get();
    if (!b.empty())
    {
        auto [curr_y, curr_x] = _POSITION.get_curr_coords();
        auto [max_y, max_x] = _POSITION.get_max_coords();

        for (int i = 0; i < b.size(); i++)
        {
            mvwprintw(stdscr, b[i]->y, b[i]->x, "%c", b[i]->symbol);
        }

        // && !is_common_handled(K_BACKSPACE)
        // && _STATE.get_state() != COMMAND
        // && *curr_y != (*max_y - 2)
        if (!buf->is_last_cell(*curr_y, *curr_x) && !buf->is_ignore_forcible_move())
        {
            wmove(stdscr, *curr_y, *curr_x + 1);
        }

        auto [move_y, move_x] = buf->get_move();

        if (_POSITION.is_start())
        {
            wmove(stdscr, 0, buf->get_last_x(0));
        }
        else if ((!buf->is_empty() && !((move_y == *curr_y) && (move_x == *curr_x))))
        {
            // _LOG__BUF.add_L('Q', CHAR);
            // _LOG__BUF.add_L(*curr_x, INT);
            // _LOG__BUF.add_L(10, CHAR);
            // _LOG__BUF.add_L(move_x, INT);
            // _LOG__BUF.add_L(10, CHAR);
            wmove(stdscr, move_y, move_x);
        };

        buf->delete_move();

        buf->set_ignore_forcible_move(false);

        wrefresh(stdscr);
    }
};

void Renderer::render_with_color(BufferInterface<buf_cell_C> *buf, int color_pair)
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
            _INSERT__BUF->add_C(buf[i], *curr_y, *curr_x);
            mvwaddch(stdscr, *curr_y, *curr_x, buf[i]);
        };
    };
};

Renderer _RENDERER;