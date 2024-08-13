#include "signal.hpp"

std::vector<void (*)()> Signal::callbacks;

void Signal::init() {
    std::atexit(handleExit);
    signal(SIGINT, handleExit);
}

void Signal::registerHandler(void (*callback)()) {
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