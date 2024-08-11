#pragma once

#include "../../tools/spinner/spinner.hpp"

#include <iostream>

/**
 * Represents effects entrypoint used during.
*/
class Effects {
public:
    /**
     * Represents effect operation interface.
     */
    class Operation {
    public:
        /**
         * Handles operation execution.
         */
        virtual void handleExec() = 0;
    };

    /**
     * Performs processing of all the effects.
     *
     * @return result of the effects execution.
     */
    static int process();
};