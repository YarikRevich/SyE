#pragma once

#include "./entry/entry.hpp"
#include "./global/global.hpp"
#include "./input/input.hpp"
#include "./window/window.hpp"
#include "./widget/widget.hpp"
#include "./swap/swap.hpp"

/**
 * Represents global state manager.
*/
class State {
public:
    /**
     * Retrieves global state instance.
     *
     * @return retrieved global state instance.
     */
    static GlobalState* getGlobalState();

    /**
     * Retrieves input state instance.
     *
     * @return retrieved input state instance.
     */
    static InputState* getInputState();

    /**
     * Retrieves window state instance.
     *
     * @return retrieved window state instance.
     */
    static WindowState* getWindowState();

    /**
     * Retrieves entry state instance.
     *
     * @return retrieved entry state instance.
     */
    static EntryState* getEntryState();

    /**
     * Retrieves widget state instance.
     *
     * @return retrieved widget state instance.
     */
    static WidgetState* getWidgetState();

    /**
    * Retrieves swap state instance.
    *
    * @return retrieved swap state instance.
    */
    static SwapState* getSwapState();
private:
    /**
     * Represents global state instance.
    */
    static GlobalState* globalState;

    /**
     * Represents input state instance.
    */
    static InputState* inputState;

    /**
     * Represents window state instance.
    */
    static WindowState* windowState;

    /**
     * Represents entry state instance.
     */
    static EntryState* entryState;

    /**
     * Represents widget state instance.
     */
    static WidgetState* widgetState;

    /**
     * Represents swap state instance.
     */
    static SwapState* swapState;
};