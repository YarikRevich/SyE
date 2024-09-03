#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "../../../state/event/event.hpp"
#include "../../signal/common/common.hpp"
#include "../../../tools/window/window.hpp"

#include "ncurses.h"

/**
 * Represents event processing operation to be used by scheduler.
*/
class EventOperation : public SchedulerOperationWithSignal {
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