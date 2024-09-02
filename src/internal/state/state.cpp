#include "./state.hpp"

GlobalState* State::globalState = new GlobalState();
InputState* State::inputState = new InputState();
WindowState* State::windowState = new WindowState();
EntryState* State::entryState = new EntryState();
WidgetState* State::widgetState = new WidgetState();
SwapState* State::swapState = new SwapState();

GlobalState *State::getGlobalState() {
    return State::globalState;
}

InputState *State::getInputState() {
    return State::inputState;
}

WindowState *State::getWindowState() {
    return State::windowState;
}

EntryState *State::getEntryState() {
    return State::entryState;
}

WidgetState *State::getWidgetState() {
    return State::widgetState;
}

SwapState *State::getSwapState() {
    return State::swapState;
}