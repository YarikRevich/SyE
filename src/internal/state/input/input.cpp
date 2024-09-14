#include "./input.hpp"

InputState::Symbol::Symbol(wint_t value) : value{value} {
}

wint_t InputState::Symbol::getValue() {
    return this->value;
}

void InputState::Symbol::setValue(wint_t value) {
    this->value = value;
}

InputState::Symbol* InputState::getLatestSymbol() {
    return this->latestSymbol;
}

void InputState::setLatestSymbol(InputState::Symbol* value) {
    this->latestSymbol = value;
}

int InputState::getCurrentCursorShift() {
    return this->currentCursorShift;
}

void InputState::setCurrentCursorShift(int value) {
    this->currentCursorShift = value;
}

Point *InputState::getCurrentCursorPosition() {
    return this->currentCursorPosition;
}

void InputState::setCurrentCursorPosition(Point *value) {
    this->currentCursorPosition = value;
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

std::vector<InputState::Symbol*>* InputState::getCommandSymbolsBuffer() {
    return &this->commandSymbolsBuffer;
}