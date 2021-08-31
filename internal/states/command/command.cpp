#include "command.hpp"

#include <stdlib.h>
#include "./../../bufs/bufs.hpp"
#include "./../../keys/keys.hpp"
#include "./../common/common.hpp"
#include "./../../colors/colors.hpp"
#include "./../../helper/helper.hpp"
#include "./../../files/exec/exec.hpp"
#include "./../../history/history.hpp"
#include "./../common/helper/helper.hpp"
#include "./../../position/position.hpp"
#include "./../../editor_status/editor_status.hpp"
#include "./../../commands/applicator/applicator.hpp"

int *CommandStateStorage::g_ch = (int *)std::malloc(sizeof(int));

void CommandStateDefaultHandler::use()
{
    if (!CommonStateHelper::isCommonKeyHandler(*CommandStateStorage::g_ch) && (Coords::curr_x != (Coords::max_x - 1)))
    {
        _COMMAND__BUF->addCellWithCoords(*CommandStateStorage::g_ch, Coords::curr_y, Coords::curr_x);
        Coords::incX();
    }
};

void CommandStateEnterHandler::cleanBuffers()
{
    _EFFECTS__BUF->clearBuf();
    _COMMAND__BUF->clearBuf();
};

void CommandStateEnterHandler::modifyState()
{
    EditorStatus::setCurrStatus(EditorStatus::getCheckpoint());
    CommonStateHelper::setKeyHandled(K_ENTER);
};

void CommandStateEnterHandler::use()
{
    _INSERT__BUF->eraseCell(Coords::max_y - 1, 0);

    if (Applicator::applyCommand(_COMMAND__BUF->getBufAsString()))
    {
        Coords::setY(PreviouslyPressedHistory::y), Coords::setX(PreviouslyPressedHistory::x);
    }

    CommandStateEnterHandler::cleanBuffers();

    CommandStateEnterHandler::modifyState();
};

void CommandStateBackspaceHandler::cleanBuffers()
{
    _EFFECTS__BUF->clearBuf();
    _INSERT__BUF->eraseCell(Coords::max_y - 1, 0);
};

void CommandStateBackspaceHandler::modifyCurrentlyProcessedBuffer()
{
    _COMMAND__BUF->eraseCell(Coords::curr_y, Coords::curr_x - 1);
    Coords::decX();
};

void CommandStateBackspaceHandler::use()
{
    if (Coords::curr_x - 1 == 0)
    {
        CommandStateBackspaceHandler::cleanBuffers();
        EditorStatus::setCurrStatus(EditorStatus::getCheckpoint());

        Coords::setY(PreviouslyPressedHistory::y), Coords::setX(PreviouslyPressedHistory::x);
        CommonStateHelper::setKeyHandled(K_BACKSPACE);
    }
    else
    {
        CommandStateBackspaceHandler::modifyCurrentlyProcessedBuffer();
        CommonStateHelper::setKeyHandled(K_BACKSPACE);
    }
};

CommandState::CommandState(int ch)
{
    *CommandStateStorage::g_ch = ch;
};

void CommandState::use()
{
    switch (*CommandStateStorage::g_ch)
    {
    case K_BACKSPACE:
    {
        CommandStateBackspaceHandler::use();
        break;
    }
    case K_ENTER:
    {
        CommandStateEnterHandler::use();
        break;
    };
    default:
        CommandStateDefaultHandler::use();
    }
};