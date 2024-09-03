#pragma once

#include "../common/common.hpp"
#include "../../signal/common/common.hpp"

#include "ncurses.h"
#include <iostream>

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class RenderOperation : public SchedulerOperationWithSignal {
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