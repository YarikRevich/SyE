#pragma once

#include "../common/common.hpp"

#include <cstdlib>

/**
 * Represents buffer cleaning operation to be used by scheduler.
*/
class CleanerOperation : public SchedulerOperationWithSignal {
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