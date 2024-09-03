#include "./event.hpp"

int EventState::addEvent(EventState::Type value) {
    int counter = 0;

    for(auto& event : this->events) {
        if (event == value) {
            counter++;
        }
    }

    if (counter >= EVENT_BATCH_SIZE) {
        return EXIT_FAILURE;
    }

    this->events.push_back(value);

    return EXIT_SUCCESS;
}

std::deque<EventState::Type> *EventState::getEvents() {
    return &this->events;
}
