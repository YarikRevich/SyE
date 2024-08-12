#include "./state.hpp"

WINDOW* State::window = NULL;

//Scheduler* State::getScheduler() {
//    return this->scheduler;
//}
//
//void State::setScheduler(Scheduler *scheduler) {
//    this->scheduler = scheduler;
//}

WINDOW* State::getWindow() {
    return State::window;
}

void State::setWindow(WINDOW *value) {
    State::window = value;
}
