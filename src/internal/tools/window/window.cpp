#include "./window.hpp"

Point* Window::getCurrentWindowSize() {
    struct winsize size;

    if (ioctl(0, TIOCGWINSZ, (char *) &size) < 0) {
        return NULL;
    }

    return new Point(size.ws_col, size.ws_row);
}

int Window::getWindowMaxSymbolAmount(Point *value) {
    return value->getY() * value->getX();
}
