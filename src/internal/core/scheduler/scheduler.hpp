#pragma once

#include <thread>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <chrono>

#include "./common/common.hpp"
#include "./render/render.hpp"
#include "./input/input.hpp"
#include "./widget/widget.hpp"
#include "../../signal/signal.hpp"
#include "../../signal/common/common.hpp"

/**
 * Responsible for threads allocation and their management.
*/
class Scheduler : public SignalOperation {
public:
    /**
     * Performs scheduler initialization.
     */
    static void init();

    /**
     * Starts all the persisted scheduled operations and waits till all of them are completed.
     *
     * @return result of the scheduler execution.
     */
    static int process();

    /**
     * @see SignalOperation
    */
    int handleExit() override;
private:
    /**
     * Starts scheduled operation with delayed pipeline calls.
     */
    static void handleExecRaw();

    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<SchedulerOperationWithSignal*> callbacks;

    /**
     * Represents switch used to block scheduler exit.
     */
    static std::atomic<bool> blockExit;
};