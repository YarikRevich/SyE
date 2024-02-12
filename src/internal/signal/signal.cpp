#include "signal.hpp"

std::vector<void (*)(int)> Signal::callbacks;

void Signal::init() {
    signal(SIGINT, handleExit);
}

void Signal::addHandler(void (*callback)(int)) {
    callbacks.push_back(callback);
}

void Signal::handleExit(int s) {
    for (void (*value)(int) : callbacks) {
        value(s);
    }

    exit(1);
}