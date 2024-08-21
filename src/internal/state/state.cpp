#include "./state.hpp"

Signal* State::signal = NULL;
Effects* State::effects = NULL;
Scheduler* State::scheduler = NULL;

InputState* State::inputState = new InputState();
WindowState* State::windowState = new WindowState();
FileState* State::fileState = new FileState();

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

FileState *State::getFileState() {
    return State::fileState;
}