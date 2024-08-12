#pragma once

#include <thread>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <chrono>

#include "../../signal/signal.hpp"

/**
 * Responsible for threads allocation and their management.
*/
class Scheduler : public Signal::Operation {
public:
    /**
     * Adds new operation to the storage
     *
     * @param operation - given operation to be saved.
     */
    static void addHandler(Operation* operation);

    /**
     * Starts all the persisted scheduled operations and waits till all of them are completed.
     *
     * @return result of the scheduler execution.
     */
    static int process();

    /**
     * Handles application exit signal.
    */
    void handleExit() override;
private:
    /**
     * Starts scheduled operation with delayed pipeline calls.
     */
    static void handleExecRaw();

    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<Operation*> callbacks;

    /**
     * Represents switch used to block scheduler exit.
     */
    static std::atomic<bool> blockExit;
};