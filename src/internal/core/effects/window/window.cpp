#include "./window.hpp"

int WindowEffect::handleExec() {
    initscr();
    set_escdelay(FALSE);
    noecho();
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);

    int x, y;
    getmaxyx(stdscr, y, x);

    auto window = newwin(x, y, 0, 0);

    State::setWindow(window);

    return EXIT_SUCCESS;
}

int WindowEffect::handleExit() {
    endwin();
    delwin(State::getWindow());

    return EXIT_SUCCESS;
}

//int Init::process() {
//    Signal::init();
//
//    Scheduler* scheduler = new Scheduler();
//
//    State::setScheduler(scheduler);
//
//    Signal::addHandler(scheduler::handleExit);
//
//    Scheduler::addHandler(new Input());
//    Scheduler::addHandler(new Render());
//
//    return EXIT_SUCCESS;
//}