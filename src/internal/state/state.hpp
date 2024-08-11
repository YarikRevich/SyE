#pragma once

#include "../core/scheduler/scheduler.hpp"

/**
 * Represents global state manager.
*/
class State {
public:
    /**
     * Retrieves scheduler instance.
     *
     * @return retrieved scheduler instance.
     */
    static Scheduler* getScheduler();

    /**
     * Sets scheduler instance.
     *
     * @param scheduler - scheduler instance to be set .
     */
    static void setScheduler(Scheduler* scheduler);

private:

    /**
     * Represents instance of scheduler.
     */
    Scheduler* scheduler;
};