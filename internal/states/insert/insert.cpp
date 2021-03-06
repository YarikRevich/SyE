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

bool InsertStateStorage::await;

void InsertStateDefaultHandler::moveCariage()
{
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x);
    _INSERT__BUF->addCellWithCoords(10, Coords::curr_y, Coords::curr_x + 1);
    _INSERT__BUF->setCellSentenceHyphenation(Coords::curr_y, Coords::curr_x, TRUE);
    Coords::incY(), Coords::resetX();
};

void InsertStateDefaultHandler::includeWideChar()
{
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x);

    if (!InsertStateStorage::await)
    {
        InsertStateStorage::await = true;
    }
    else
    {
        InsertStateStorage::await = false;
        Coords::incX();
    }
};

void InsertStateDefaultHandler::use()
{
    if (!CommonStateHelper::isCommonKeyHandler(*InsertStateStorage::g_ch) &&
        !CommonStateHelper::isKeyException(*InsertStateStorage::g_ch))
    {
        // _LOG__BUF->addCellWithSymbolType(*InsertStateStorage::g_ch, INT);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        if (Coords::curr_x == (Coords::max_x - 1))
        {
            InsertStateDefaultHandler::moveCariage();
        }
        else
        {
            // if (_INSERT__BUF->isBufCell(Coords::curr_y, Coords::curr_x))
            // {
            //     _LOG__BUF->addCellWithSymbolType('B', CHAR);
            //     _INSERT__BUF->translocateXRightAfter(Coords::curr_y, Coords::curr_x);
            // }

            if (wide_char(*InsertStateStorage::g_ch))
            {
                InsertStateDefaultHandler::includeWideChar();
            }
            else
            {
                _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x);
                Coords::incX();
            };
        }
    }
};

void InsertStateEnterHandler::includeWordAreaOffsetDown()
{
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::curr_y, Coords::curr_x);
    _INSERT__BUF->translocateYDown();
    Coords::resetX();
    clear();
};

void InsertStateEnterHandler::moveCariage()
{
    _INSERT__BUF->translocateYUpAfter(Coords::curr_y);
    Coords::resetX(), Coords::incY();
};

void InsertStateEnterHandler::use()
{
    if (Coords::curr_y == (Coords::max_y - 2))
    {
        InsertStateEnterHandler::includeWordAreaOffsetDown();
        return;
    }
    InsertStateDefaultHandler::use();
    InsertStateEnterHandler::moveCariage();
};

void InsertStateColonHandler::fillPanelWithSpaces()
{
    int pos = 0;
    while (pos != Coords::max_x - WIDGET_AREA)
    {
        _EFFECTS__BUF->addCellWithCoords(32, Coords::max_y - 1, pos);
        pos++;
    };
};

void InsertStateColonHandler::modifyBuffer()
{
    _INSERT__BUF->addCellWithCoords(*InsertStateStorage::g_ch, Coords::max_y - 1, 0);
    Coords::setY(Coords::max_y - 1), Coords::setX(1);
};

void InsertStateColonHandler::modifyState()
{
    EditorStatus::setCheckpoint();
    EditorStatus::setCurrStatus(COMMAND);
};

void InsertStateColonHandler::use()
{
    PressHistoryCommand->set(Coords::curr_y, Coords::curr_x);

    InsertStateColonHandler::fillPanelWithSpaces();
    InsertStateColonHandler::modifyBuffer();
    InsertStateColonHandler::modifyState();
};

void InsertStateTabHandler::use()
{
    for (int i = 0; i < 4; i++)
    {
        if ((Coords::curr_x + i) <= Coords::max_x)
        {
            Coords::incX();
        }
        else
        {
            Coords::incY();
            Coords::setX(0);
        }
        _INSERT__BUF->addCellWithCoords(0, Coords::curr_y, Coords::curr_x);
    };
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
    case K_TAB:
    {
        InsertStateTabHandler::use();
        break;
    }
    default:
    {
        InsertStateDefaultHandler::use();
    }
    };
};
