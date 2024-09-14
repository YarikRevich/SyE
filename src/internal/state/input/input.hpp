#pragma once

#include "../common/common.hpp"

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
         * Sets provided symbol value.
         *
         * @param value - given symbol value.
         */
        explicit Symbol(wint_t value);

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
     * Represents input buffer implementation.
     */
    class Buffer {
    public:

    private:
    };

    /**
     * Retrieves latest provided symbol.
     *
     * @return retrieved latest provided symbol.
     */
    Symbol* getLatestSymbol();

    /**
     * Sets latest provided symbol.
     *
     * @param value - latest provided symbol.
     */
    void setLatestSymbol(Symbol* value);

    /**
     * Retrieves current cursor shift.
     *
     * @return retrieved current cursor shift.
     */
    int getCurrentCursorShift();

    /**
     * Sets current cursor shift.
     *
     * @param value - current cursor shift.
     */
    void setCurrentCursorShift(int value);

    /**
     * Retrieves current cursor position.
     *
     * @return retrieved current cursor position.
     */
    Point* getCurrentCursorPosition();

    /**
     * Sets current cursor position.
     *
     * @param value - current cursor position.
     */
    void setCurrentCursorPosition(Point* value);

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

    /**
     * Retrieves general symbols buffer.
     *
     * @return retrieved general symbols buffer.
     */
    std::vector<Symbol*>* getGeneralSymbolsBuffer();

    /**
     * Retrieves command symbols buffer.
     *
     * @return retrieved command symbols buffer.
     */
    std::vector<Symbol*>* getCommandSymbolsBuffer();
private:
    /**
     * Represents latest provided symbol.
     */
    Symbol* latestSymbol;

    /**
     * Represents general symbols buffer.
     */
    std::vector<Symbol*> generalSymbolsBuffer;

    /**
     * Represents command symbols buffer.
     */
    std::vector<Symbol*> commandSymbolsBuffer;

    /**
     * Represents current cursor position.
     */
    Point* currentCursorPosition;

    /**
     * Represents current cursor shift.
     */
    int currentCursorShift;

    /**
     * Represents current editor mode.
     */
    Mode currentMode = Mode::VIEW;
};

// TODO: create position to symbol map for all the recorded symbols.