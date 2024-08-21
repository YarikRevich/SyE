#pragma once

#include <string>
#include <thread>

#include "ncurses.h"

/**
 * Represents terminal bash-like spinner.
 */
class Window {
public:
    /**
     * Start thread worker to run the indefinite command line spinner.
     *
     * @param window - given active application window.
     * @return retrieved symbol as char.
    */
    static wchar_t* getSymbolAsChar(WINDOW* window);
};