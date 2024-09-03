#include "./swap.hpp"

int SwapOperation::getPriority() {
    return SCHEDULER_PRIORITY_2;
};

int SwapOperation::handleExec() {
    return EXIT_SUCCESS;
}

int SwapOperation::handleExit() {
    return EXIT_SUCCESS;
}