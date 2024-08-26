#include "./widget.hpp"

WidgetState::WidgetState() {
    this->timeWidgetState = new TimeWidgetState();
}

TimeWidgetState *WidgetState::getTimeWidget() {
    return this->timeWidgetState;
}