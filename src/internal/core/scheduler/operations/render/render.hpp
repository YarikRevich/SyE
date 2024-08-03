#pragma once

#include "ncurses.h"

#include "../../../scheduler/scheduler.hpp"
#include "../../../../signal/signal.hpp"
#include "../../../../tools/window/window.hpp"

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class Render : public Scheduler::Operation {
public:
    /**
     * Initializes screen rendering using ncurses pseudo-graphic library.
    */
    Render();

    /**
    * @see Scheduler::Operation::handleExec
    */
    void handleExec() override;

    /**
    * @see Scheduler::Operation::handleExit
    */
    void handleExit() override;
private:
    /**
     * Represents currently selected window entity.
    */
    WINDOW* window;

    /**
     * Renders currently selected window entity without any additional content.
    */
    void renderWindow();

    /**
     * Cleans all the previously rendered content from the selected window entity.
    */
    void cleanContent();

    /**
     * 
    */
    void scrollDown();

    /**
     * 
    */
    void scrollUp();
};