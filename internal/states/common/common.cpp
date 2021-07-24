#include "common.hpp"

#include <stdlib.h>
#include "./helper/helper.hpp"
#include "./../../keys/keys.hpp"
#include "./../../colors/colors.hpp"
#include "./../../helper/helper.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../history/history.hpp"
#include "./../../position/position.hpp"
#include "./../../editor_status/editor_status.hpp"

int *CommonStateStorage::g_ch = (int *)std::malloc(sizeof(int));

void CommonStateUpHandler::includeWordAreaOffsetUp()
{
    wscrl(stdscr, -1);
    _INSERT__BUF->translocateYUp();

    CommonStateAutomation::setMoveForCurrentlyUsedStateBuffer(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
};

void CommonStateUpHandler::moveLineUp()
{

    Coords::decY();
    CommonStateAutomation::setMoveForCurrentlyUsedStateBuffer(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
};

void CommonStateUpHandler::use()
{
    if (EditorStatus::getCurrStatus() != COMMAND && !Position::isStartOfY())
    {

        if (!_INSERT__BUF->isStartRow(Coords::curr_y))
        {
            if (Coords::curr_y == 0)
            {
                CommonStateUpHandler::includeWordAreaOffsetUp();
                return;
            };
            CommonStateUpHandler::moveLineUp();
        }
        else
        {
            Position::setStartOfY(true);
        };
        _INSERT__BUF->setIgnoreForcibleMove(true);
        // CommonStateAutomation::setIgnoreForcibleMoveForAffectedBuffs(_INSERT__BUF, _COMMAND__BUF);
    }
};

void CommonStateDownHandler::includeWordAreaOffsetDown()
{
    scroll(stdscr);
    _INSERT__BUF->translocateYDown();
};

void CommonStateDownHandler::moveLineDown()
{
    Coords::incY();
    CommonStateAutomation::setMoveForCurrentlyUsedStateBuffer(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
};

void CommonStateDownHandler::use()
{
    if (EditorStatus::getCurrStatus() != COMMAND)
    {
        if ((Coords::curr_y + 1) == (Coords::max_y - 1))
        {
            CommonStateDownHandler::includeWordAreaOffsetDown();
            return;
        };
        CommonStateDownHandler::moveLineDown();
    }
};

void CommonStateLeftHandler::moveRowLeft()
{
    Position::setStartOfY(false);
    Coords::decX();
    CommonStateAutomation::setMoveForCurrentlyUsedStateBuffer(Coords::curr_y, Coords::curr_x);
};

void CommonStateLeftHandler::use()
{
    if (Coords::curr_x == 0 && _INSERT__BUF->cellIsSentenceHyphenation(Coords::curr_y - 1, _INSERT__BUF->getLastXInRow(Coords::curr_y - 1) - 1))
    {
        _INSERT__BUF->setMovement(Coords::curr_y - 1, _INSERT__BUF->getLastXInRow(Coords::curr_y - 1) - 1);
    }
    else if (Coords::curr_x == 0 || (EditorStatus::getCurrStatus() == COMMAND && (Coords::curr_x - 1) == 1))
    {
        Position::setStartOfX(true);
    }
    else if (Coords::curr_x != 0)
    {
        CommonStateLeftHandler::moveRowLeft();
    }
};

void CommonStateRightHandler::moveRowRight()
{
    Coords::incX();
    CommonStateAutomation::setMoveForCurrentlyUsedStateBuffer(Coords::curr_y, Coords::curr_x);
};

void CommonStateRightHandler::use()
{
    if ((!_INSERT__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x)) || (!_COMMAND__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x - 1)))
    {
        if (_INSERT__BUF->isBufCell(Coords::curr_y, Coords::curr_x + 1))
        {
            CommonStateRightHandler::moveRowRight();
        }
    }
    // CommonStateAutomation::setIgnoreForcibleMoveForAffectedBuffs(_INSERT__BUF, _COMMAND__BUF);
};

void CommonStateBackspaceHandler::moveBufferUp()
{
    _INSERT__BUF->setMovement(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
    _INSERT__BUF->setIgnoreForcibleMove(TRUE);
    _INSERT__BUF->translocateYDownAfter(Coords::curr_y);
};

void CommonStateBackspaceHandler::moveRowUp()
{
    _INSERT__BUF->eraseCell(Coords::curr_y, 0);
    Coords::decY();
    if (_INSERT__BUF->cellIsSentenceHyphenation(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y) - 1))
    {
        _INSERT__BUF->eraseCell(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y) - 1);
    }
    CommonStateBackspaceHandler::moveBufferUp();
};

void CommonStateBackspaceHandler::shiftRowToLeft()
{
    _INSERT__BUF->eraseCell(Coords::curr_y, Coords::curr_x - 1);
    _INSERT__BUF->translocateXLeftAfter(Coords::curr_y, Coords::curr_x);
};

void CommonStateBackspaceHandler::use()
{
    if (!_INSERT__BUF->getBufferIterator().empty())
    {
        if (Coords::curr_x == 0)
        {
            CommonStateBackspaceHandler::moveRowUp();
            return;
        }
        else if (!_INSERT__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x - 1))
        {
            CommonStateBackspaceHandler::shiftRowToLeft();
        }
        else
        {
            _INSERT__BUF->eraseCell(Coords::curr_y, Coords::curr_x - 1);
        }
        CommonStateAutomation::setMoveForCurrentlyUsedStateBuffer(Coords::curr_y, Coords::curr_x - 1);
    }
};

CommonState::CommonState(int ch)
{
    *CommonStateStorage::g_ch = ch;
};

void CommonState::use()
{
    switch (*CommonStateStorage::g_ch)
    {
    case KEY_UP:
    {
        CommonStateUpHandler::use();
        break;
    }
    case KEY_DOWN:
    {
        CommonStateDownHandler::use();
        break;
    }
    case KEY_LEFT:
    {
        CommonStateLeftHandler::use();
        break;
    }
    case KEY_RIGHT:
    {
        CommonStateRightHandler::use();
        break;
    }
    case K_BACKSPACE:
    {
        CommonStateBackspaceHandler::use();
        break;
    }
    };
};