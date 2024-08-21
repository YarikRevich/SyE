#include "window.hpp"

wchar_t* Window::getSymbolAsChar(WINDOW* window) {
    auto ch = (wchar_t)wgetch(window);

    return &ch;
}