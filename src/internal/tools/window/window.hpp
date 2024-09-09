#pragma once

#include <sys/ioctl.h>
#include <cstdio>
#include <unistd.h>

#include "../../state/window/window.hpp"

/**
 * Represents window related helpers.
 */
class Window {
public:
    /**
     * Retrieves current terminal window size.
     *
     * @return retrieved current terminal window size.
    */
    static Point* getCurrentWindowSize();

    /**
     * Calculates window max symbol amount.
     *
     * @param value - current window size.
     * @return calculated window max symbol amount.
     */
    static int getWindowMaxSymbolAmount(Point* value);
};