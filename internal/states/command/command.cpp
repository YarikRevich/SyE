#include "command.hpp"
#include "./commands/pool.hpp"
#include "./../../keys/keys.hpp"
#include "./../common/common.hpp"
#include "./../../status/status.hpp"
#include "./../../colors/colors.hpp"
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
    case K_ENTER:
    {
        int i = 0;
        do
        {
            _FILE.erase(*curr_y, *max_x - i);
            _POSITION.decx();
            i++;
        } while (i != *max_x);

        _POSITION.set_move(prev_y, prev_x);
        _COLORS.turn_off_command_theme();
        _STATE.set_state(_STATE.get_checkpoint_before_command());
        _COMMAND_TOOL.apply_command(_COMMAND_TOOL.get_command());
        _COMMAND_TOOL.delete_command();
        break;
    }
    case K_BACKSPACE:
    {
        if (*curr_x - 1 == 0)
        {
            int i = 0;
            do
            {
                _FILE.erase(*curr_y, *max_x - i);
                i++;
            } while (i != *max_x + 1);
            _POSITION.set_move(prev_y, prev_x);
            _STATE.set_state(_STATE.get_checkpoint_before_command());
            _COLORS.turn_off_command_theme();
            _COMMAND_TOOL.delete_command();
            set_handled_status(K_BACKSPACE);
            break;
        };

        int b = 0;
        while (b != *max_x - 1)
        {
            _FILE.add(32, *max_y - 1, b);
            b++;
        }
        _COMMAND_TOOL.pop_symbol_from_command();

        auto const c = _COMMAND_TOOL.get_command();
        int increaser = 0;
        _FILE.add(':', *max_y - 1, increaser);
        for (int i = 0; i < c.size(); i++)
        {
            increaser++;
            _FILE.add(c[i], *max_y - 1, increaser);
        }
        set_handled_status(K_BACKSPACE);
        break;
    }
    default:
        _COMMAND_TOOL.set_command(ch);
        _FILE.add(ch, *curr_y, *curr_x);
    }
};