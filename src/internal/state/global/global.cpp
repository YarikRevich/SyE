#include "./global.hpp"

void GlobalState::setSignal(Signal *value) {
    this->signal = value;
}

Effects* GlobalState::getEffects() {
    return this->effects;
}

void GlobalState::setEffects(Effects *value) {
    this->effects = value;
}

Scheduler* GlobalState::getScheduler() {
    return this->scheduler;
}

void GlobalState::setScheduler(Scheduler* value) {
    this->scheduler = value;
}

std::queue<GlobalState::Event>* GlobalState::getEvents() {
    return &this->events;
}