#pragma once

#include "../common/common.hpp"
#include "../../signal/common/common.hpp"
#include "../../../state/state.hpp"
#include "../../../tools/window/window.hpp"

#include "ncurses.h"

/**
 * Represents all the forbidden symbols.
 */
const wchar_t FORBIDDEN_SYMBOLS[] = { 401 };

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class InputOperation : public SchedulerOperationWithSignal {
public:
    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExec() override;

    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExit() override;
};