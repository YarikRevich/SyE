#include "scheduler.hpp"

std::vector<SchedulerOperationWithSignal*> Scheduler::callbacks;

std::atomic<bool> Scheduler::blockExit = false;

Scheduler::Scheduler() {
    callbacks.push_back(new InputOperation());
    callbacks.push_back(new RenderOperation());
    callbacks.push_back(new WidgetOperation());
}

int Scheduler::process() {
    auto* operation = new std::thread(Scheduler::handleExecRaw);

    operation->detach();

    std::mutex mutex;
    std::condition_variable condition;
    
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, []() mutable { return (bool)Scheduler::blockExit; });

    return EXIT_SUCCESS;
}

void Scheduler::handleExecRaw() {
    for(auto callback : Scheduler::callbacks) {
        if (callback->handleExec() != EXIT_SUCCESS) {
            Signal::emitExit();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(SCHEDULER_BASIC_AWAIT));
    }
}

int Scheduler::handleExit() {
    for(auto callback : Scheduler::callbacks) {
        if (callback->handleExit() != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        };
    }

    Scheduler::blockExit = true;

    return EXIT_SUCCESS;
}