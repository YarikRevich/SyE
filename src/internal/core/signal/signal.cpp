#include "signal.hpp"

std::vector<SignalOperation*> Signal::callbacks;

Signal::Signal() {
    std::atexit(handleExit);
    signal(SIGINT, handleExit);
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