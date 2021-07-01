#include "common.hpp"
#include "./../../keys/keys.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../status/status.hpp"
#include "./../../colors/colors.hpp"
#include "./../../position/position.hpp"
#include "./../../history/history.hpp"
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

bool is_common_handled(int id)
{
    if (handler_status.count(id))
    {
        return handler_status[id];
    }
    return false;
};

void reset_handled_status()
{
    for (auto const &[key, _] : handler_status)
    {
        handler_status[key] = false;
    };
};

bool is_common_handler(int ch)
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

    // CharInserter char_inseter;

    switch (ch)
    {
    case KEY_UP:
    {
        // || !_FILE.exist_in_buf(*curr_y - 1)
        if (*curr_y == 0)
        {
            wscrl(stdscr, -1);
            // _PRESSED_HISTORY.translocation_up();
            //_POSITION.set_move(*curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
            break;
        };

        _POSITION.decy();
        //_POSITION.set_move(*curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
        break;
    }
    case KEY_DOWN:
    {
        if ((*curr_y + 1) == (*max_y - 1))
        {
            scroll(stdscr);
            // _PRESSED_HISTORY.translocation_down();
            break;
        };

        _POSITION.incy();
        //_POSITION.set_move(*curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
        break;
    }
    case KEY_LEFT:
    {
        _POSITION.decx();
        _POSITION.set_move(*curr_y, *curr_x);
        break;
    }
    case KEY_RIGHT:
    {
        _POSITION.incx();
        _POSITION.set_move(*curr_y, *curr_x);
        break;
    }
    case K_BACKSPACE:
    {
        _INSERT__BUF.pop();
        break;
    }
    };
};