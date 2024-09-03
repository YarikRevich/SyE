#include "./widget.hpp"
#include "./time/time.hpp"

std::vector<WidgetProcessingOperationWithSignal*> WidgetOperation::callbacks;

WidgetOperation::WidgetOperation() {
    callbacks.push_back(new TimeWidget());
}

int WidgetOperation::getPriority() {
    return SCHEDULER_PRIORITY_4;
};

int WidgetOperation::handleExec() {
    for (auto callback: WidgetOperation::callbacks) {
        if (callback->handleExec() != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        };
    }

    return EXIT_SUCCESS;
}

int WidgetOperation::handleExit() {
    for (auto callback: WidgetOperation::callbacks) {
        if (callback->handleExit() != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        };
    }

    return EXIT_SUCCESS;
}