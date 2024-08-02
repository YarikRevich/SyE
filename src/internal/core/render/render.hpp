#pragma once

#include "ncurses.h"
#include "../../signal/signal.hpp"

/**
 * Represents screen rendering handler.
*/
class Render {
public:
    /**
     * Initializes screen rendering using ncurses pseudo-graphic library.
    */
    static void init();

    /**
     * Renders currently selected window entity without any additional content.
    */
    static void renderWindow();

    /**
     * Cleans all the previously rendered content from the selected window entity.
    */
    static void cleanContent();

    /**
     * 
    */
    static void scrollDown();

    /**
     * 
    */
    static void scrollUp();
private:
    /**
     * Handles application exit signal.
    */
    static void handleExit();

    /**
     * Represents currently selected window entity.
    */
    static WINDOW* window;
};