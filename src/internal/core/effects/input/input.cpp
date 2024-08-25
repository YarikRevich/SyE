#include "./input.hpp"

#include <iostream>

int InputEffect::handleExec() {
    auto inputFile = State::getEntryState()->getInputFile();

    if (IOHelper::getFileExists(inputFile)) {
        State::getEntryState()->setInputFileContentHash(IOHelper::getFileContentHash(inputFile));
    }

    State::getEntryState()->setInputFileExtension(IOHelper::getFileExtension(inputFile));

    return EXIT_SUCCESS;
}

int InputEffect::handleExit() {

    return EXIT_SUCCESS;
}