#pragma once

#include "../core/scheduler/scheduler.hpp"

#include "ncurses.h"

/**
 * Represents global state manager.
*/
class State {
public:
//    /**
//     * Retrieves scheduler instance.
//     *
//     * @return retrieved scheduler instance.
//     */
//    static Scheduler* getScheduler();
//
//    /**
//     * Sets scheduler instance.
//     *
//     * @param scheduler - scheduler instance to be set .
//     */
//    static void setScheduler(Scheduler* scheduler);

    /**
     * Retrieves terminal window instance.
     *
     * @return retrieved terminal window instance.
     */
    static WINDOW* getWindow();

    /**
     * Sets terminal window instance.
     *
     * @param value - terminal window to be set.
     */
    static void setWindow(WINDOW* value);

private:
//    /**
//     * Represents instance of scheduler.
//     */
//    Scheduler* scheduler;

    /**
     * Represents terminal instance.
    */
    static WINDOW* window;
};