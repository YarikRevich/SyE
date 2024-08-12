#include "./widget.hpp"

int WidgetOperation::handleExec() {
    std::string symbol = Window::getSymbolAsChar(State::getWindow());

    wprintw(State::getWindow(), symbol.c_str());

    return EXIT_SUCCESS;
}

int WidgetOperation::handleExit() {
    return EXIT_SUCCESS;
}