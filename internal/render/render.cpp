#include "render.hpp"
#include "./../log/dev/dev.hpp"

void Renderer::render(std::vector<buf_cell> buf)
{
    clear(); // Clears screen
    for (int i = 0; i < buf.size(); i++)
    {
        mvwaddch(stdscr, buf[i].y, buf[i].x, buf[i].symbol);
    }
    auto [move_y, move_x] = _POSITION.get_move();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    if (!_POSITION.is_empty() && ((move_y != *curr_y) && (move_x != *curr_x)))
    {
        wmove(stdscr, move_y, move_x);
    };
    wrefresh(stdscr);
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
                _PRESSED_HISTORY.set_pressed(*curr_y, *curr_x);
                _POSITION.incx();
            };
            _FILE.add(buf[i], *curr_y, *curr_x);
            mvwaddch(stdscr, *curr_y, *curr_x, buf[i]);
        };
    };
};

Renderer _RENDERER;