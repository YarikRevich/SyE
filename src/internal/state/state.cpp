#include "./state.hpp"

Signal* State::signal = NULL;
Effects* State::effects = NULL;
Scheduler* State::scheduler = NULL;

InputState* State::inputState = new InputState();
WindowState* State::windowState = new WindowState();
EntryState* State::entryState = new EntryState();
WidgetState* State::widgetState = new WidgetState();
SwapState* State::swapState = new SwapState();

void State::setSignal(Signal *value) {
    State::signal = value;
}

Effects* State::getEffects() {
    return State::effects;
}

void State::setEffects(Effects *value) {
    State::effects = value;
}

Scheduler* State::getScheduler() {
    return State::scheduler;
}

void State::setScheduler(Scheduler* value) {
    State::scheduler = value;
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