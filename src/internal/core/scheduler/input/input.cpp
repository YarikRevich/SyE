#include "./input.hpp"

#include "./mode/command/command.hpp"
#include "./mode/insert/insert.hpp"
#include "./mode/view/view.hpp"

std::vector<InputMode*> InputOperation::modes;

InputOperation::InputOperation() {
    modes.push_back(new InputCommand());
    modes.push_back(new InputInsert());
    modes.push_back(new InputView());
};

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
        State::getInputState()->setLatestSymbol(new InputState::Symbol(symbol));

        for (auto mode : modes) {
            if (mode->getType() == currentMode) {
                if (mode->handleExec() != EXIT_SUCCESS) {
                    return EXIT_FAILURE;
                };
            }
        }
    }

    return EXIT_SUCCESS;
}

int InputOperation::handleExit() {
    return EXIT_SUCCESS;
}