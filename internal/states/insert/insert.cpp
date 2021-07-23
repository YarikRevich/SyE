#include "insert.hpp"

#include <stdlib.h>
#include "./../../keys/keys.hpp"
#include "./../../bufs/bufs.hpp"
#include "./../common/common.hpp"
#include "./../../colors/colors.hpp"
#include "./../../helper/helper.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../history/history.hpp"
#include "./../../position/position.hpp"
#include "./../common/helper/helper.hpp"
#include "./../../editor_status/editor_status.hpp"

int *InsertStateStorage::g_ch = (int *)std::malloc(sizeof(int));

void InsertStateDefaultHandler::moveCariage()
{
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x);
    _INSERT__BUF->addCellWithCoords(10, Coords::curr_y, Coords::curr_x + 1, isWideChar(*InsertStateStorage::g_ch));
    _INSERT__BUF->setCellSentenceHyphenation(Coords::curr_y, Coords::curr_x, TRUE);
};

void InsertStateDefaultHandler::use()
{
    if (!CommonStateHelper::isCommonKeyHandler(*InsertStateStorage::g_ch))
    {
        if (Coords::curr_x == (Coords::max_x - 1))
        {
            InsertStateDefaultHandler::moveCariage();
        }
        else
        {
            _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x, isWideChar(*InsertStateStorage::g_ch));
        }
    }
};

void InsertStateEnterHandler::includeWordAreaOffset()
{
    _INSERT__BUF->setIgnoreForcibleMove(true);
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x);
    _INSERT__BUF->translocateYDown();
};

void InsertStateEnterHandler::moveCariage()
{
    Position::setStartOfY(false);
    if (!_INSERT__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x))
    {
        _INSERT__BUF->setMovement(Coords::curr_y + 1, 0);
        _INSERT__BUF->translocateYUpAfter(Coords::curr_y);
    }
};

void InsertStateEnterHandler::use()
{
    if (Coords::curr_y == (Coords::max_y - 2))
    {
        InsertStateEnterHandler::includeWordAreaOffset();
        return;
    }
    InsertStateEnterHandler::moveCariage();
    InsertStateDefaultHandler::use();
};

void InsertStateColonHandler::fillPanelWithSpaces()
{
    int pos = 0;
    while (pos != Coords::max_x - 1)
    {
        _EFFECTS__BUF->addCellWithCoords(32, Coords::max_y - 1, pos);
        pos++;
    };
};

void InsertStateColonHandler::modifyBuffer()
{
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::max_y - 1, 0);
    _INSERT__BUF->setMovement(Coords::max_y - 1, 1);
};

void InsertStateColonHandler::modifyState()
{
    EditorStatus::setCheckpoint();
    EditorStatus::setCurrStatus(COMMAND);
};

void InsertStateColonHandler::use()
{
    PreviouslyPressedHistory::set(Coords::curr_y, Coords::curr_x);

    InsertStateColonHandler::fillPanelWithSpaces();
    InsertStateColonHandler::modifyBuffer();
    InsertStateColonHandler::modifyState();
};

InsertState::InsertState(int ch)
{
    *InsertStateStorage::g_ch = ch;
};

void InsertState::use()
{
    switch (*InsertStateStorage::g_ch)
    {
    case K_ENTER:
    {
        InsertStateEnterHandler::use();
        break;
    }
    case K_COLON:
    {
        InsertStateColonHandler::use();
        break;
    }
    default:
    {
        InsertStateDefaultHandler::use();
    }
    };
};
