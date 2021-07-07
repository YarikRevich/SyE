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

void set_move(int y, int x)
{
    //Sets move depending on the current state

    switch (_STATE.get_state())
    {
    case INSERT:
        _INSERT__BUF->set_move(y, x);
        break;
    case COMMAND:
        _COMMAND__BUF->set_move(y, x);
    }
};

void CommonHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case KEY_UP:
    {
        if (_STATE.get_state() != COMMAND && !_POSITION.is_start())
        {
            if (!_INSERT__BUF->is_start(*curr_y))
            {
                if (*curr_y == 0)
                {
                    wscrl(stdscr, -1);
                    _INSERT__BUF->translocation_up();

                    set_move(*curr_y, _INSERT__BUF->get_last_x(*curr_y));
                    return;
                };
                _POSITION.decy();
                set_move(*curr_y, _INSERT__BUF->get_last_x(*curr_y));
            }
            else
            {
                _POSITION.set_start(true);
            };
        }
        break;
    }
    case KEY_DOWN:
    {
        if (_STATE.get_state() != COMMAND && !_POSITION.is_start())
        {
            if ((*curr_y + 1) == (*max_y - 1))
            {
                scroll(stdscr);
                _INSERT__BUF->translocation_down();
                break;
            };

            _POSITION.set_start(false);
            _POSITION.incy();
            set_move(*curr_y, _INSERT__BUF->get_last_x(*curr_y));
        }
        break;
    }
    case KEY_LEFT:
    {
        if (*curr_x != 0)
        {
            _POSITION.set_start(false);
            _POSITION.decx();
            set_move(*curr_y, *curr_x);
        }
        _INSERT__BUF->set_ignore_forcible_move(true);
        _COMMAND__BUF->set_ignore_forcible_move(true);
        break;
    }
    case KEY_RIGHT:
    {
        // _LOG__BUF->add_L(!_INSERT__BUF->is_last_cell(*curr_y, *curr_x-1), INT);
        // _LOG__BUF->add_L(10, CHAR);
        if (!_INSERT__BUF->is_last_cell(*curr_y, *curr_x - 1)) //!_COMMAND__BUF->is_last_cell(*curr_y, *curr_x - 1))
        {
            _POSITION.set_start(false);
            _POSITION.incx();
            set_move(*curr_y, *curr_x);
        }
        _INSERT__BUF->set_ignore_forcible_move(true);
        _COMMAND__BUF->set_ignore_forcible_move(true);
        break;
    }
    case K_BACKSPACE:
    {
        if (!_INSERT__BUF->get().empty())
        {
            if (*curr_x == 0)
            {
                _POSITION.decy();
                _INSERT__BUF->erase(*curr_y, _INSERT__BUF->get_last_x(*curr_y));
                _INSERT__BUF->erase(*curr_y, _INSERT__BUF->get_last_x(*curr_y)-1);
                _INSERT__BUF->set_move(*curr_y, _INSERT__BUF->get_last_x(*curr_y));
                _INSERT__BUF->set_ignore_forcible_move(TRUE);
                // _INSERT__BUF->translocation_down_after_y(*curr_y);
                break;
            }
            else if (!_INSERT__BUF->is_last_cell(*curr_y, *curr_x - 1))
            {
                _INSERT__BUF->erase(*curr_y, *curr_x - 1);
                //_INSERT__BUF->translocation_left_after_x(*curr_y, *curr_x);
            }
            else
            {
                _INSERT__BUF->erase(*curr_y, *curr_x - 1);
            }

            set_move(*curr_y, *curr_x - 1);
        }
        break;
    }
    };
};