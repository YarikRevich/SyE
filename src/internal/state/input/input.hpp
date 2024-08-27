#pragma once

#include <vector>

/**
 * Represents input state holder.
 */
class InputState {
public:
    /**
     * Represents all the available input modes.
     */
    enum Mode {
        /**
         * Represents insert mode, when user can write anything.
         */
        INSERT,

        /**
         * Represents command mode, when all user input is considered as one command.
         */
        COMMAND,

        /**
         * Represents view mode, when user can only view file content, not modifying it.
         */
        VIEW,
    };

    /**
     * Represents input symbol metadata.
     */
    class Symbol {
    public:
        /**
         * Retrieves raw symbol value.
         *
         * @return retrieved raw symbol value.
         */
        wint_t getValue();

        /**
         * Sets raw symbol value.
         *
         * @param value - given raw symbol value to be set.
         */
        void setValue(wint_t value);
    private:


        /**
         * Represents raw symbol value.
         */
        wint_t value;
    };

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

    /**
     * Retrieves current editor mode.
     *
     * @return retrieved current editor mode.
     */
    Mode getCurrentMode();

    /**
     * Sets current editor mode.
     *
     * @param value - current editor mode.
     */
    void setCurrentMode(Mode value);
private:
    /**
     * Represents all the
     */
    std::vector<Symbol*> symbols;

    /**
     * Represents current cursor position.
     */
    Position* currentPosition;

    /**
     * Represents current editor mode.
     */
    Mode currentMode;
};

// TODO: create position to symbol map for all the recorded symbols.