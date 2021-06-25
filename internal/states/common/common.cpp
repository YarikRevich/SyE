#include "common.hpp"
#include "./../../keys/keys.hpp"
#include "./../../file/file.hpp"
#include "./../../state/state.hpp"
#include "./../../colors/colors.hpp"
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
    auto [max_y, max_x] = _POSITION.get_max_coords();
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
        break;
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
        _STATE.set_checkpoint_before_command();
        _STATE.set_state(COMMAND);
        return;
    }
    };

    reset_handled_status();
};