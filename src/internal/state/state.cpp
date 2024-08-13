#include "./state.hpp"

Signal* State::signal = NULL;
Effects* State::effects = NULL;
Scheduler* State::scheduler = NULL;
WINDOW* State::window = NULL;

Signal* State::getSignal() {
    return State::signal;
}

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

WINDOW* State::getWindow() {
    return State::window;
}

void State::setWindow(WINDOW *value) {
    State::window = value;
}