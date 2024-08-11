#include "./state.hpp"

Scheduler* State::getScheduler() {
    return this->scheduler;
}

void State::setScheduler(Scheduler *scheduler) {
    this->scheduler = scheduler;
}