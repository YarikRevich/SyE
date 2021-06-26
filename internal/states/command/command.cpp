#include "command.hpp"
#include "./../../state/state.hpp"
#include "./../../keys/keys.hpp"
#include "./../../file/file.hpp"
#include "./../../colors/colors.hpp"
#include "./../../position/position.hpp"
#include "./../../history/history.hpp"
#include "./../common/common.hpp"
#include "./commands/commands.hpp"

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
            mvdelch(*curr_y, *max_x - i);
            _POSITION.decx();
            i++;
        } while (i != *max_x + 1);

        wmove(stdscr, prev_y, prev_x);
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
                mvdelch(*curr_y, *max_x - i);
                i++;
            } while (i != *max_x + 1);
            wmove(stdscr, prev_y, prev_x);
            _STATE.set_state(_STATE.get_checkpoint_before_command());
            _COLORS.turn_off_command_theme();
            _COMMAND_TOOL.delete_command();
            set_handled_status(K_BACKSPACE);
            break;
        };
        int b = 0;
        while (b != *max_x - 1)
        {
            mvwprintw(stdscr, *max_y - 1, b, "%c", 32);
            b++;
        }
        _COMMAND_TOOL.pop_symbol_from_command();
        mvwprintw(stdscr, *max_y - 1, 0, ":%s", _COMMAND_TOOL.get_command().c_str());
        set_handled_status(K_BACKSPACE);
        break;
    }
    default:
        _COMMAND_TOOL.set_command(ch);
        wprintw(stdscr, "%c", ch);
    }
};