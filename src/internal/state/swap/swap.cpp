#include "./swap.hpp"

bool SwapState::getPreviousPresent() {
    return previousPresent;
}

void SwapState::setPreviousPresent(bool value) {
    this->previousPresent = value;
}