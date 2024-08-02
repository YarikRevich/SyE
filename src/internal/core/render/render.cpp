#include "render.hpp"
#include <iostream>

WINDOW* Render::window = NULL;

void Render::init() {
    Signal::addHandler(Render::handleExit);

    initscr();
	set_escdelay(FALSE);
	noecho();
	scrollok(stdscr, TRUE);
	keypad(stdscr, TRUE);

    int x, y;
    getmaxyx(stdscr, y, x);

    Render::window = newwin(x, y, 0, 0);
}
    
void Render::renderWindow() {
    wprintw(Render::window, "first");

    wgetch(Render::window);
};

void Render::cleanContent() {

};

void Render::handleExit() {
    endwin();
}