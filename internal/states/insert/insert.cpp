#include "insert.hpp"
#include "./../../colors/colors.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../history/history.hpp"
#include "./../../status/status.hpp"
#include "./../../position/position.hpp"
#include "./../../keys/keys.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../common/common.hpp"

void InsertHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case K_ENTER:
    {
        if (*curr_y == (*max_y - 2))
        {
            _INSERT__BUF->set_ignore_forcible_move(true);
            _INSERT__BUF->add_C(ch, *curr_y, *curr_x);
            _INSERT__BUF->translocation_down();
            return;
        }
        _POSITION.set_start(false);
        if (!_INSERT__BUF->is_last_cell(*curr_y, *curr_x))
        {
            _INSERT__BUF->set_move(*curr_y + 1, 0);
            _INSERT__BUF->translocation_up_after_y(*curr_y);
        }
        break;
    }
    case K_COLON:
    {
        _PREV_HISTORY.set_prev_yx(*curr_y, *curr_x);

        int i = 0;
        while (i != *max_x - 1)
        {
            _EFFECTS__BUF->add_C(32, *max_y - 1, i);
            i++;
        }
        _INSERT__BUF->add_C(ch, *max_y - 1, 0);

        _INSERT__BUF->set_move(*max_y - 1, 1);

        _STATE.set_checkpoint_before_command();
        _STATE.set_state(COMMAND);
        return;
    }
    }

    if (!is_common_handler(ch))
    {
        // _LOG__BUF->add_L(*curr_x, INT);
        // _LOG__BUF->add_L(10, CHAR);
        if (*curr_x == (*max_x - 1))
        {
            _INSERT__BUF->add_C(ch, *curr_y, *curr_x);
            _INSERT__BUF->add_C(10, *curr_y, *curr_x + 1);
        }
        else
        {
            _INSERT__BUF->add_C(ch, *curr_y, *curr_x);
        }
    }
};
