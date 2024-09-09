#pragma once

#include "ncurses.h"

/**
 * Represents window state holder.
 */
class WindowState {
public:
    /**
     * Represents immutable position.
     */
    class Point {
    public:
        /**
         * Sets provided position values.
         *
         * @param x - given column position value.
         * @param y - given row position value.
         */
        Point(int x, int y);

        /**
         * Retrieves current column position.
         *
         * @return retrieved current column position.
         */
        int getX();

        /**
         * Retrieves current line position.
         *
         * @return retrieved current line position.
         */
        int getY();
    private:
        /**
         * Represents current column position.
         */
        int x;

        /**
         * Represents current line position.
         */
        int y;
    };

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

    /**
     * Retrieves current window size.
     *
     * @return retrieved current window size.
     */
    Point* getCurrentWindowSize();

    /**
     * Sets current window size;
     *
     * @param value - given current window size.
     */
    void setCurrentWindowSize(Point* value);
private:
    /**
     * Represents terminal instance.
    */
    WINDOW* window;

    /**
     * Represents current window size.
     */
    Point* currentWindowSize;
};

// TODO: create one more buffer(window chunk), which would be of size of the terminal window and will represent some
// TODO: part of the general file buffer.