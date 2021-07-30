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
    if (!CommonStateHelper::isCommonKeyHandler(*InsertStateStorage::g_ch))
    {
        if (_INSERT__BUF->getBufferIterator().empty())
        {
            _INSERT__BUF->addCellWithCoords(' ', 0, 0);
        }

        if (Coords::curr_x == (Coords::max_x - 1))
        {
            InsertStateDefaultHandler::moveCariage();
        }
        else

        {
            // _LOG__BUF->addCellWithSymbolType(10, CHAR);
            // for (auto i : std::string(" NEW !"))
            // {
            //     _LOG__BUF->addCellWithSymbolType(i, CHAR);
            // };
            // _LOG__BUF->addCellWithSymbolType('Q', CHAR);

            if (_INSERT__BUF->isBufCell(Coords::curr_y, Coords::curr_x))
            {

                // _LOG__BUF->addCellWithSymbolType(this->buf[i - 1]->coords.y, INT);
                // _LOG__BUF->addCellWithSymbolType(10, CHAR);
                // _LOG__BUF->addCellWithSymbolType(this->buf[i - 1]->coords.x, INT);
                _INSERT__BUF->translocateXRightAfter(Coords::curr_y, Coords::curr_x);
            }

            if (isWideChar(*InsertStateStorage::g_ch))
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
    while (pos != Coords::max_x - 1)
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
