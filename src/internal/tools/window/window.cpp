#include "window.hpp"

std::string Window::getSymbolAsChar(WINDOW* window) {
    char ch = (char)wgetch(window);

    return std::string{1, ch};
}