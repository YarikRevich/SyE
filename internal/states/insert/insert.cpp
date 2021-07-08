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
            _INSERT__BUF->setIgnoreForcibleMove(true);
            _INSERT__BUF->addCellWithCoords(ch, *curr_y, *curr_x);
            _INSERT__BUF->translocateYDown();
            return;
        }
        _POSITION.setStartOfY(false);
        if (!_INSERT__BUF->isLastBufCell(*curr_y, *curr_x))
        {
            _INSERT__BUF->setMovement(*curr_y + 1, 0);
            _INSERT__BUF->translocateYUpAfter(*curr_y);
        }
        break;
    }
    case K_COLON:
    {
        _PREV_HISTORY.set_prev_yx(*curr_y, *curr_x);

        int i = 0;
        while (i != *max_x - 1)
        {
            _EFFECTS__BUF->addCellWithCoords(32, *max_y - 1, i);
            i++;
        }
        _INSERT__BUF->addCellWithCoords(ch, *max_y - 1, 0);

        _INSERT__BUF->setMovement(*max_y - 1, 1);

        _STATE.set_checkpoint_before_command();
        _STATE.set_state(COMMAND);
        return;
    }
    }

    if (!is_common_handler(ch))
    {
        if (*curr_x == (*max_x - 1))
        {
            //  _LOG__BUF->addCellWithSymbolType('O', CHAR);
            _INSERT__BUF->addCellWithCoords(ch, *curr_y, *curr_x);
            _INSERT__BUF->addCellWithCoords(10, *curr_y, *curr_x + 1);
            _INSERT__BUF->setCellSentenceHyphenation(*curr_y, *curr_x, TRUE);
        }
        else
        {
            _INSERT__BUF->addCellWithCoords(ch, *curr_y, *curr_x);
        }
    }
};
