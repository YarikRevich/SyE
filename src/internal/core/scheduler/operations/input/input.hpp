#pragma once

#include "ncurses.h"

#include "../../../scheduler/scheduler.hpp"
#include "../../../../signal/signal.hpp"
#include "../../../../tools/window/window.hpp"

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class Input : public Scheduler::Operation {
public:
    /**
     * Initializes screen rendering using ncurses pseudo-graphic library.
    */
    Input();

    /**
    * @see Scheduler::Operation::handleExec
    */
    void handleExec() override;

    /**
    * @see Scheduler::Operation::handleExit
    */
    void handleExit() override;
private:
};