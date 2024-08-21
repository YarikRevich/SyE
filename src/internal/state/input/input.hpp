#pragma once

#include <vector>

/**
 * Represents input state holder.
 */
class InputState {
public:
    class

    /**
     * Represents current cursor position.
     */
    class Position {
    public:
        /**
         * Retrieves current column position.
         *
         * @return retrieved current column position.
         */
        int getX();

        /**
         * Sets current column position.
         *
         * @param value - current column position.
         */
        void setX(int value);

        /**
         * Retrieves current line position.
         *
         * @return retrieved current line position.
         */
        int getY();

        /**
         * Sets current line position.
         *
         * @param value - current line position.
         */
        void setY(int value);
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
     * Retrieves current position.
     *
     * @return retrieved current position.
     */
    Position* getCurrentPosition();

    /**
     * Sets current cursor position.
     *
     * @param value - current cursor position.
     */
    void setCurrentPosition(Position* value);
private:
//    std::vector<wchar_t>

    /**
     * Represents current cursor position.
     */
    Position* currentPosition;
};