#include "input.hpp"

Input::Input() {
}

void Input::handleExec() {
    std::string symbol = Window::getSymbolAsChar(window);

    wprintw(this->window, symbol.c_str());
}

void Input::handleExit() {
}