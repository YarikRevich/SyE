#include "./input.hpp"

int InputOperation::getPriority() {
    return SCHEDULER_PRIORITY_2;
};

int InputOperation::handleExec() {
    auto window = State::getWindowState()->getWindow();
    auto currentMode = State::getInputState()->getCurrentMode();

    wint_t symbol;

    wget_wch(window, &symbol);

    if (std::find(
            FORBIDDEN_SYMBOLS.begin(), FORBIDDEN_SYMBOLS.end(), symbol) == FORBIDDEN_SYMBOLS.end()) {
        Point* currentWindowSize;

        switch (currentMode) {
            case InputState::Mode::VIEW:
                currentWindowSize = State::getWindowState()->getCurrentWindowSize();

                wprintw(window, "x - %d; y - %d %d\n", currentWindowSize->getX(), currentWindowSize->getY(), State::getInputState()->getCurrentCursorShift());

                wrefresh(window);

                if (symbol == COMMAND_KEY) {
                    State::getInputState()->setCurrentMode(InputState::Mode::COMMAND);
                }

                break;
            case InputState::Mode::INSERT:
//                Point* currentWindowSize;
                Point* currentCursorPosition;

                switch (symbol) {
                    case MOVE_UP_KEY:
                        currentWindowSize = State::getWindowState()->getCurrentWindowSize();
                        currentCursorPosition = State::getInputState()->getCurrentCursorPosition();

//                        State::getInputState()->setCurrentCursorPosition()

                        break;
                    case MOVE_DOWN_KEY:
                        break;
                    case MOVE_LEFT_KEY:
                        break;
                    case MOVE_RIGHT_KEY:
                        break;
                }

                break;
            case InputState::Mode::COMMAND:
                currentWindowSize = State::getWindowState()->getCurrentWindowSize();

                break;
        }
    }

    return EXIT_SUCCESS;
}

int InputOperation::handleExit() {
    return EXIT_SUCCESS;
}