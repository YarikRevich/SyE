#include "./input.hpp"

int InputState::Position::getX() {
    return this->x;
}

void InputState::Position::setX(int value) {
    this->x = value;
}

int InputState::Position::getY() {
    return this->y;
}

void InputState::Position::setY(int value) {
    this->y = value;
}

InputState::Position *InputState::getCurrentPosition() {
    return this->currentPosition;
}

void InputState::setCurrentPosition(InputState::Position *value) {
    this->currentPosition = value;
}
