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

    _COMMAND__BUF->set_ignore_forcible_move(true);

    switch (ch)
    {
    case K_BACKSPACE:
    {
        if (*curr_x - 1 == 0)
        {
            _EFFECTS__BUF->clear();
            _INSERT__BUF->erase(*curr_y, 0);
            _COMMAND__BUF->clear();
            _STATE.set_state(_STATE.get_checkpoint_before_command());
            _INSERT__BUF->set_move(prev_y, prev_x);
            set_handled_status(K_BACKSPACE);
            _INSERT__BUF->set_ignore_forcible_move(true);
            break;
        };
        _COMMAND__BUF->set_move(*curr_y, *curr_x - 1);
        _COMMAND__BUF->erase(*curr_y, *curr_x - 1);
        set_handled_status(K_BACKSPACE);
        _INSERT__BUF->set_ignore_forcible_move(true);
        break;
    }
    case K_ENTER:
    {
        _EFFECTS__BUF->clear();
        _INSERT__BUF->erase(*max_y - 1, 0);
        apply_command(_COMMAND__BUF->get_as_string());
        _COMMAND__BUF->clear();
        _STATE.set_state(_STATE.get_checkpoint_before_command());
        _INSERT__BUF->set_move(prev_y, prev_x);
        set_handled_status(K_ENTER);
        break;
    };
    default:
        if (!is_common_handler(ch) && (*curr_x != (*max_x - 1)))
        {
            _COMMAND__BUF->add_C(ch, *curr_y, *curr_x);
        }
    }
};