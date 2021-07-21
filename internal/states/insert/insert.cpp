#include "insert.hpp"
#include "./../../colors/colors.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../history/history.hpp"
#include "./../../status/status.hpp"
#include "./../../position/position.hpp"
#include "./../../keys/keys.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../common/common.hpp"

InsertState::InsertState(int ch)
{
    this->m_ch = ch;

    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    this->m_max_y = *max_y;
    this->m_max_x = *max_x;
    this->m_curr_y = *curr_y;
    this->m_curr_x = *curr_x;
};

void InsertState::use()
{
    switch (this->m_ch)
    {
    case K_ENTER:
    {
        this->handle_enter();
        break;
    }
    case K_COLON:
    {
        this->handle_colon();
        break;
    }
    default:
    {
        this->handle_default();
    }
    };
};

void KeyHandlers::handle_default()
{
    if (!is_common_handler(this->m_ch))
    {
        if (this->m_curr_x == (this->m_max_x - 1))
        {
            _INSERT__BUF->addCellWithCoords(this->m_ch, this->m_curr_y, this->m_curr_x);
            _INSERT__BUF->addCellWithCoords(10, this->m_curr_y, this->m_curr_x + 1);
            _INSERT__BUF->setCellSentenceHyphenation(this->m_curr_y, this->m_curr_x, TRUE);
        }
        else
        {
            _INSERT__BUF->addCellWithCoords(m_ch, this->m_curr_y, this->m_curr_x);
        }
    }
};

void KeyHandlers::handle_colon()
{
    _PREV_HISTORY.set_prev_yx(this->m_curr_y, this->m_curr_x);

    int i = 0;
    while (i != this->m_max_x - 1)
    {
        _EFFECTS__BUF->addCellWithCoords(32, this->m_max_y - 1, i);
        i++;
    }
    _INSERT__BUF->addCellWithCoords(this->m_ch, this->m_max_y - 1, 0);

    _INSERT__BUF->setMovement(this->m_max_y - 1, 1);

    _STATE.set_checkpoint_before_command();
    _STATE.set_state(COMMAND);
};

void KeyHandlers::handle_enter()
{
    if (this->m_curr_y == (this->m_max_y - 2))
    {
        _INSERT__BUF->setIgnoreForcibleMove(true);
        _INSERT__BUF->addCellWithCoords(m_ch, this->m_curr_y, this->m_curr_x);
        _INSERT__BUF->translocateYDown();
        return;
    }
    _POSITION.setStartOfY(false);
    if (!_INSERT__BUF->isLastBufCell(this->m_curr_y, this->m_curr_x))
    {
        _INSERT__BUF->setMovement(this->m_curr_y + 1, 0);
        _INSERT__BUF->translocateYUpAfter(this->m_curr_y);
    }
    this->handle_default();
};