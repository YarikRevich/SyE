#include "./init.hpp"

int Init::process() {
    Signal::init();

    Scheduler* scheduler = new Scheduler();

    State::setScheduler(scheduler);

    Signal::addHandler(scheduler::handleExit);

    Scheduler::addHandler(new Input());
    Scheduler::addHandler(new Render());

    return EXIT_SUCCESS;
}