#pragma once

#include <thread>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>

#include "../../signal/signal.hpp"

/**
 * Responsible for threads allocation and their management.
*/
class Scheduler {
public:
    /**
     * Represents scheduler operation interface.
     */
    class Operation {
    public:
        /**
         * Handles operation execution.
         */
        virtual void handleExec() = 0;

        /**
         * Handles application exit signal.
         */
        virtual void handleExit() = 0;
    };

    /**
     * Initializes scheduler and registers all the operations.
    */
    static void init();

    /**
     * Adds new operation to the storage
     *
     * @param operation - given operation to be saved.
     */
    static void addHandler(Operation* operation);

    /**
     * Starts all the persisted scheduled operations and waits till all of them are completed.
     */
    static void handleExec();
private:
    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<Operation*> callbacks;

    /**
     * Represents switch used to block scheduler exit.
     */
    static std::atomic<bool> blockExit;

    /**
     * Handles application exit signal.
    */
    static void handleExit();
};