#include "search.hpp"
#include <ncurses.h>
#include "./../../status/status.hpp"
#include "./../common/common.hpp"
#include "./../../keys/keys.hpp"
#include "./../../position/position.hpp"
#include "./../../bufs/bufs.hpp"

void SearchHandler::handle(int ch)
{
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    //auto buf = _SEARCH_BUF.get_buf();
    // switch (ch)
    // {
    // case KEY_UP:
    //     set_handled_status(KEY_UP);
    //     for (int i = 0; i < buf.size(); i++)
    //     {
    //         auto [y, x] = buf[i];
    //         if (y < *curr_y)
    //         {
    //             wmove(stdscr, y, x + 1);
    //             break;
    //         }
    //     }
    //     break;
    // case KEY_DOWN:
    //     set_handled_status(KEY_DOWN);
    //     for (int i = 0; i < buf.size(); i++)
    //     {
    //         auto [y, x] = buf[i];
    //         if (y > *curr_y)
    //         {
    //             wmove(stdscr, y, x + 1);
    //             break;
    //         }
    //     }
    //     break;
    // case KEY_LEFT:
    //     set_handled_status(KEY_LEFT);
    //     break;
    // case KEY_RIGHT:
    //     set_handled_status(KEY_RIGHT);
    //     break;
    // case K_ENTER:
    //     _STATE.set_state(INSERT);
    // }
}