#include "./window.hpp"

WINDOW *WindowState::getWindow() {
    return this->window;
}

void WindowState::setWindow(WINDOW *value) {
    this->window = value;
}

Point *WindowState::getCurrentWindowSize() {
    return this->currentWindowSize;
}

void WindowState::setCurrentWindowSize(Point *value) {
    this->currentWindowSize = value;
}
