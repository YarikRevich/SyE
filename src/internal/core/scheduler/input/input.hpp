#pragma once

#include "ncurses.h"

#include "../common/common.hpp"
#include "../../../signal/common/common.hpp"
#include "../../../tools/window/window.hpp"
#include "../../../state/state.hpp"

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