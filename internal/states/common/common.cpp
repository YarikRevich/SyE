#include "common.hpp"
#include "./../../keys/keys.hpp"
#include "./../../file/file.hpp"
#include "./../../position/position.hpp"
#include "./../../history/history.hpp"

std::map<int, bool> handler_status = {
    {BACKSPACE, false},
};

void set_handled_status(int id, bool status)
{
    handler_status[id] = status;
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

void CommonHandler::handle(int ch)
{
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case K_BACKSPACE:
        if (is_handled(BACKSPACE))
            return;

        _PRESSED_HISTORY.delete_pressed(*curr_y, *curr_x - 1);
        _FILE.delete_from_buffer(*curr_y, *curr_x - 1);
        mvdelch(*curr_y, *curr_x - 1);
        wmove(stdscr, *curr_y, *curr_x - 1);
        if (*curr_x == 0)
        {
            _POSITION.decy();
            wmove(stdscr, *curr_y, _PRESSED_HISTORY.get_best_x(*curr_y));
        }
        else
        {
            _POSITION.decx();
        };
    };

    reset_handled_status();
};