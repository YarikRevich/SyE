#include "common.hpp"
#include "./../../keys/keys.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../status/status.hpp"
#include "./../../colors/colors.hpp"
#include "./../../position/position.hpp"
#include "./../../history/history.hpp"
#include "./../../margin/margin.hpp"

std::map<int, bool> handler_status = {
    {K_BACKSPACE, false},
    {K_COLON, false},
    {KEY_UP, false},
    {KEY_DOWN, false},
    {KEY_LEFT, false},
    {KEY_RIGHT, false},
};

void set_handled_status(int id)
{
    handler_status[id] = true;
};

bool is_common_handled(int id)
{
    if (handler_status.count(id))
    {
        return handler_status[id];
    }
    return false;
};

void reset_handled_status()
{
    for (auto const &[key, _] : handler_status)
    {
        handler_status[key] = false;
    };
};

bool is_common_handler(int ch)
{
    for (auto const &[key, val] : handler_status)
    {
        if (key == ch)
        {
            return true;
        }
    }
    return false;
};

void set_move(int y, int x)
{
    //Sets move depending on the current state

    switch (_STATE.get_state())
    {
    case INSERT:
        _INSERT__BUF->setMovement(y, x);
        break;
    case COMMAND:
        _COMMAND__BUF->setMovement(y, x);
    }
};

void CommonHandler::handle(int ch)
{
    auto [max_y, max_x] = _POSITION.get_max_coords();
    auto [curr_y, curr_x] = _POSITION.get_curr_coords();

    switch (ch)
    {
    case KEY_UP:
    {
        if (_STATE.get_state() != COMMAND && !_POSITION.isStartOfY())
        {
            if (!_INSERT__BUF->isStartRow(*curr_y))
            {
                if (*curr_y == 0)
                {
                    wscrl(stdscr, -1);
                    _INSERT__BUF->translocateYUp();

                    set_move(*curr_y, _INSERT__BUF->getLastXInRow(*curr_y));
                    return;
                };
                _POSITION.decy();
                set_move(*curr_y, _INSERT__BUF->getLastXInRow(*curr_y));
            }
            else
            {
                _POSITION.setStartOfY(true);
            };
        }
        break;
    }
    case KEY_DOWN:
    {
        if (_STATE.get_state() != COMMAND && !_POSITION.isStartOfY())
        {
            if ((*curr_y + 1) == (*max_y - 1))
            {
                scroll(stdscr);
                _INSERT__BUF->translocateYDown();
                break;
            };
            _POSITION.incy();
            set_move(*curr_y, _INSERT__BUF->getLastXInRow(*curr_y));
        }
        break;
    }
    case KEY_LEFT:
    {
        _LOG__BUF->addCellWithSymbolType(*curr_x, INT);
        _LOG__BUF->addCellWithSymbolType(10, CHAR);

        if (*curr_x == 0 || (_STATE.get_state() == COMMAND && (*curr_x - 1) == 1))
        {
            _POSITION.setStartOfX(true);
        }
        else if (*curr_x != 0)
        {
            _POSITION.setStartOfY(false);
            _POSITION.decx();
            set_move(*curr_y, *curr_x);
        }
        // _INSERT__BUF->setIgnoreForcibleMove(true);
        // _COMMAND__BUF->setIgnoreForcibleMove(true);
        break;
    }
    case KEY_RIGHT:
    {
        // _LOG__BUF->add_L(!_INSERT__BUF->is_last_cell(*curr_y, *curr_x-1), INT);
        // _LOG__BUF->add_L(10, CHAR);
        if ((!_INSERT__BUF->isLastBufCell(*curr_y, *curr_x)) || (!_COMMAND__BUF->isLastBufCell(*curr_y, *curr_x - 1)))
        {
            _POSITION.incx();
            set_move(*curr_y, *curr_x);
        }
        // _INSERT__BUF->setIgnoreForcibleMove(true);
        // _COMMAND__BUF->setIgnoreForcibleMove(true);
        break;
    }
    case K_BACKSPACE:
    {
        if (!_INSERT__BUF->getBuf().empty())
        {
            if (*curr_x == 0)
            {
                _INSERT__BUF->eraseCell(*curr_y, 0);
                _POSITION.decy();
                if (_INSERT__BUF->cellIsSentenceHyphenation(*curr_y, _INSERT__BUF->getLastXInRow(*curr_y) - 1))
                {
                _INSERT__BUF->eraseCell(*curr_y, _INSERT__BUF->getLastXInRow(*curr_y) - 1);
                }
                _INSERT__BUF->setMovement(*curr_y, _INSERT__BUF->getLastXInRow(*curr_y));
                _INSERT__BUF->setIgnoreForcibleMove(TRUE);
                _INSERT__BUF->translocateYDownAfter(*curr_y);
                break;
            }
            else if (!_INSERT__BUF->isLastBufCell(*curr_y, *curr_x - 1))
            {
                _INSERT__BUF->eraseCell(*curr_y, *curr_x - 1);
                _INSERT__BUF->translocateXLeftAfter(*curr_y, *curr_x);
            }
            else
            {
                _INSERT__BUF->eraseCell(*curr_y, *curr_x - 1);
            }

            set_move(*curr_y, *curr_x - 1);
        }
        break;
    }
    };
};