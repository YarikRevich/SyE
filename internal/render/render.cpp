#include "render.hpp"
#include "./../bufs/bufs.hpp"
#include "./../keys/keys.hpp"
#include "./../colors/colors.hpp"
#include "./../states/common/common.hpp"

void Renderer::render(std::vector<buf_cell_C *> buf)
{
    if (!buf.empty())
    {
        auto [curr_y, curr_x] = _POSITION.get_curr_coords();

        for (int i = 0; i < buf.size(); i++)
        {
            mvwprintw(stdscr, buf[i]->y, buf[i]->x, "%c", buf[i]->symbol);
        }

        if (!_INSERT__BUF.is_last_cell(*curr_y, *curr_x) && !is_common_handled(K_BACKSPACE))
        {
            wmove(stdscr, *curr_y, *curr_x+1);
        }

        auto [move_y, move_x] = _POSITION.get_move();

        if (_POSITION.is_start())
        {
            wmove(stdscr, 0, _INSERT__BUF.get_last_x(0));
        }
        else if ((!_POSITION.is_empty() && !((move_y == *curr_y) && (move_x == *curr_x))))
        {
            wmove(stdscr, move_y, move_x);
        };

        _POSITION.delete_move();

        wrefresh(stdscr);
    }
};

void Renderer::render_with_color(std::vector<buf_cell_C *> buf, int color_pair)
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
            _INSERT__BUF.add_C(buf[i], *curr_y, *curr_x);
            mvwaddch(stdscr, *curr_y, *curr_x, buf[i]);
        };
    };
};

Renderer _RENDERER;