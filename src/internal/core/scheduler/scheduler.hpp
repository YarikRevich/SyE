#pragma once

#include "./common/common.hpp"
#include "../signal/common/common.hpp"

#include <thread>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <chrono>

/**
 * Represents manager of scheduled internal processes.
*/
class Scheduler : public SignalOperation {
public:
    /**
     * Performs scheduler initialization.
     */
    Scheduler();

    /**
     * Starts all the persisted scheduled operations and waits till all of them are completed.
     *
     * @return result of the scheduler execution.
     */
    int process();

    /**
     * @see SignalOperation
    */
    int handleExit() override;
private:
    /**
     * Handles main thread pipeline execution.
     */
    static void handleExecMain();

    /**
     * Handles thread task execution.
     *
     * @param callback - given scheduler operation handler.
     */
    static void handleExecTask(SchedulerOperation* callback);

    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<SchedulerOperationWithSignal*> callbacks;

    /**
     * Represents switch used to block scheduler exit.
     */
    static std::atomic<bool> blockExit;
};