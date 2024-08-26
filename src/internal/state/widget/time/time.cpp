#include "./time.hpp"

std::string TimeWidgetState::getTime() {
    return time;
}

void TimeWidgetState::setTime(std::string value) {
    this->time = value;
}