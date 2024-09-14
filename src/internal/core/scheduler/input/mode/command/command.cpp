#include "./command.hpp"

int InputCommand::getType() {
    return InputState::Mode::COMMAND;
}

int InputCommand::handleExec() {
    auto symbol = State::getInputState()->getLatestSymbol();
    auto currentWindowSize = State::getWindowState()->getCurrentWindowSize();

    switch (symbol->getValue()){
        case ENTER_KEY:


            break;
        case BACKSPACE_KEY:
            break;
        case INSERT_COMMAND:
            State::getInputState()->setCurrentMode(InputState::Mode::INSERT);

            break;
    }

    return EXIT_SUCCESS;
}