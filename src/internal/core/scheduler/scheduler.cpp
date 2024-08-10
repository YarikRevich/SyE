#include "scheduler.hpp"

std::vector<Scheduler::Operation*> Scheduler::callbacks;

std::atomic<bool> Scheduler::blockExit = false;

void Scheduler::init() {
    Signal::addHandler(Scheduler::handleExit);
}

void Scheduler::addHandler(Scheduler::Operation * callback) {
    callbacks.push_back(callback);
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
        callback->handleExec();

        std::this_thread::sleep_for(std::chrono::milliseconds(SCHEDULER_BASIC_AWAIT));
    }
}

void Scheduler::handleExit() {
    for(auto callback : Scheduler::callbacks) {
        callback->handleExit();
    }

    Scheduler::blockExit = true;
}