#include "signal.hpp"

std::vector<void (*)()> Signal::callbacks;

void Signal::init() {
    std::atexit(handleExit);
    signal(SIGINT, handleExit);
}

void Signal::addHandler(void (*callback)()) {
    callbacks.push_back(callback);
}

void Signal::handleExit() {
    for (void (*value)() : callbacks) {
        value();
    }
}

void Signal::handleExit(int signal) {
    for (void (*value)() : callbacks) {
        value();
    }

    exit(1);
}