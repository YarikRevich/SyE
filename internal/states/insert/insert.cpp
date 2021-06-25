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
    case K_BACKSPACE:
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
    case K_COLON:
    {
        _PREV_HISTORY.set_prev_yx(*curr_y, *curr_x);
        _COLORS.turn_on_command_theme();

        int i = 0;
        while (i != *max_x - 1)
        {
            mvwprintw(stdscr, *max_y - 1, i, "%c", 32);
            i++;
        }
        mvwprintw(stdscr, *max_y - 1, 0, "%c", ch);
        _STATE.set_state(COMMAND);
        return;
    }
    default:
        _PRESSED_HISTORY.set_pressed(*curr_y, *curr_x);
    }

    _FILE.save_to_buffer(ch, *curr_y, *curr_x);
    wprintw(stdscr, "%c", ch);
};
