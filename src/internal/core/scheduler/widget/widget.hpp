#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"

#include "ncurses.h"

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class WidgetOperation : public SchedulerOperationWithSignal {
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