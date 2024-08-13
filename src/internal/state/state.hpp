#pragma once

#include "../core/signal/signal.hpp"
#include "../core/effects/effects.hpp"
#include "../core/scheduler/scheduler.hpp"

#include "ncurses.h"

/**
 * Represents global state manager.
*/
class State {
public:
    /**
     * Retrieves signal instance.
     *
     * @return retrieved signal instance.
     */
    static Signal* getSignal();

    /**
     * Sets signal instance.
     *
     * @param value - signal instance to be set .
     */
    static void setSignal(Signal* value);

    /**
     * Retrieves effects instance.
     *
     * @return retrieved effects instance.
     */
    static Effects* getEffects();

    /**
     * Sets effects instance.
     *
     * @param value - effects instance to be set .
     */
    static void setEffects(Effects* value);

    /**
     * Retrieves scheduler instance.
     *
     * @return retrieved scheduler instance.
     */
    static Scheduler* getScheduler();

    /**
     * Sets scheduler instance.
     *
     * @param value - scheduler instance to be set .
     */
    static void setScheduler(Scheduler* value);

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
    /**
     * Represents instance of signal.
     */
    static Signal* signal;

    /**
     * Represents instance of effects.
     */
    static Effects* effects;

    /**
     * Represents instance of scheduler.
     */
    static Scheduler* scheduler;

    /**
     * Represents terminal instance.
    */
    static WINDOW* window;
};