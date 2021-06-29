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
            // _FILE.add('\n', *curr_y, *curr_x);
            // _FILE.add('\n', *curr_y+1, *curr_x);
            //wprintw(stdscr, "\n\n");
            _POSITION.resetx();
            wmove(stdscr, *curr_y, *curr_x);
            _PRESSED_HISTORY.translocation_down();
            return;
        }

        _FILE.add('\n', *curr_y, *curr_x);
        _POSITION.resetx();
        _POSITION.incy();

        return;
    }
    default:
        if (!is_handler(ch))
        {
            _PRESSED_HISTORY.set_pressed(*curr_y, *curr_x);
        }
    }
    if (!is_handler(ch))
    {
        _FILE.add(ch, *curr_y, *curr_x);
    }
};
