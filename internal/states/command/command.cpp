#include "command.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../../keys/keys.hpp"
#include "./../common/common.hpp"
#include "./../../status/status.hpp"
#include "./../../colors/colors.hpp"
#include "./../../commands/pool.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../history/history.hpp"
#include "./../../position/position.hpp"

void CommandHandler::handle(int ch)
{
    auto [prev_y, prev_x] = _PREV_HISTORY.get_prev_yx();
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case K_BACKSPACE:
    {
        if (*curr_x - 1 == 0)
        {
            _INSERT__BUF.erase(*max_y - 1, 0);

            _COMMAND__BUF.clear();

            _STATE.set_state(_STATE.get_checkpoint_before_command());

            _POSITION.set_move(prev_y, prev_x);

            _COLORS.turn_off_command_theme();

            set_handled_status(K_BACKSPACE);
            break;
        };
        int b = 1;
        while (b != *max_x - 1)
        {
            _EFFECTS__BUF.add_C(32, *max_y - 1, b);
            b++;
        }

        _POSITION.set_move(*max_y - 1, 1);

        _COMMAND__BUF.pop();

        set_handled_status(K_BACKSPACE);
        break;
    }
    case K_ENTER:
    {
        _INSERT__BUF.erase(*max_y - 1, 0);

        apply_command(_COMMAND__BUF.get_as_string());

        _COMMAND__BUF.clear();

        _STATE.set_state(_STATE.get_checkpoint_before_command());

        _POSITION.set_move(prev_y, prev_x);

        _COLORS.turn_off_command_theme();

        set_handled_status(K_BACKSPACE);
        break;
    };
    default:
        if (!is_common_handler(ch) && (*curr_x != (*max_x - 1)))
        {
            _COMMAND__BUF.add_C(ch, *curr_y, *curr_x);
        }
    }
};