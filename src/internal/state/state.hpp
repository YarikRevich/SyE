#pragma once

#include "../core/signal/signal.hpp"
#include "../core/effects/effects.hpp"
#include "../core/scheduler/scheduler.hpp"
#include "./file/file.hpp"
#include "./input/input.hpp"
#include "./window/window.hpp"

/**
 * Represents global state manager.
*/
class State {
public:
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
     * Retrieves input state instance.
     *
     * @return retrieved input state instance.
     */
    static InputState* getInputState();

    /**
     * Retrieves window state instance.
     *
     * @return retrieved window state instance.
     */
    static WindowState* getWindowState();

    /**
     * Retrieves file state instance.
     *
     * @return retrieved file state instance.
     */
    static FileState* getFileState();
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
     * Represents input state instance.
    */
    static InputState* inputState;

    /**
     * Represents window state instance.
    */
    static WindowState* windowState;

    /**
     * Represents file state instance.
     */
    static FileState* fileState;
};