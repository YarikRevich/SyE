#include "./view.hpp"

int InputView::getType() {
    return InputState::Mode::VIEW;
}

int InputView::handleExec() {
    auto symbol = State::getInputState()->getLatestSymbol();

    if (symbol->getValue() == COMMAND_KEY) {
        State::getInputState()->setCurrentMode(InputState::Mode::COMMAND);

        // TODO: create separated buffer class for different types of buffers.
        // TODO: buffer needs to have an opportunity to have buffer window.
        // TODO: also needs to have metadata buffer separation.
//        State::getInputState()->getCommandSymbolsBuffer()
    }

    return EXIT_SUCCESS;
}