#include "signal.hpp"

std::vector<void (*)()> Signal::callbacks;

Signal::Signal() {
    std::atexit(handleExit);
    signal(SIGINT, handleExit);
}

void Signal::addHandler(void (*callback)()) {
    callbacks.push_back(callback);
}

void Signal::emitExit() {
    raise(SIGTERM);
}

void Signal::handleExit() {
    for (const auto& callback : callbacks) {
        callback();
    }
}

void Signal::handleExit(int signal) {
    for (const auto& callback : callbacks) {
        callback();
    }

    exit(1);
}