#include "render.hpp"

Render::Render() {
    initscr();
	set_escdelay(FALSE);
	noecho();
	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);

    int x, y;
    getmaxyx(stdscr, y, x);

    this->window = newwin(x, y, 0, 0);
}

void Render::handleExec() {
//    wprintw(this->window, "first");
//
//    box(this->window, '*', '*');
//    touchwin(this->window);
//    wrefresh(this->window);

    while (true) {
        std::string symbol = Window::getSymbolAsChar(window);

        wprintw(this->window, symbol.c_str());
    }
}

void Render::handleExit() {
    endwin();
    delwin(this->window);
}
    
void Render::renderWindow() {
};

void Render::cleanContent() {

};

// Perform listening to new symbols and rendering in different threads. All the classes should implement 
//
// Define special type of symbols, that will bypass swap file modification.