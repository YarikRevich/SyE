#include "./insert.hpp"

int InputInsert::getType() {
    return InputState::Mode::INSERT;
}

int InputInsert::handleExec() {
    auto window = State::getWindowState()->getWindow();
    auto symbol = State::getInputState()->getLatestSymbol();
    auto currentWindowSize = State::getWindowState()->getCurrentWindowSize();
    auto currentCursorPosition = State::getInputState()->getCurrentCursorPosition();

    switch (symbol->getValue()) {
        case BACKSPACE_KEY:
            break;
        case MOVE_UP_KEY:
            mvwinch(window, 0, 0) == '0';

//                        State::getInputState()->setCurrentCursorPosition()

            break;
        case MOVE_DOWN_KEY:

            break;
        case MOVE_LEFT_KEY:

            break;
        case MOVE_RIGHT_KEY:

            break;
    }

    return EXIT_SUCCESS;
}