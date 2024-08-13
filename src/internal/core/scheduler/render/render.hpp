#pragma once

#include "../common/common.hpp"
#include "../../signal/common/common.hpp"

#include "ncurses.h"
#include <iostream>

/**
 * Represents screen rendering operation to be used by scheduler.
*/
class RenderOperation : public SchedulerOperationWithSignal {
public:
    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExec() override;

    /**
    * @see SchedulerOperationWithSignal
    */
    int handleExit() override;
private:
//    /**
//     * Renders currently selected window entity without any additional content.
//    */
//    void renderWindow();
//
//    /**
//     * Cleans all the previously rendered content from the selected window entity.
//    */
//    void cleanContent();
//
//    /**
//     *
//    */
//    void scrollDown();
//
//    /**
//     *
//    */
//    void scrollUp();
};