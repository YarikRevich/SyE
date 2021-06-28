#include "insert.hpp"
#include "./../../colors/colors.hpp"
#include "./../../file/file.hpp"
#include "./../../log/dev/dev.hpp"
#include "./../../history/history.hpp"
#include "./../../state/state.hpp"
#include "./../../position/position.hpp"
#include "./../../keys/keys.hpp"
#include "./../common/common.hpp"

void InsertHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case K_ENTER:
    {
        if (*curr_y == (*max_y - 2))
        {
            wprintw(stdscr, "\n\n");
            wmove(stdscr, *curr_y - 1, *curr_x);
            break;
        }

        _POSITION.incy();
        _POSITION.resetx();
        break;
    }
    default:
        if (!is_handler(ch))
        {
            _PRESSED_HISTORY.set_pressed(*curr_y, *curr_x);
        }
    }
    if (!is_handler(ch))
    {

        _FILE.save_to_buffer(ch, *curr_y, *curr_x);
        wprintw(stdscr, "%c", ch);
    }
};
