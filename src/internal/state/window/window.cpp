#include "./window.hpp"

WINDOW *WindowState::getWindow() {
    return this->window;
}

void WindowState::setWindow(WINDOW *value) {
    this->window = value;
}
