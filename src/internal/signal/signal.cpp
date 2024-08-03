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