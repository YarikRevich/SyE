#include "common.hpp"
#include "./../../keys/keys.hpp"
#include "./../../file/file.hpp"
#include "./../../state/state.hpp"
#include "./../../colors/colors.hpp"
#include "./../../position/position.hpp"
#include "./../../history/history.hpp"
#include "./../../log/dev/dev.hpp"
#include "./../../margin/margin.hpp"

std::map<int, bool> handler_status = {
    {K_BACKSPACE, false},
    {K_COLON, false},
    {KEY_UP, false},
    {KEY_DOWN, false},
    {KEY_LEFT, false},
    {KEY_RIGHT, false},
};

void set_handled_status(int id)
{
    handler_status[id] = true;
};

bool is_handled(int id)
{
    return handler_status[id];
};

void reset_handled_status()
{
    for (auto const &[key, _] : handler_status)
    {
        handler_status[key] = false;
    };
};

bool is_handler(int ch)
{
    for (auto const &[key, val] : handler_status)
    {
        if (key == ch)
        {
            return true;
        }
    }
    return false;
};

void CommonHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    _DEV_LOG.write_to_file_str({std::to_string(*curr_y) + "\n"});

    // CharInserter char_inseter;

    switch (ch)
    {
    case KEY_UP:
    {
        // || !_FILE.exist_in_buf(*curr_y - 1)
        if (is_handled(KEY_UP))
            break;

        if (*curr_y == 0)
        {
            wscrl(stdscr, -1);
            _PRESSED_HISTORY.translocation_up();
            _POSITION.set_move(*curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
            break;
        };

        _POSITION.decy();
        _POSITION.set_move(*curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
        break;
    }
    case KEY_DOWN:
    {
        if (is_handled(KEY_DOWN))
            break;

        if ((*curr_y + 1) == (*max_y - 1))
        {
            scroll(stdscr);
            _PRESSED_HISTORY.translocation_down();
            break;
        };

        _POSITION.incy();
        _POSITION.set_move(*curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
        break;
    }
    case KEY_LEFT:
    {
        if (is_handled(KEY_LEFT))
            break;

        _POSITION.decx();
        _POSITION.set_move(*curr_y, *curr_x);
        break;
    }
    case KEY_RIGHT:
    {
        if (is_handled(KEY_RIGHT))
            break;

        _POSITION.incx();
        _POSITION.set_move(*curr_y, *curr_x);
        break;
    }
    case K_BACKSPACE:
    {
        if (is_handled(K_BACKSPACE))
            break;

        if (*curr_x == 0)
        {
            _PRESSED_HISTORY.delete_pressed(*curr_y, *curr_x);
            _FILE.erase(*curr_y, *curr_x);
            _POSITION.decy();
            _POSITION.setx(_PRESSED_HISTORY.get_best_x(*curr_y));
        }
        else
        {
            _POSITION.decx();
        }
        _PRESSED_HISTORY.delete_pressed(*curr_y, *curr_x);
        _FILE.erase(*curr_y, *curr_x);
        mvdelch(*curr_y, *curr_x);
        wmove(stdscr, *curr_y, *curr_x);
        break;
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
        _STATE.set_checkpoint_before_command();
        _STATE.set_state(COMMAND);
        break;
    }
    };

    reset_handled_status();
};