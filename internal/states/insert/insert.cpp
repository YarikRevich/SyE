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
            _INSERT__BUF.add_C(ch, *curr_y, *curr_x);
            _INSERT__BUF.translocation_down();
            return;
        }
        break;
    }
    case K_COLON:
    {
        _PREV_HISTORY.set_prev_yx(*curr_y, *curr_x);
        _COLORS.turn_on_command_theme();

        int i = 0;
        while (i != *max_x - 1)
        {
            _EFFECTS__BUF.add_C(32, *max_y - 1, i);
            i++;
        }
        _INSERT__BUF.add_C(ch, *max_y - 1, 0);

        _POSITION.set_move(*max_y - 1, 1);

        _STATE.set_checkpoint_before_command();
        _STATE.set_state(COMMAND);
        return;
    }
    }

    if (!is_common_handler(ch))
    {
        _INSERT__BUF.add_C(ch, *curr_y, *curr_x);
    }
    // auto [t, ok] = ctrl(ch);
    // if (ok)
    // {
    //     for (int i = 0; i < t.size(); i++)
    //     {
    //         _FILE.add(t[i], *curr_y, *curr_x - i);
    //     }
    // }

    // std::string m = std::to_string(_INSERT__BUF.get().size()) + " IS SIZE\n";
    // for (int i = 0; i < m.size(); i++)
    // {
    //     _LOG__BUF.add(m[i]);
    // }
};
