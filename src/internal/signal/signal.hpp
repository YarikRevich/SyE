#pragma once

#include <cstdlib>

#include <vector>

/**
 * Represents global signal manager.
*/
class Signal {
public:
    /**
     * Represents signal operation interface.
     */
    class Operation {
    public:
        /**
         * Handles application exit signal.
         */
        virtual void handleExit() = 0;
    };

    /**
     * Initializes signal manager.
    */
    static void init();

    /**
     * Adds signal handler to the callback storage.
    */
    static void addHandler(void (*)());

    /**
     * Gathers all the exit handlers and manages graceful exit.
    */
    static void handleExit();

    /**
     * Gathers all the exit handlers and manages graceful exit.
     * 
     * @param singal - represents received signal.
    */
    static void handleExit(int signal);
private:
    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<void (*)()> callbacks;
};