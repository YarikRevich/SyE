#include "insert.hpp"
#include "./../../colors/colors.hpp"
#include "./../../file/file.hpp"
#include "./../../log/dev/dev.hpp"
#include "./../../history/history.hpp"
#include "./../../status/status.hpp"
#include "./../../position/position.hpp"
#include "./../../keys/keys.hpp"
#include "./../common/common.hpp"

void InsertHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    _DEV_LOG.write_to_file_str({std::to_string(*curr_y), " IS Y, ", std::to_string(*curr_x), " IS X ", "\n"});

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
    case K_COLON:
    {
        if (is_handled(K_COLON))
            break;

        _PREV_HISTORY.set_prev_yx(*curr_y, *curr_x);
        _COLORS.turn_on_command_theme();

        int i = 0;
        while (i != *max_x - 1)
        {
            _FILE.add(32, *max_y - 1, i);
            i++;
        }
        _FILE.add(ch, *max_y - 1, 0);
        _POSITION.set_move(*max_y - 1, 1);
        _STATE.set_checkpoint_before_command();
        _STATE.set_state(COMMAND);
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
        // auto [t, ok] = ctrl(ch);
        // if (ok)
        // {
        //     for (int i = 0; i < t.size(); i++)
        //     {
        //         _FILE.add(t[i], *curr_y, *curr_x - i);
        //     }
        // }
        // else
        {
            _FILE.add(ch, *curr_y, *curr_x);
        }
    }
};
