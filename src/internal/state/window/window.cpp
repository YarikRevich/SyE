#include "./window.hpp"

WINDOW *WindowState::getWindow() {
    return this->window;
}

void WindowState::setWindow(WINDOW *value) {
    this->window = value;
}

WindowState::Point *WindowState::getCurrentWindowSize() {
    return this->currentWindowSize;
}

void WindowState::setCurrentWindowSize(WindowState::Point *value) {
    this->currentWindowSize = value;
}
