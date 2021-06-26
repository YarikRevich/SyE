#include "insert.hpp"
#include "./../../colors/colors.hpp"
#include "./../../file/file.hpp"
#include "./../../history/history.hpp"
#include "./../../state/state.hpp"
#include "./../../position/position.hpp"
#include "./../../keys/keys.hpp"

void InsertHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case KEY_UP:
        return;
    case KEY_DOWN:
        return;
    case KEY_LEFT:
        return;
    case KEY_RIGHT:
        return;
    case K_BACKSPACE:
        return;
    case K_COLON:
        return;
    case K_ENTER:
    {
        if (*curr_y == (*max_y - 1))
        {
            wprintw(stdscr, "\n\n");
            wmove(stdscr, *curr_y - 1, *curr_x);
        }

        _POSITION.incy();
        _POSITION.resetx();
        break;
    }
    default:
        _PRESSED_HISTORY.set_pressed(*curr_y, *curr_x);
    }

    _FILE.save_to_buffer(ch, *curr_y, *curr_x);
    wprintw(stdscr, "%c", ch);
};
