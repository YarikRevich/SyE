#include "./state.hpp"

GlobalState* State::globalState = new GlobalState();
EventState* State::eventState = new EventState();
InputState* State::inputState = new InputState();
WindowState* State::windowState = new WindowState();
EntryState* State::entryState = new EntryState();
WidgetState* State::widgetState = new WidgetState();
SwapState* State::swapState = new SwapState();

GlobalState *State::getGlobalState() {
    return State::globalState;
}

EventState *State::getEventState() {
    return State::eventState;
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