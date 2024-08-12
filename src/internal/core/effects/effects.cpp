#include "./effects.hpp"
#include "./window/window.hpp"

int Effects::process() {
    Spinner::startIndefiniteSpinner();

    WindowEffect* windowEffect = new WindowEffect();

    if (windowEffect->handleExec() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    };

    Spinner::stopIndefiniteSpinner();

    return EXIT_SUCCESS;
}