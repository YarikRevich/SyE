#include "./init.hpp"

int Init::process() {
    Signal::init();

    Scheduler::init();
    Scheduler::addHandler(new Input());
    Scheduler::addHandler(new Render());

    return EXIT_SUCCESS;
}