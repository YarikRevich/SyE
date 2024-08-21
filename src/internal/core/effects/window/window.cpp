#include "./window.hpp"

int WindowEffect::handleExec() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    initscr();
    cbreak();
    set_escdelay(FALSE);
    start_color();
    noecho();

    int x, y;
    getmaxyx(stdscr, y, x);

    auto window = newwin(y, x, 0, 0);

    scrollok(window, TRUE);
    keypad(window, TRUE);

    State::getWindowState()->setWindow(window);

    return EXIT_SUCCESS;
}

int WindowEffect::handleExit() {
    endwin();
    delwin(State::getWindowState()->getWindow());

    return EXIT_SUCCESS;
}