#include "./window.hpp"

Window::Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Window::Point::getX() {
    return this->x;
}

int Window::Point::getY() {
    return this->y;
}

Window::Point* Window::getCurrentWindowSize() {
    struct winsize size;

    if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0) {
        return NULL;
    }

    return new Window::Point(size.ws_col, size.ws_row);
}