#include "./event.hpp"

int EventOperation::getPriority() {
    return SCHEDULER_PRIORITY_3;
};

int EventOperation::handleExec() {
    auto queue = State::getEventState()->getEvents();

    while (!queue->empty()) {
        auto event = queue->front();

        switch (event) {
            case EventState::Type::RESIZE:
                auto window = State::getWindowState()->getWindow();

                wclear(window);
                wrefresh(window);

                auto windowSize = Window::getCurrentWindowSize();

                if (windowSize != NULL) {
                    // calling this macro lots of times with a short delay can cause segmentation fault.
                    resize_term(windowSize->getY(), windowSize->getX());
                }

                break;
        }

        queue->pop_front();
    }

    return EXIT_SUCCESS;
}

int EventOperation::handleExit() {
    return EXIT_SUCCESS;
}