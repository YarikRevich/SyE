#pragma once

#include "../../core/signal/signal.hpp"
#include "../../core/effects/effects.hpp"
#include "../../core/scheduler/scheduler.hpp"

#include <queue>

/**
 * Represents global state holder.
 */
class GlobalState {
public:
    /**
     * Sets signal instance.
     *
     * @param value - signal instance to be set .
     */
    void setSignal(Signal* value);

    /**
     * Retrieves effects instance.
     *
     * @return retrieved effects instance.
     */
    Effects* getEffects();

    /**
     * Sets effects instance.
     *
     * @param value - effects instance to be set .
     */
    void setEffects(Effects* value);

    /**
     * Retrieves scheduler instance.
     *
     * @return retrieved scheduler instance.
     */
    Scheduler* getScheduler();

    /**
     * Sets scheduler instance.
     *
     * @param value - scheduler instance to be set .
     */
    void setScheduler(Scheduler* value);
private:
    /**
     * Represents instance of signal.
     */
    Signal* signal;

    /**
     * Represents instance of effects.
     */
    Effects* effects;

    /**
     * Represents instance of scheduler.
     */
    Scheduler* scheduler;
};