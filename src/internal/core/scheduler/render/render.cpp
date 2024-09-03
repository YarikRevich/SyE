#include "render.hpp"

int RenderOperation::getPriority() {
    return SCHEDULER_PRIORITY_2;
};

int RenderOperation::handleExec() {
////    wprintw(this->window, "first");
////
////    box(this->window, '*', '*');
////    touchwin(this->window);
////    wrefresh(this->window);
//
//    while (true) {
//        std::string symbol = Window::getSymbolAsChar(window);
//
//        wprintw(this->window, symbol.c_str());
//    }

    return EXIT_SUCCESS;
}

int RenderOperation::handleExit() {


    return EXIT_SUCCESS;
}
//
//void Render::renderWindow() {
//};
//
//void Render::cleanContent() {
//
//};

// Perform listening to new symbols and rendering in different threads. All the classes should implement 
//
// Define special type of symbols, that will bypass swap file modification.