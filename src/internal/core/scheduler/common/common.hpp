#pragma once

#include "../../signal/common/common.hpp"

/**
* Represents scheduler operation interface.
*/
class SchedulerOperation {
public:
    /**
     * Returns óperation priority.
     *
     * @return retrieved operation priority.
     */
    virtual int getPriority() = 0;

    /**
     * Handles operation execution.
     *
     * @return result of the operation execution.
     */
    virtual int handleExec() = 0;
};

/**
* Represents combination of scheduler operation and signal operation interfaces.
*/
class SchedulerOperationWithSignal : public SchedulerOperation, public SignalOperation {};