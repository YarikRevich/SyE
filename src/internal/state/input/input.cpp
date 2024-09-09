#include "./input.hpp"

InputState::Symbol::Symbol(wint_t value) : value{value} {
}

wint_t InputState::Symbol::getValue() {
    return this->value;
}

void InputState::Symbol::setValue(wint_t value) {
    this->value = value;
}

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

InputState::Position *InputState::getCurrentCursorPosition() {
    return this->currentPosition;
}

void InputState::setCurrentCursorPosition(InputState::Position *value) {
    this->currentPosition = value;
}

InputState::Mode InputState::getCurrentMode() {
    return this->currentMode;
}

void InputState::setCurrentMode(InputState::Mode value) {
    this->currentMode = value;
}

std::vector<InputState::Symbol*>* InputState::getGeneralSymbolsBuffer() {
    return &this->generalSymbolsBuffer;
}