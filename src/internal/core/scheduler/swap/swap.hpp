#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"

#include "ncurses.h"

/**
 * Represents swap operation to be used by scheduler.
*/
class SwapOperation : public SchedulerOperationWithSignal {
public:
    /**
     * @see SchedulerOperationWithSignal
     */
    int getPriority() override;

    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExec() override;

    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExit() override;
};