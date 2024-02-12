#pragma once

#include <vector>

/**
 * Represents global signal manager.
*/
class Signal {
public:
    /**
     * Initializes signal manager.
    */
    static void init();

    /**
     * Adds signal handler to the callback storage.
    */
    static void addHandler(void (*)(int));

    /**
     * Gathers all the exit handlers and manages graceful exit.
    */
    static void handleExit(int s);

private:
    /**
     * Represents collection of registered callbacks.
    */
    static std::vector<void (*)(int)> callbacks;
};