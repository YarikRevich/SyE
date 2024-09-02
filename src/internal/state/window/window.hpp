#pragma once

#include "ncurses.h"

/**
 * Represents window state holder.
 */
class WindowState {
public:
    /**
    * Retrieves terminal window instance.
    *
    * @return retrieved terminal window instance.
    */
    WINDOW* getWindow();

    /**
     * Sets terminal window instance.
     *
     * @param value - terminal window to be set.
     */
    void setWindow(WINDOW* value);
private:
    /**
     * Represents terminal instance.
    */
    WINDOW* window;
};

// TODO: create one more buffer(window chunk), which would be of size of the terminal window and will represent some
// TODO: part of the general file buffer.