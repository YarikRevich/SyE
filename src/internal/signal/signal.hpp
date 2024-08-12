#pragma once

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