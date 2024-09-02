#include "./effects.hpp"
#include "./swap/swap.hpp"
#include "./input/input.hpp"
#include "./loader/loader.hpp"
#include "./window/window.hpp"
#include "./content/content.hpp"

Effects::Effects() {
    callbacks.push_back(new InputEffect());
    callbacks.push_back(new LoaderEffect());
    callbacks.push_back(new ContentEffect());
    callbacks.push_back(new WindowEffect());
    callbacks.push_back(new SwapEffect());
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