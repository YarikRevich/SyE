#include "./loader.hpp"

int LoaderEffect::handleExec() {
    if (ConfigLoader::process() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    };

    if (ThemeLoader::process() != EXIT_SUCCESS) {
        return EXIT_FAILURE;
    };

    return EXIT_SUCCESS;
}

int LoaderEffect::handleExit() {
    return EXIT_SUCCESS;
}
