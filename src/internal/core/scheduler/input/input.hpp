#pragma once

#include "./common/common.hpp"
#include "../common/common.hpp"
#include "../../../state/state.hpp"
#include "./mode/common/common.hpp"
#include "../../signal/common/common.hpp"

#include "ncurses.h"
#include <cwchar>

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class InputOperation : public SchedulerOperationWithSignal {
public:
    /**
     * Performs input operation initialization.
     */
    InputOperation();

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
private:
    /**
     * Represents collection of registered input modes.
    */
    static std::vector<InputMode*> modes;
};