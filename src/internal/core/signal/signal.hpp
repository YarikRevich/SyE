#pragma once

#include "./common/common.hpp"
#include "../../logger/logger.hpp"

#include <csignal>
#include <cstdlib>
#include <vector>

/**
 * Represents global signal manager.
*/
class Signal {
public:
    /**
     * Initializes signal manager.
    */
    Signal();

    /**
     * Adds signal handler to the callback storage.
     *
     * @param value - handler to be registered.
    */
    void registerHandler(SignalOperation* value);

    /**
     * Emits sigterm exit signal.
     */
    static void emitExit();

    /**
     * Gathers all the exit handlers and manages graceful exit.
    */
    static void handleExit();

    /**
     * Gathers all the exit handlers and manages graceful exit.
     * 
     * @param signal - represents received signal.
    */
    static void handleExit(int signal);

    /**
     * Manages application window resize.
     *
     * @param signal - represents received signal.
    */
    static void handleResize(int signal);
private:
    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<SignalOperation*> callbacks;
};