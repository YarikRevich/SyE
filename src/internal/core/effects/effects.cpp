#include "./effects.hpp"
#include "./window/window.hpp"

Effects::Effects() {
    callbacks.push_back(new WindowEffect());
}

int Effects::process() {
    Spinner::startIndefiniteSpinner();

    for(auto callback : Effects::callbacks) {
        if (callback->handleExec() != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    }

    Spinner::stopIndefiniteSpinner();

    return EXIT_SUCCESS;
}

int Effects::handleExit() {
    for(auto callback : Effects::callbacks) {
        if (callback->handleExit() != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        };
    }

    return EXIT_SUCCESS;
}