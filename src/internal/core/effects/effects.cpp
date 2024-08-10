#include "./effects.hpp"
#include "./init/init.hpp"

int Effects::process() {
    Spinner::startIndefiniteSpinner();

    if (Init::process() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    };

    Spinner::stopIndefiniteSpinner();

    return EXIT_SUCCESS;
}