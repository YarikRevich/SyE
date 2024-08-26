#include "./time.hpp"

int TimeWidget::handleExec() {
    if (ConfigHelper::isWidgetActive(WIDGET_TIME)) {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);

        std::ostringstream oss;
        oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");

        State::getWidgetState()->getTimeWidget()->setTime(oss.str());
    }

    return EXIT_SUCCESS;
}

int TimeWidget::handleExit() {
    return EXIT_SUCCESS;
}