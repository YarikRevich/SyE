#include "./cleaner.hpp"

int CleanerOperation::getPriority() {
    return SCHEDULER_PRIORITY_5;
};

int CleanerOperation::handleExec() {
    return EXIT_SUCCESS;
}

int CleanerOperation::handleExit() {
    return EXIT_SUCCESS;
}