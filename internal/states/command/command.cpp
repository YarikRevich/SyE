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
    }
};

void CommandStateEnterHandler::cleanBuffers()
{
    _EFFECTS__BUF->clearBuf();
    _INSERT__BUF->eraseCell(Coords::max_y - 1, 0);
    _COMMAND__BUF->clearBuf();
};

void CommandStateEnterHandler::modifyState()
{
    EditorStatus::setCurrStatus(EditorStatus::getCheckpoint());
    CommonStateHelper::setKeyHandled(K_ENTER);
};

void CommandStateEnterHandler::use()
{

    Applicator::apply_command(_COMMAND__BUF->getBufAsString());
    CommandStateEnterHandler::cleanBuffers();

    _INSERT__BUF->setMovement(PreviouslyPressedHistory::y, PreviouslyPressedHistory::x);

    CommandStateEnterHandler::modifyState();
};

void CommandStateBackspaceHandler::cleanBuffers()
{
    _EFFECTS__BUF->clearBuf();
    _INSERT__BUF->eraseCell(Coords::curr_y, 0);
    _COMMAND__BUF->clearBuf();
};

void CommandStateBackspaceHandler::modifyCurrentlyProcessedBuffer()
{
    _COMMAND__BUF->setMovement(Coords::curr_y, Coords::curr_x - 1);
    _COMMAND__BUF->eraseCell(Coords::curr_y, Coords::curr_x - 1);
};

void CommandStateBackspaceHandler::setKeyHandledIgnoringInsBufForceMovement()
{
    CommonStateHelper::setKeyHandled(K_BACKSPACE);
    _INSERT__BUF->setIgnoreForcibleMove(true);
};

void CommandStateBackspaceHandler::use()
{
    if (Coords::curr_x - 1 == 0)
    {
        CommandStateBackspaceHandler::cleanBuffers();
        EditorStatus::setCurrStatus(EditorStatus::getCheckpoint());

        _INSERT__BUF->setMovement(PreviouslyPressedHistory::y, PreviouslyPressedHistory::x);
        CommandStateBackspaceHandler::setKeyHandledIgnoringInsBufForceMovement();
    }
    else
    {
        CommandStateBackspaceHandler::modifyCurrentlyProcessedBuffer();
        CommandStateBackspaceHandler::setKeyHandledIgnoringInsBufForceMovement();
    }
};

CommandState::CommandState(int ch)
{
    *CommandStateStorage::g_ch = ch;
};

void CommandState::use()
{
    _COMMAND__BUF->setIgnoreForcibleMove(true);

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