#include "signal.hpp"
#include "../../state/state.hpp"
#include "../../state/event/event.hpp"

#include "ncurses.h"

std::vector<SignalOperation*> Signal::callbacks;

Signal::Signal() {
    std::atexit(handleExit);
    signal(SIGINT, handleExit);
    signal(SIGWINCH, handleResize);
}

void Signal::registerHandler(SignalOperation* value) {
    callbacks.push_back(value);
}

void Signal::emitExit() {
    raise(SIGTERM);
}

void Signal::handleExit() {
    for (const auto& callback : callbacks) {
        if (callback->handleExit() != EXIT_SUCCESS) {
            return;
        }
    }
}

void Signal::handleExit(int signal) {
    for (const auto& callback : callbacks) {
        if (callback->handleExit() != EXIT_SUCCESS) {
            return;
        }
    }

    exit(1);
}

void Signal::handleResize(int signal) {
    State::getEventState()->addEvent(EventState::Type::RESIZE);
}