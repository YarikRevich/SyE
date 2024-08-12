#pragma once

#include "ncurses.h"

#include "../common/common.hpp"
#include "../../../signal/common/common.hpp"
#include "../../../tools/window/window.hpp"
#include "../../../state/state.hpp"

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class WidgetOperation : public SchedulerOperation, SignalOperation {
public:
    /**
    * @see SchedulerOperation
    */
    int handleExec() override;

    /**
    * @see SignalOperation
    */
    int handleExit() override;
};