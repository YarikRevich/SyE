#pragma once

#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "../../signal/common/common.hpp"
#include "../../../state/global/global.hpp"
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
    int handleExec() override;

    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExit() override;
};