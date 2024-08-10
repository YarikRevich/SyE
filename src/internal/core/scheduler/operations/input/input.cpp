#include "input.hpp"

Input::Input() {
}

void Input::handleExec() {
}

void Input::handleExit() {
   std::string symbol = Window::getSymbolAsChar(window);

   wprintw(this->window, symbol.c_str());
}