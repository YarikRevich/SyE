#include "scheduler.hpp"

std::vector<Scheduler::Operation*> Scheduler::callbacks;

std::atomic<bool> Scheduler::blockExit = false;

void Scheduler::init() {
    Signal::addHandler(Scheduler::handleExit);
}

void Scheduler::addHandler(Scheduler::Operation * callback) {
    callbacks.push_back(callback);
}

void Scheduler::handleExec() {
    for(auto callback : Scheduler::callbacks) {
        auto* operation = new std::thread(&Scheduler::Operation::handleExec, callback);

        operation->detach();
    }

    std::mutex mutex;
    std::condition_variable condition;
    
    std::unique_lock<std::mutex> lock(mutex);
    condition.wait(lock, []() mutable { return (bool)Scheduler::blockExit; });
}

void Scheduler::handleExit() {
    for(auto callback : Scheduler::callbacks) {
        callback->handleExit();
    }

    Scheduler::blockExit = true;
}