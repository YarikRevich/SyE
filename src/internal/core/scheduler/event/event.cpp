#include "./event.hpp"



int EventOperation::handleExec() {
    auto queue = State::getGlobalState()->getEvents();

    while (!queue->empty()) {
        auto event = queue->front();

        switch (event) {
            case GlobalState::RESIZE:
                auto window = State::getWindowState()->getWindow();

                wclear(window);

                wrefresh(window);

                auto windowSize = Window::getCurrentWindowSize();

                if (windowSize != NULL) {
                    resize_term(windowSize->getY(), windowSize->getX());
                }

                break;
        }

        queue->pop();
    }

    return EXIT_SUCCESS;
}

int EventOperation::handleExit() {
    return EXIT_SUCCESS;
}