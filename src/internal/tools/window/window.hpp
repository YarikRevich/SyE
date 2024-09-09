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
    static WindowState::Point* getCurrentWindowSize();
};