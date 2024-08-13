#include "../internal/logger/logger.hpp"
#include "../internal/command/handler/handler.hpp"

/**
 * Performs initialization of basic components.
 */
void init() {
    auto signal = new Signal();

    auto effects = new Effects();
    signal->registerHandler(effects);

    auto scheduler = new Scheduler();
    signal->registerHandler(scheduler);

    State::setSignal(signal);
    State::setEffects(effects);
    State::setScheduler(scheduler);
}

/**
 * Entrypoint, which propagates logic to the handler.
*/
int main(int argc, char **argv) {
    init();

    auto* handler = new Handler(argc, argv);

    if (handler->run() != EXIT_SUCCESS) {
        if (Logger::isErrorExist()) {
            std::cout << Logger::getError() << std::endl;
        }
    }
}