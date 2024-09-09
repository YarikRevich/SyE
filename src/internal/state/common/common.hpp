#pragma once

/**
* Represents window position.
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