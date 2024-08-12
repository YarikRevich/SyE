#include "input.hpp"

int InputOperation::handleExec() {
    std::string symbol = Window::getSymbolAsChar(State::getWindow());

    wprintw(State::getWindow(), symbol.c_str());

    return EXIT_SUCCESS;
}

int InputOperation::handleExit() {
    return EXIT_SUCCESS;
}