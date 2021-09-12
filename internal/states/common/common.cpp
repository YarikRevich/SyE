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

    Coords::setX(_INSERT__BUF->getLastXInRow(Coords::curr_y));
};

void CommonStateUpHandler::moveLineUp()
{
    // if (PressHistoryStandard->x == 0 ||   != 0){

    // }
    Coords::decY(), Coords::setX(_INSERT__BUF->getLastXInRow(Coords::curr_y));

    // const int x = ;
    // if (x == UNDEFINED){
    //     Coords::setX(0);
    // }else{
    //     Coords::setX(x);
    // }
};

void CommonStateUpHandler::use()
{
    if (EditorStatus::getCurrStatus() == INSERT && !Position::isStartOfY())
    {

        if (!_INSERT__BUF->isStartRow(Coords::curr_y))
        {
            if (Coords::curr_y == 0)
            {
                // CommonStateUpHandler::includeWordAreaOffsetUp();
                return;
            };
            CommonStateUpHandler::moveLineUp();
        }
    }
};

void CommonStateDownHandler::includeWordAreaOffsetDown()
{
    scroll(stdscr);
    _INSERT__BUF->translocateYDown();
};

void CommonStateDownHandler::moveLineDown()
{
    Coords::incY(), Coords::setX(_INSERT__BUF->getLastXInRow(Coords::curr_y));
};

void CommonStateDownHandler::use()
{
    if (EditorStatus::getCurrStatus() == INSERT)
    {
        if ((Coords::curr_y + 1) == (Coords::max_y - 1))
        {
            //   CommonStateDownHandler::includeWordAreaOffsetDown();
            return;
        }

        if (PressHistoryStandard->x == 0 && _INSERT__BUF->getRowLength(Coords::curr_y + 1) == 0)
        {
            return;
        }

        CommonStateDownHandler::moveLineDown();
    }
};

void CommonStateLeftHandler::use()
{
    if (Coords::curr_x == 0 && _INSERT__BUF->cellIsSentenceHyphenation(Coords::curr_y - 1, _INSERT__BUF->getLastXInRow(Coords::curr_y - 1) - 1))
    {
        Coords::decY(), Coords::setX(_INSERT__BUF->getLastXInRow(Coords::curr_y - 1) - 1);
    }
    else if (EditorStatus::getCurrStatus() == INSERT && Coords::curr_x != 0 ||
             (EditorStatus::getCurrStatus() == COMMAND && Coords::curr_x != 1))
    {
        Coords::decX();
    }
};

void CommonStateRightHandler::use()
{
    if ((!_INSERT__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x)) ||
        (!_COMMAND__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x - 1)))
    {
        if (_INSERT__BUF->isBufCell(Coords::curr_y, Coords::curr_x) ||
            _COMMAND__BUF->isBufCell(Coords::curr_y, Coords::curr_x))
        {
            Coords::incX();
        };
    };
};

void CommonStateBackspaceHandler::moveBufferUp()
{
    _INSERT__BUF->translocateYDownAfter(Coords::curr_y);
    Coords::setX(_INSERT__BUF->getLastXInRow(Coords::curr_y));
};

void CommonStateBackspaceHandler::moveRowUp()
{
    auto &&buf = _INSERT__BUF->getBufferIterator();
    for (int i = 0; i < buf.size(); ++i)
    {
        _LOG__BUF->addCellWithSymbolType(buf[i]->coords.y, INT);
        _LOG__BUF->addCellWithSymbolType(' ', CHAR);
        _LOG__BUF->addCellWithSymbolType(buf[i]->coords.x, INT);
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
        _LOG__BUF->addCellWithSymbolType(buf[i]->sentenceHyphenation, INT);
        _LOG__BUF->addCellWithSymbolType(10, CHAR);

        _LOG__BUF->addCellWithSymbolType(buf[i]->symbol, INT);
        _LOG__BUF->addCellWithSymbolType(10, CHAR);
    };

    Coords::decY();

    Deleters::last_in_row_delch();
    _INSERT__BUF->eraseCell(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y));
    
    if (_INSERT__BUF->cellIsSentenceHyphenation(Coords::curr_y, _INSERT__BUF->getLastXInRow(Coords::curr_y) - 1))
    {
        Deleters::hyphination_last_in_row_delch();
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
    if (EditorStatus::getCurrStatus() == INSERT && !(Coords::curr_x == 0 && Coords::curr_y == 0))
    {
        if (Coords::curr_x == 0 && _INSERT__BUF->isRowEmpty(Coords::curr_y))
        {
            CommonStateBackspaceHandler::moveRowUp();
            return;
        }
        else if (!_INSERT__BUF->isLastBufCell(Coords::curr_y, Coords::curr_x - 1))
        {
            CommonStateBackspaceHandler::shiftRowToLeft();
        }

        Coords::decX();

        _INSERT__BUF->eraseCell(Coords::curr_y, Coords::curr_x);
        Deleters::sequencial_delch();
    };
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
        // _LOG__BUF->addCellWithSymbolType('Y', CHAR);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        // _LOG__BUF->addCellWithSymbolType(Coords::curr_y, INT);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        // _LOG__BUF->addCellWithSymbolType('X', CHAR);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        // _LOG__BUF->addCellWithSymbolType(Coords::curr_x, INT);
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        // for (const auto &q : std::string{"INSERT BUF"})
        // {
        //     _LOG__BUF->addCellWithSymbolType(q, CHAR);
        // };
        // _LOG__BUF->addCellWithSymbolType(10, CHAR);

        // for (const auto &r : _INSERT__BUF->getBufferIterator())
        // {
        //     _LOG__BUF->addCellWithSymbolType(r->symbol, INT);
        //     _LOG__BUF->addCellWithSymbolType(10, CHAR);
        // };
        break;
    }
    };
};